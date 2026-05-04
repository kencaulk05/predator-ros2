#!/usr/bin/env python3
"""
pursuit_planner_node.py
=======================
Converts behavior states into Nav2 NavigateToPose action goals.

Subscriptions:
  /behavior_state          (predator_msgs/BehaviorState)
  /target_pose_map          (geometry_msgs/PoseStamped)
  /predicted_target_pose_map (geometry_msgs/PoseStamped)
  /zone_status             (predator_msgs/ZoneStatus)

Action client:
  /navigate_to_pose        (nav2_msgs/NavigateToPose)

Map frame (rotated map, origin = bottom-left of free space):
  Origin (0,0)   = bottom-left corner of arena floor
  UR3 arm        = (0.0, 1.29)
  Standby        = (1.40, 0.90)  center of bottom corridor
  Map bounds     = x: 0.0-6.10,  y: 0.0-3.46
  Corridor step  = x=2.80 (corridor narrows above this)
"""

import math
import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient

from geometry_msgs.msg import PoseStamped, Quaternion
from nav2_msgs.action import NavigateToPose
from predator_msgs.msg import BehaviorState, ZoneStatus
from action_msgs.msg import GoalStatus


def yaw_to_quaternion(yaw: float) -> Quaternion:
    """Convert a yaw angle (radians) to a geometry_msgs/Quaternion."""
    q = Quaternion()
    q.w = math.cos(yaw / 2.0)
    q.x = 0.0
    q.y = 0.0
    q.z = math.sin(yaw / 2.0)
    return q


def distance_2d(p1: PoseStamped, p2: PoseStamped) -> float:
    """Euclidean distance between two PoseStamped positions (x/y only)."""
    dx = p1.pose.position.x - p2.pose.position.x
    dy = p1.pose.position.y - p2.pose.position.y
    return math.hypot(dx, dy)


