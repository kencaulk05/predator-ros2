#!/usr/bin/env python3
"""
camera_to_map_transform_node.py
================================
Transforms /target_pose from camera frame to map frame.

The wall-mounted USB camera publishes target positions in its own
coordinate frame (z = depth/forward, x = right, y = down).
This node applies a rigid transform to convert those positions
into the map frame used by Nav2, zone_monitor, and pursuit_planner.

Camera mounting (fill in measured values tomorrow):
  - Position in map frame: (camera_x, camera_y, camera_z)
  - Tilt downward: camera_tilt_deg  (positive = tilted down)
  - Pan (yaw): camera_yaw_deg       (0 = facing +X in map frame)

Subscriptions:
  /target_pose          (geometry_msgs/PoseStamped) — camera frame

Publications:
  /target_pose_map      (geometry_msgs/PoseStamped) — map frame
  /predicted_target_pose_map (geometry_msgs/PoseStamped) — map frame

Usage:
  Once you measure the camera mounting at the lab, update the
  default parameter values below and rebuild.
"""

import math
import numpy as np
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped, Point


def rot_x(angle_rad: float) -> np.ndarray:
    """Rotation matrix around X axis."""
    c, s = math.cos(angle_rad), math.sin(angle_rad)
    return np.array([[1, 0,  0],
                     [0, c, -s],
                     [0, s,  c]])


def rot_y(angle_rad: float) -> np.ndarray:
    """Rotation matrix around Y axis."""
    c, s = math.cos(angle_rad), math.sin(angle_rad)
    return np.array([[ c, 0, s],
                     [ 0, 1, 0],
                     [-s, 0, c]])


def rot_z(angle_rad: float) -> np.ndarray:
    """Rotation matrix around Z axis."""
    c, s = math.cos(angle_rad), math.sin(angle_rad)
    return np.array([[c, -s, 0],
                     [s,  c, 0],
                     [0,  0, 1]])


