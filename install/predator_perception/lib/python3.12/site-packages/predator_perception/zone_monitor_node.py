import rclpy
from rclpy.node import Node

import numpy as np

from geometry_msgs.msg import PoseStamped, Point
from std_msgs.msg import Float32
from predator_msgs.msg import ZoneStatus


class ZoneMonitor(Node):

    def __init__(self):
        super().__init__("zone_monitor_node")
        self.declare_parameter("ur3_zone_center_x",  0.0)
        self.declare_parameter("ur3_zone_center_y",  1.29)
        self.declare_parameter("ur3_zone_radius",    1.20)
        self.declare_parameter("safety_zone_radius", 0.9)
        self.declare_parameter("publish_rate_hz",    10.0)

        cx  = self.get_parameter("ur3_zone_center_x").value
        cy  = self.get_parameter("ur3_zone_center_y").value
        self._ur3_zone_center   = np.array([cx, cy])
        self._ur3_zone_radius   = self.get_parameter("ur3_zone_radius").value
        self._safety_radius     = self.get_parameter("safety_zone_radius").value
        rate                    = self.get_parameter("publish_rate_hz").value

        self._latest_pose: np.ndarray | None = None
        self._confidence  = 0.0

        self._pub = self.create_publisher(ZoneStatus, "/zone_status", 10)

        self.create_subscription(PoseStamped, "/target_pose_map",       self.callback_pose,       10)
        self.create_subscription(Float32,     "/target_confidence", self.callback_confidence, 10)

        self.create_timer(1.0 / rate, self._timer_cb)

        self.get_logger().info(
            f"ZoneMonitor ready — UR3 zone center=({cx},{cy}), "
            f"r={self._ur3_zone_radius}m, safety_r={self._safety_radius}m"
        )

    def callback_confidence(self, msg: Float32):
        self._confidence = msg.data

    def callback_pose(self, msg: PoseStamped):
        p = msg.pose.position
        self._latest_pose = np.array([p.x, p.y, p.z])

    def _timer_cb(self):
        msg = ZoneStatus()
        msg.header.stamp    = self.get_clock().now().to_msg()
        msg.header.frame_id = "map"
        msg.zone_radius     = float(self._ur3_zone_radius)

        center_pt       = Point()
        center_pt.x     = float(self._ur3_zone_center[0])
        center_pt.y     = float(self._ur3_zone_center[1])
        center_pt.z     = 0.0
        msg.zone_center = center_pt

        if self._latest_pose is None or self._confidence < 0.1:
            msg.target_in_ur3_zone    = False
            msg.target_in_safety_zone = False
            msg.distance_to_zone_center = -1.0
        else:
            target_2d = self._latest_pose[:2]
            dist_to_ur3   = float(np.linalg.norm(target_2d - self._ur3_zone_center))

            msg.distance_to_zone_center  = dist_to_ur3
            msg.target_in_ur3_zone       = dist_to_ur3   <= self._ur3_zone_radius
            msg.target_in_safety_zone    = dist_to_ur3 <= self._safety_radius

        self._pub.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    node = ZoneMonitor()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