class PursuitPlannerNode(Node):
    """
    Translates behavior FSM states into Nav2 navigation goals.

    PURSUIT  → Drive to intercept point behind the target
    HERD     → Position between target and UR3 arm to herd
    others   → Return to standby position
    """

    # ── Tunable parameters ──────────────────────────────────────────────────
    GOAL_RECOMPUTE_THRESHOLD = 0.30  # m — resubmit goal if target moves this far
    INTERCEPT_OFFSET         = 1.00  # m — how far behind target to aim (pursuit)
    HERD_OFFSET              = 0.80  # m — how far behind target (away from arm)

    # ── Map frame coordinates (origin = bottom-left of free space) ──────────
    UR3_X            = 0.00   # m — UR3 arm x in map frame
    UR3_Y            = 1.29   # m — UR3 arm y in map frame

    ROBOT_STANDBY_X  = 1.59   # m — standby x (center of bottom corridor)
    ROBOT_STANDBY_Y  = 1.80   # m — standby y (center of bottom corridor)

    # Map bounds for clamping goals
    MAP_X_MIN = 0.30
    MAP_X_MAX = 2.50
    MAP_Y_MIN = 0.40
    MAP_Y_MAX = 1.80

    def __init__(self):
        super().__init__('pursuit_planner_node')

        # ── State ────────────────────────────────────────────────────────────
        self._current_behavior = BehaviorState.SEARCH
        self._target_pose      = None
        self._predicted_pose   = None
        self._last_goal_pose   = None
        self._goal_handle      = None
        self._nav_active       = False

        # ── Nav2 action client ───────────────────────────────────────────────
        self._nav_client = ActionClient(self, NavigateToPose, 'navigate_to_pose')
        self.get_logger().info('Waiting for navigate_to_pose action server...')
        self._nav_client.wait_for_server()
        self.get_logger().info('navigate_to_pose action server connected.')

        # ── Subscribers ──────────────────────────────────────────────────────
        self.create_subscription(
            BehaviorState, '/behavior_state', self._behavior_cb, 10)
        self.create_subscription(
            PoseStamped, '/target_pose_map', self._target_cb, 10)
        self.create_subscription(
            PoseStamped, '/predicted_target_pose_map', self._predicted_cb, 10)
        self.create_subscription(
            ZoneStatus, '/zone_status', self._zone_cb, 10)

        # ── Planning timer at 2 Hz ───────────────────────────────────────────
        self.create_timer(0.5, self._planning_tick)

        self.get_logger().info(
            f'PursuitPlannerNode ready. '
            f'UR3=({self.UR3_X},{self.UR3_Y}), '
            f'Standby=({self.ROBOT_STANDBY_X},{self.ROBOT_STANDBY_Y})')

    # ── Subscriber callbacks ─────────────────────────────────────────────────

    def _behavior_cb(self, msg: BehaviorState):
        prev = self._current_behavior
        self._current_behavior = msg.state
        if prev != msg.state:
            self.get_logger().info(
                f'Behavior → {msg.state_label} '
                f'(reason: {msg.transition_reason})')
            self._cancel_current_goal()
            self._planning_tick()

    def _target_cb(self, msg: PoseStamped):
        self._target_pose = msg

    def _predicted_cb(self, msg: PoseStamped):
        self._predicted_pose = msg

    def _zone_cb(self, msg: ZoneStatus):
        pass

    # ── Planning tick ─────────────────────────────────────────────────────────

    def _planning_tick(self):
        state = self._current_behavior

        if state == BehaviorState.PURSUIT:
            self._handle_pursuit()

        elif state == BehaviorState.HERD:
            self._handle_herd()

        elif state == BehaviorState.ARM_ALERT:
            # Hold position — cancel any active goal
            if self._nav_active:
                self._cancel_current_goal()

        elif state in (BehaviorState.SEARCH,
                       BehaviorState.ACQUIRE,
                       BehaviorState.REACQUIRE,
                       BehaviorState.SAFETY_STOP):
            if self._nav_active:
                self._cancel_current_goal()
                self._send_standby_goal()

    # ── Pursuit mode ──────────────────────────────────────────────────────────

    def _handle_pursuit(self):
        """
        Intercept point: INTERCEPT_OFFSET metres behind the target
        along the current→predicted trajectory vector.
        """
        target = self._predicted_pose or self._target_pose
        if target is None:
            return

        if self._predicted_pose and self._target_pose:
            dx = (self._predicted_pose.pose.position.x
                  - self._target_pose.pose.position.x)
            dy = (self._predicted_pose.pose.position.y
                  - self._target_pose.pose.position.y)
            dist = math.hypot(dx, dy)
            if dist > 0.01:
                heading = math.atan2(dy, dx)
            else:
                heading = 0.0
        else:
            heading = 0.0

        goal_x = (target.pose.position.x
                  - self.INTERCEPT_OFFSET * math.cos(heading))
        goal_y = (target.pose.position.y
                  - self.INTERCEPT_OFFSET * math.sin(heading))

        goal_x = max(self.MAP_X_MIN, min(self.MAP_X_MAX, goal_x))
        goal_y = max(self.MAP_Y_MIN, min(self.MAP_Y_MAX, goal_y))

        goal_yaw = heading
        goal_pose = self._make_pose(goal_x, goal_y, goal_yaw)

        if self._should_replan(goal_pose):
            self.get_logger().info(
                f'PURSUIT → intercept ({goal_x:.2f}, {goal_y:.2f})')
            self._send_nav_goal(goal_pose)

    # ── Herd mode ─────────────────────────────────────────────────────────────

    def _handle_herd(self):
        """
        Place robot HERD_OFFSET metres beyond the target away from the UR3 arm,
        facing toward the arm to physically nudge the person forward.
        """
        target = self._target_pose
        if target is None:
            return

        tx = target.pose.position.x
        ty = target.pose.position.y

        # Vector from UR3 → target
        dx = tx - self.UR3_X
        dy = ty - self.UR3_Y
        dist = math.hypot(dx, dy)
        if dist < 0.01:
            return

        # Unit vector away from UR3
        ux, uy = dx / dist, dy / dist

        goal_x = tx + self.HERD_OFFSET * ux
        goal_y = ty + self.HERD_OFFSET * uy

        goal_x = max(self.MAP_X_MIN, min(self.MAP_X_MAX, goal_x))
        goal_y = max(self.MAP_Y_MIN, min(self.MAP_Y_MAX, goal_y))

        # Face toward UR3 arm
        goal_yaw = math.atan2(self.UR3_Y - goal_y, self.UR3_X - goal_x)

        goal_pose = self._make_pose(goal_x, goal_y, goal_yaw)

        if self._should_replan(goal_pose):
            self.get_logger().info(
                f'HERD → ({goal_x:.2f}, {goal_y:.2f}), '
                f'facing UR3 ({self.UR3_X}, {self.UR3_Y})')
            self._send_nav_goal(goal_pose)

    # ── Standby ───────────────────────────────────────────────────────────────

    def _send_standby_goal(self):
        goal_pose = self._make_pose(
            self.ROBOT_STANDBY_X, self.ROBOT_STANDBY_Y, 3.1416)
        self.get_logger().info(
            f'Returning to standby '
            f'({self.ROBOT_STANDBY_X}, {self.ROBOT_STANDBY_Y})')
        self._send_nav_goal(goal_pose)

    # ── Nav2 helpers ──────────────────────────────────────────────────────────

    def _should_replan(self, new_goal: PoseStamped) -> bool:
        if not self._nav_active:
            return True
        if self._last_goal_pose is None:
            return True
        return (distance_2d(new_goal, self._last_goal_pose)
                > self.GOAL_RECOMPUTE_THRESHOLD)

    def _make_pose(self, x: float, y: float, yaw: float) -> PoseStamped:
        pose = PoseStamped()
        pose.header.stamp = self.get_clock().now().to_msg()
        pose.header.frame_id = 'map'
        pose.pose.position.x = x
        pose.pose.position.y = y
        pose.pose.position.z = 0.0
        pose.pose.orientation = yaw_to_quaternion(yaw)
        return pose

    def _send_nav_goal(self, pose: PoseStamped):
        goal_msg = NavigateToPose.Goal()
        goal_msg.pose = pose
        self._last_goal_pose = pose
        self._nav_active = True
        future = self._nav_client.send_goal_async(
            goal_msg, feedback_callback=self._nav_feedback_cb)
        future.add_done_callback(self._nav_goal_response_cb)

    def _cancel_current_goal(self):
        if self._goal_handle is not None:
            self._goal_handle.cancel_goal_async()
            self._goal_handle = None
        self._nav_active = False
        self._last_goal_pose = None

    def _nav_goal_response_cb(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().warn('Nav2 rejected goal.')
            self._nav_active = False
            return
        self._goal_handle = goal_handle
        result_future = goal_handle.get_result_async()
        result_future.add_done_callback(self._nav_result_cb)

    def _nav_result_cb(self, future):
        result = future.result()
        status = result.status
        if status == GoalStatus.STATUS_SUCCEEDED:
            self.get_logger().info('Nav2 goal reached.')
        elif status == GoalStatus.STATUS_CANCELED:
            self.get_logger().info('Nav2 goal cancelled.')
        else:
            self.get_logger().warn(f'Nav2 goal failed: status={status}')
        self._nav_active = False
        self._goal_handle = None

    def _nav_feedback_cb(self, feedback_msg):
        pass


def main(args=None):
    rclpy.init(args=args)
    node = PursuitPlannerNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
