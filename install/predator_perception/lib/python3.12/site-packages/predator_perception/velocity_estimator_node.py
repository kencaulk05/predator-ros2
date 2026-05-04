from collections import deque

import rclpy
from rclpy.node import Node
from rclpy.time import Time

import numpy as np

from geometry_msgs.msg import PoseStamped, TwistStamped
from std_msgs.msg import Float32


class VelocityEstimator(Node):

    def __init__(self):
        super().__init__("velocity_estimator_node")
        self.declare_parameter("buffer_size",        10)
        self.declare_parameter("prediction_horizon", 0.5)
        self.declare_parameter("min_confidence",     0.3)
        self.declare_parameter("min_dt",             0.01)

        self._buffer_size  = self.get_parameter("buffer_size").value
        self._horizon      = self.get_parameter("prediction_horizon").value
        self._min_conf     = self.get_parameter("min_confidence").value
        self._min_dt       = self.get_parameter("min_dt").value

        #stamp_sec: float, position: np.ndarray shape (3,))
        self._pose_buffer: deque = deque(maxlen=self._buffer_size)
        self._current_confidence = 0.0

        self._pub_velocity  = self.create_publisher(TwistStamped, "/target_velocity",       10)
        self._pub_predicted = self.create_publisher(PoseStamped,  "/predicted_target_pose", 10)

        self.create_subscription(PoseStamped, "/target_pose",       self.callback_pose,       10)
        self.create_subscription(Float32,     "/target_confidence", self.callback_confidence, 10)

        self.get_logger().info(
            f"VelocityEstimator ready — horizon={self._horizon}s, buffer={self._buffer_size}"
        )


    def callback_confidence(self, msg: Float32):
        self._current_confidence = msg.data

    def callback_pose(self, msg: PoseStamped):
        if self._current_confidence < self._min_conf:
            return

        stamp_sec = Time.from_msg(msg.header.stamp).nanoseconds * 1e-9
        position  = self._extract_position(msg)

        self._update_buffer(stamp_sec, position)

        velocity = self._compute_velocity()
        if velocity is None:
            return

        predicted = self._predict_future_pose(position, velocity)

        self._publish_velocity(msg.header, velocity)
        self._publish_predicted(msg.header, predicted)

    def _update_buffer(self, stamp_sec: float, position: np.ndarray):
        if self._pose_buffer:
            last_stamp, _ = self._pose_buffer[-1]
            if (stamp_sec - last_stamp) < self._min_dt:
                return
        self._pose_buffer.append((stamp_sec, position))

    def _compute_velocity(self) -> np.ndarray | None:
        """
        Finite-difference velocity estimate over the full buffer window.
        Uses oldest and newest entries for a stable estimate.
        Returns velocity vector [vx, vy, vz] in m/s, or None if insufficient data.
        """
        if len(self._pose_buffer) < 2:
            return None

        t0, p0 = self._pose_buffer[0]
        t1, p1 = self._pose_buffer[-1]
        dt = t1 - t0

        if dt < self._min_dt:
            return None

        return (p1 - p0) / dt

    def _predict_future_pose(self, current_pos: np.ndarray, velocity: np.ndarray) -> np.ndarray:
        """Linear motion prediction: p_future = p_current + v * horizon."""
        return current_pos + velocity * self._horizon


    @staticmethod
    def _extract_position(msg: PoseStamped) -> np.ndarray:
        p = msg.pose.position
        return np.array([p.x, p.y, p.z])

    def _publish_velocity(self, header, velocity: np.ndarray):
        msg = TwistStamped()
        msg.header            = header
        msg.twist.linear.x    = float(velocity[0])
        msg.twist.linear.y    = float(velocity[1])
        msg.twist.linear.z    = float(velocity[2])
        self._pub_velocity.publish(msg)

    def _publish_predicted(self, header, predicted_pos: np.ndarray):
        msg = PoseStamped()
        msg.header              = header
        msg.pose.position.x     = float(predicted_pos[0])
        msg.pose.position.y     = float(predicted_pos[1])
        msg.pose.position.z     = float(predicted_pos[2])
        msg.pose.orientation.w  = 1.0
        self._pub_predicted.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    node = VelocityEstimator()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
