import rclpy
from rclpy.node import Node
from rclpy.time import Time

import numpy as np

from geometry_msgs.msg import PoseStamped
from std_msgs.msg import Float32, Bool


class SafetySupervisor(Node):

    def __init__(self):
        super().__init__("safety_supervisor_node")
        self.declare_parameter("min_distance_m",     0.5)
        self.declare_parameter("tracking_timeout_s", 2.0)
        self.declare_parameter("min_confidence",     0.2)
        self.declare_parameter("publish_rate_hz",    20.0)

        self._min_dist    = self.get_parameter("min_distance_m").value
        self._timeout     = self.get_parameter("tracking_timeout_s").value
        self._min_conf    = self.get_parameter("min_confidence").value
        rate              = self.get_parameter("publish_rate_hz").value

        self._last_pose_time: float | None = None   # seconds since epoch
        self._target_distance: float       = float("inf")
        self._confidence: float            = 0.0

        self._pub = self.create_publisher(Bool, "/safety_status", 10)

        self.create_subscription(PoseStamped, "/target_pose",       self.callback_pose,       10)
        self.create_subscription(Float32,     "/target_confidence", self.callback_confidence, 10)

        self.create_timer(1.0 / rate, self._monitor_cb)

        self.get_logger().info(
            f"SafetySupervisor ready — min_dist={self._min_dist}m, "
            f"timeout={self._timeout}s"
        )


    def callback_confidence(self, msg: Float32):
        self._confidence = msg.data

    def callback_pose(self, msg: PoseStamped):
        self._last_pose_time = Time.from_msg(msg.header.stamp).nanoseconds * 1e-9

        p = msg.pose.position
        self._target_distance = float(np.linalg.norm([p.x, p.y, p.z]))

    def _monitor_cb(self):
        unsafe, reason = self._check_safety()

        if unsafe:
            self.get_logger().warn(f"[SAFETY] UNSAFE — {reason}", throttle_duration_sec=1.0)
        
        out      = Bool()
        out.data = unsafe
        self._pub.publish(out)


    def _check_safety(self) -> tuple[bool, str]:
        """Returns (is_unsafe, reason). Both checks are independent."""

        # 1. Tracking timeout
        if self._last_pose_time is not None:
            now_sec = self.get_clock().now().nanoseconds * 1e-9
            gap     = now_sec - self._last_pose_time
            if gap > self._timeout:
                return True, f"tracking timeout ({gap:.1f}s > {self._timeout}s)"

        # 2. Distance violation (only when confident we know where target is)
        if self._confidence >= self._min_conf:
            if self._target_distance < self._min_dist:
                return True, (
                    f"distance violation "
                    f"({self._target_distance:.2f}m < {self._min_dist}m)"
                )

        return False, "ok"


def main(args=None):
    rclpy.init(args=args)
    node = SafetySupervisor()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