class CameraToMapTransformNode(Node):
    """
    Converts target poses from camera frame to map frame using
    a configurable rigid body transform.

    Camera frame convention (standard OpenCV/ROS camera):
      +Z = forward (depth, away from camera)
      +X = right
      +Y = down

    Map frame convention:
      +X = right (East)
      +Y = forward (North)
      +Z = up
    """

    def __init__(self):
        super().__init__('camera_to_map_transform_node')

        # ── Parameters (fill in measured values at the lab) ──────────────────
        # Camera position in map frame (meters)
        # MEASURE: distance along map X and Y from origin corner
        self.declare_parameter('camera_x',        0.0)   # m from origin along +X
        self.declare_parameter('camera_y',        1.00)   # m from origin along +Y
        self.declare_parameter('camera_z',        2.00)   # m height above floor

        # Camera orientation
        # MEASURE: angle camera is tilted downward (degrees, positive = down)
        self.declare_parameter('camera_tilt_deg', 30.0)   # degrees downward tilt

        # MEASURE: angle camera faces in map frame (degrees)
        # 0   = facing +X (right across arena)
        # 90  = facing +Y (toward open space / UR3 arm)
        # 45  = diagonal
        self.declare_parameter('camera_yaw_deg',  12.0)   # degrees, 0=+X in map

        # Floor height in map frame (usually 0.0)
        self.declare_parameter('floor_z',         0.0)

        # Whether to publish a debug log of each transformed point
        self.declare_parameter('debug_transform',  False)

        # ── Read parameters ───────────────────────────────────────────────────
        self._cam_pos = np.array([
            self.get_parameter('camera_x').value,
            self.get_parameter('camera_y').value,
            self.get_parameter('camera_z').value,
        ])
        tilt_rad = math.radians(self.get_parameter('camera_tilt_deg').value)
        yaw_rad  = math.radians(self.get_parameter('camera_yaw_deg').value)
        self._floor_z = self.get_parameter('floor_z').value
        self._debug   = self.get_parameter('debug_transform').value

        # ── Build camera→map rotation matrix ─────────────────────────────────
        # Step 1: Camera frame to world-up frame
        #   Camera +Z (forward) → map +X direction (before yaw)
        #   Camera +Y (down)    → map -Z (up in world = -Y_cam)
        #   Camera +X (right)   → map +Y direction (before yaw)
        #
        # Base rotation: align camera axes with world axes
        # R_base rotates from camera frame to a forward-facing world frame
        R_base = np.array([
            [0,  0,  1],   # map X = camera Z (forward)
            [1,  0,  0],   # map Y = camera X (right)
            [0, -1,  0],   # map Z = -camera Y (up = -down)
        ])

        # Step 2: Apply tilt (camera pitched down around its X axis)
        R_tilt = rot_x(-tilt_rad)  # negative because tilting down = -pitch

        # Step 3: Apply yaw (camera panned in map frame)
        R_yaw = rot_z(yaw_rad)

        # Combined: first align axes, then tilt, then pan
        self._R = R_yaw @ R_base @ R_tilt

        # ── Publishers ────────────────────────────────────────────────────────
        self._pub_target = self.create_publisher(
            PoseStamped, '/target_pose_map', 10)
        self._pub_predicted = self.create_publisher(
            PoseStamped, '/predicted_target_pose_map', 10)

        # ── Subscribers ───────────────────────────────────────────────────────
        self.create_subscription(
            PoseStamped, '/target_pose',
            self._target_cb, 10)
        self.create_subscription(
            PoseStamped, '/predicted_target_pose',
            self._predicted_cb, 10)

        self.get_logger().info(
            f'CameraToMapTransformNode ready.\n'
            f'  Camera position in map: '
            f'({self._cam_pos[0]:.2f}, {self._cam_pos[1]:.2f}, '
            f'{self._cam_pos[2]:.2f})m\n'
            f'  Tilt: {self.get_parameter("camera_tilt_deg").value}° down, '
            f'  Yaw: {self.get_parameter("camera_yaw_deg").value}° in map frame\n'
            f'  *** Update camera_x, camera_y, camera_z, camera_tilt_deg, '
            f'camera_yaw_deg after measuring at the lab ***')

    # ── Callbacks ─────────────────────────────────────────────────────────────

    def _target_cb(self, msg: PoseStamped):
        transformed = self._transform(msg)
        if transformed is not None:
            self._pub_target.publish(transformed)

    def _predicted_cb(self, msg: PoseStamped):
        transformed = self._transform(msg)
        if transformed is not None:
            # Republish on the map-frame predicted topic
            transformed.header.frame_id = 'map'
            self._pub_predicted.publish(transformed)

    # ── Transform ─────────────────────────────────────────────────────────────

    def _transform(self, msg: PoseStamped) -> PoseStamped:
        """
        Transform a PoseStamped from camera frame to map frame.

        Camera frame (OpenCV convention):
          p_cam = [x_cam, y_cam, z_cam]
          z_cam = depth (distance from camera along optical axis)
          x_cam = horizontal offset (right = positive)
          y_cam = vertical offset (down = positive)

        Map frame result:
          p_map = R @ p_cam + camera_position
        """
        # Extract camera-frame position
        p_cam = np.array([
            msg.pose.position.x,
            msg.pose.position.y,
            msg.pose.position.z,
        ])

        # Sanity check — depth must be positive
        if p_cam[2] <= 0.0:
            self.get_logger().warn(
                f'Invalid camera depth {p_cam[2]:.3f} — skipping transform')
            return None

        # Apply rotation and translation
        p_map = self._R @ p_cam + self._cam_pos

        # Clamp Z to floor (person is on the floor)
        # Small negative values due to noise should be clamped to 0
        p_map[2] = max(self._floor_z, p_map[2])

        if self._debug:
            self.get_logger().info(
                f'Transform: cam({p_cam[0]:.2f},{p_cam[1]:.2f},{p_cam[2]:.2f})'
                f' → map({p_map[0]:.2f},{p_map[1]:.2f},{p_map[2]:.2f})')

        # Build output PoseStamped
        out = PoseStamped()
        out.header.stamp    = msg.header.stamp
        out.header.frame_id = 'map'
        out.pose.position.x = float(p_map[0])
        out.pose.position.y = float(p_map[1])
        out.pose.position.z = float(p_map[2])
        # Keep orientation from input (or set to identity)
        out.pose.orientation = msg.pose.orientation

        return out


def main(args=None):
    rclpy.init(args=args)
    node = CameraToMapTransformNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
