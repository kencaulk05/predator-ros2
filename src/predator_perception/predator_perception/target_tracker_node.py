import rclpy
from rclpy.node import Node

import cv2
import cv2.aruco as aruco
import numpy as np

from sensor_msgs.msg import Image, CameraInfo
from geometry_msgs.msg import PoseStamped
from std_msgs.msg import Float32
from cv_bridge import CvBridge


# Aruco dictionary lookup
ARUCO_DICTS = {
    "DICT_4X4_50":         aruco.DICT_4X4_50,
    "DICT_4X4_100":        aruco.DICT_4X4_100,
    "DICT_5X5_50":         aruco.DICT_5X5_50,
    "DICT_6X6_50":         aruco.DICT_6X6_50,
    "DICT_ARUCO_ORIGINAL": aruco.DICT_ARUCO_ORIGINAL,
}


class PoseFilter:
    """First-order low-pass filter over a 3-element position vector."""

    def __init__(self, alpha: float = 0.3):
        self.alpha = alpha
        self._value = None

    def update(self, new_value: np.ndarray) -> np.ndarray:
        if self._value is None:
            self._value = new_value.copy()
        else:
            self._value = self.alpha * new_value + (1.0 - self.alpha) * self._value
        return self._value.copy()

    def reset(self):
        self._value = None


class TargetTracker(Node):

    def __init__(self):
        super().__init__("target_tracker_node")

        # Parameters
        self.declare_parameter("marker_id",      0)     # front marker ID
        self.declare_parameter("marker_id_back", 1)     # back marker ID
        self.declare_parameter("marker_size_m",  0.15)
        self.declare_parameter("filter_alpha",   0.3)
        self.declare_parameter("aruco_dict",     "DICT_4X4_50")

        self._marker_id_front = self.get_parameter("marker_id").value
        self._marker_id_back  = self.get_parameter("marker_id_back").value
        self._marker_size     = self.get_parameter("marker_size_m").value
        alpha                 = self.get_parameter("filter_alpha").value
        dict_name             = self.get_parameter("aruco_dict").value

        # ArUco setup
        dict_id = ARUCO_DICTS.get(dict_name, aruco.DICT_4X4_50)
        self._aruco_dict   = aruco.getPredefinedDictionary(dict_id)
        self._aruco_params = aruco.DetectorParameters_create()
        self._detector     = None  # not used with OpenCV < 4.7

        # State
        self._camera_matrix = None
        self._dist_coeffs   = None
        self._bridge        = CvBridge()
        self._filter        = PoseFilter(alpha)

        # Confidence decay: how many frames without detection before → 0
        self._frames_since_detection  = 0
        self._confidence_decay_frames = 10

        # Publishers
        self._pub_pose       = self.create_publisher(PoseStamped, "/target_pose",       10)
        self._pub_confidence = self.create_publisher(Float32,     "/target_confidence", 10)

        # Subscribers
        self.create_subscription(CameraInfo, "/camera_info", self.callback_camera_info, 10)
        self.create_subscription(Image,      "/image_raw",   self.callback_image,       10)

        self.get_logger().info(
            f"TargetTracker ready — front marker ID {self._marker_id_front}, "
            f"back marker ID {self._marker_id_back} "
            f"({dict_name}, size={self._marker_size} m)"
        )

    # ── Callbacks ──────────────────────────────────────────────────────────

    def callback_camera_info(self, msg: CameraInfo):
        if self._camera_matrix is not None:
            return
        self._camera_matrix = np.array(msg.k).reshape(3, 3)
        self._dist_coeffs   = np.array(msg.d)
        self.get_logger().info("Camera intrinsics received.")

    def callback_image(self, msg: Image):
        if self._camera_matrix is None:
            self.get_logger().warn("No camera_info yet — skipping frame.", throttle_duration_sec=5.0)
            return

        frame = self._bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")

        # Try to detect both markers, pick the one with lower reprojection error
        detected, tvec = self._detect_best_marker(frame)

        if detected:
            self._frames_since_detection = 0
            filtered_tvec = self._filter.update(tvec)
            confidence    = 1.0
            pose_msg      = self._build_pose_msg(msg.header, filtered_tvec)
            self._pub_pose.publish(pose_msg)
        else:
            self._frames_since_detection += 1
            decay      = self._frames_since_detection / self._confidence_decay_frames
            confidence = max(0.0, 1.0 - decay)
            if confidence == 0.0:
                self._filter.reset()

        conf_msg      = Float32()
        conf_msg.data = float(confidence)
        self._pub_confidence.publish(conf_msg)

    # ── Detection logic ────────────────────────────────────────────────────

    def _detect_best_marker(self, frame: np.ndarray) -> tuple[bool, np.ndarray | None]:
        """
        Detect both front and back ArUco markers in the frame.
        If both are visible, pick the one with the lower reprojection error
        (closer to camera / better pose estimate).
        Returns (True, tvec) for the best detection, or (False, None) if neither found.
        """
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        corners, ids, _ = aruco.detectMarkers(gray, self._aruco_dict, parameters=self._aruco_params)

        if ids is None:
            return False, None

        ids_flat    = ids.flatten()
        candidates  = {}  # marker_id → (tvec, reprojection_error)

        for i, marker_id in enumerate(ids_flat):
            if marker_id not in (self._marker_id_front, self._marker_id_back):
                continue

            obj_points = self._marker_object_points()
            img_points = corners[i][0].astype(np.float32)

            ret, rvec, tvec = cv2.solvePnP(
                obj_points, img_points,
                self._camera_matrix, self._dist_coeffs,
                flags=cv2.SOLVEPNP_IPPE_SQUARE,
            )

            if not ret:
                continue

            # Compute reprojection error to rank detections
            projected, _ = cv2.projectPoints(
                obj_points, rvec, tvec,
                self._camera_matrix, self._dist_coeffs
            )
            error = float(np.mean(np.linalg.norm(
                img_points - projected.reshape(-1, 2), axis=1
            )))

            candidates[marker_id] = (tvec.flatten(), error)

        if not candidates:
            return False, None

        if len(candidates) == 1:
            tvec, _ = next(iter(candidates.values()))
            return True, tvec

        # Both markers visible — pick the one with lower reprojection error
        best_id = min(candidates, key=lambda k: candidates[k][1])
        best_tvec, best_err = candidates[best_id]
        other_id  = [k for k in candidates if k != best_id][0]
        other_err = candidates[other_id][1]

        self.get_logger().debug(
            f"Both markers visible — using ID {best_id} "
            f"(err={best_err:.2f}px vs ID {other_id} err={other_err:.2f}px)"
        )

        return True, best_tvec

    def _marker_object_points(self) -> np.ndarray:
        """Return 3D corners of the marker in marker-local coordinates."""
        half = self._marker_size / 2.0
        return np.array([
            [-half,  half, 0],
            [ half,  half, 0],
            [ half, -half, 0],
            [-half, -half, 0],
        ], dtype=np.float32)

    # ── Message builders ───────────────────────────────────────────────────

    def _build_pose_msg(self, header, tvec: np.ndarray) -> PoseStamped:
        msg = PoseStamped()
        msg.header          = header
        msg.pose.position.x = float(tvec[0])
        msg.pose.position.y = float(tvec[1])
        msg.pose.position.z = float(tvec[2])
        # Orientation left as identity — extend with rvec → quaternion if needed
        msg.pose.orientation.w = 1.0
        return msg


def main(args=None):
    rclpy.init(args=args)
    node = TargetTracker()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
