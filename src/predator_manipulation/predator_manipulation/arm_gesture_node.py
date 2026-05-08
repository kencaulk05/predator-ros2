"""
arm_gesture_node.py

Executes predator gestures on the UR3e using the MoveGroup action client.
Uses the RobotMover pattern from the Tufts EECS UR3e lab guide.

Subscriptions:
  /gesture_request          (predator_msgs/GestureRequest)
  /predicted_target_pose_map    (geometry_msgs/PoseStamped)

Publications:
  /gesture_status           (std_msgs/String)

Parameters:
  velocity_scale            (float, default=0.6)
  acceleration_scale        (float, default=0.5)

IMPORTANT: Requires CycloneDDS to be active:
  export RMW_IMPLEMENTATION=rmw_cyclonedds_cpp
"""

import math

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient

from geometry_msgs.msg import PoseStamped
from std_msgs.msg import String
from predator_msgs.msg import GestureRequest

from moveit_msgs.action import MoveGroup
from moveit_msgs.msg import (
    MotionPlanRequest,
    JointConstraint,
    Constraints,
    MoveItErrorCodes,
)
from geometry_msgs.msg import Vector3


# ── Joint names for the UR3e ───────────────────────────────────────────────
JOINT_NAMES = [
    "shoulder_pan_joint",
    "shoulder_lift_joint",
    "elbow_joint",
    "wrist_1_joint",
    "wrist_2_joint",
    "wrist_3_joint",
]

# ── Gesture poses (joint angles in RADIANS) ────────────────────────────────
# Converted from degrees recorded in RViz

def deg(*angles):
    """Convert degrees to radians."""
    return [math.radians(a) for a in angles]

# Arm pointing straight up — safe neutral position
POSE_HOME = deg(0, -90, 0, -90, 0, -155)

# Arm extended forward toward arena — alert tracking posture
POSE_READY = deg(94, -30, -101, 318, -6, -6)

# Arm bent sideways and pulled back — urgent safety retract
POSE_FREEZE = deg(9, 24, -110, 265, 79, -147)

# Gesture constants (mirror GestureRequest.msg)
GESTURE_NONE   = GestureRequest.GESTURE_NONE
GESTURE_READY  = GestureRequest.GESTURE_READY
GESTURE_POINT  = GestureRequest.GESTURE_POINT
GESTURE_FREEZE = GestureRequest.GESTURE_FREEZE
GESTURE_RESET  = GestureRequest.GESTURE_RESET

GESTURE_LABELS = {
    GESTURE_NONE:   "NONE",
    GESTURE_READY:  "READY",
    GESTURE_POINT:  "POINT",
    GESTURE_FREEZE: "FREEZE",
    GESTURE_RESET:  "RESET",
}


class ArmGestureController(Node):

    def __init__(self):
        super().__init__("arm_gesture_node")

        # ── Parameters ────────────────────────────────────────────────────
        self.declare_parameter("velocity_scale",     0.6)
        self.declare_parameter("acceleration_scale", 0.5)

        self._vel_scale  = self.get_parameter("velocity_scale").value
        self._acc_scale  = self.get_parameter("acceleration_scale").value

        # ── MoveGroup action client ───────────────────────────────────────
        self._action_client = ActionClient(self, MoveGroup, "/move_action")
        self.get_logger().info("Connecting to MoveGroup action server...")
        if not self._action_client.wait_for_server(timeout_sec=10.0):
            self.get_logger().error(
                "MoveGroup action server not available after 10s. "
                "Make sure ur_moveit_config is running with CycloneDDS active."
            )
        else:
            self.get_logger().info("MoveGroup action server connected.")

        # ── State ─────────────────────────────────────────────────────────
        self._current_gesture      = GESTURE_NONE
        self._predicted_target_pos = None
        self._executing            = False
        self._last_point_time      = 0.0   # time of last POINT execution

        # ── Publisher ─────────────────────────────────────────────────────
        self._pub_status = self.create_publisher(String, "/gesture_status", 10)

        # ── Subscribers ───────────────────────────────────────────────────
        self.create_subscription(
            GestureRequest, "/gesture_request",       self._gesture_cb, 10
        )
        self.create_subscription(
            PoseStamped,    "/predicted_target_pose_map", self._pose_cb,    10
        )

        self.get_logger().info("ArmGestureController ready.")

    # ── Callbacks ──────────────────────────────────────────────────────────

    def _pose_cb(self, msg: PoseStamped):
        p = msg.pose.position
        self._predicted_target_pos = (p.x, p.y, p.z)

    def _gesture_cb(self, msg: GestureRequest):
        # Skip duplicate gestures unless it's POINT (target moves)
        if msg.gesture_type == self._current_gesture and \
           msg.gesture_type != GESTURE_POINT:
            return

        if self._executing:
            self.get_logger().warn(
                "Gesture request ignored — still executing previous gesture.")
            return

        self._current_gesture = msg.gesture_type
        label   = GESTURE_LABELS.get(msg.gesture_type, "UNKNOWN")
        urgency = float(msg.urgency)

        # Scale velocity with urgency — urgent gestures move faster
        vel   = min(1.0, self._vel_scale * (0.5 + 0.5 * urgency))
        accel = min(1.0, self._acc_scale * (0.5 + 0.5 * urgency))

        self.get_logger().info(
            f"Gesture: {label} (urgency={urgency:.2f}, vel={vel:.2f})"
        )

        if msg.gesture_type == GESTURE_READY:
            self._move_to_pose("READY", POSE_READY, vel, accel)

        elif msg.gesture_type == GESTURE_FREEZE:
            # FREEZE always uses max speed regardless of urgency
            self._move_to_pose("FREEZE", POSE_FREEZE, 1.0, 1.0)

        elif msg.gesture_type == GESTURE_RESET:
            self._move_to_pose("HOME", POSE_HOME, vel, accel)

        elif msg.gesture_type == GESTURE_POINT:
            target = None
            if msg.target_point.x != 0 or msg.target_point.y != 0:
                target = (msg.target_point.x,
                          msg.target_point.y,
                          msg.target_point.z)
            elif self._predicted_target_pos is not None:
                target = self._predicted_target_pos

            if target is not None:
                # Rate limit POINT gestures — don't flood MoveIt
                now = self.get_clock().now().nanoseconds * 1e-9
                if now - self._last_point_time < 3.0:
                    self.get_logger().info(
                        "POINT rate limited — waiting for arm to settle.",
                        )
                    self._publish_status(label)
                    return
                self._last_point_time = now

                # Convert map frame → UR3 base_link frame
                target = self._map_to_base_link(target)
                point_pose = self._compute_point_pose(target)
                if point_pose is not None:
                    self._move_to_pose("POINT", point_pose, vel, accel)
                else:
                    self.get_logger().warn("Could not compute pointing pose.")
            else:
                self.get_logger().warn(
                    "POINT gesture requested but no target position available."
                )

        self._publish_status(label)

    # ── Motion execution ───────────────────────────────────────────────────

    def _move_to_pose(self, name: str, joint_angles: list,
                      velocity: float, acceleration: float):
        """
        Send a joint-space goal to MoveGroup and execute it.
        Uses the RobotMover pattern from the Tufts EECS UR3e guide.
        """
        self._executing = True
        self.get_logger().info(f"Moving to {name}...")

        request = MotionPlanRequest()
        request.group_name                    = "ur_manipulator"
        request.num_planning_attempts         = 20
        request.allowed_planning_time         = 10.0
        request.max_velocity_scaling_factor   = float(velocity)
        request.max_acceleration_scaling_factor = float(acceleration)
        request.workspace_parameters.header.frame_id = "base_link"
        request.workspace_parameters.min_corner = Vector3(
            x=-1.0, y=-1.0, z=-1.0
        )
        request.workspace_parameters.max_corner = Vector3(
            x=1.0, y=1.0, z=1.0
        )

        constraints = Constraints()
        for joint_name, angle in zip(JOINT_NAMES, joint_angles):
            jc                = JointConstraint()
            jc.joint_name     = joint_name
            jc.position       = angle
            jc.tolerance_above = 0.05
            jc.tolerance_below = 0.05
            jc.weight          = 1.0
            constraints.joint_constraints.append(jc)

        request.goal_constraints.append(constraints)

        goal = MoveGroup.Goal()
        goal.request                                    = request
        goal.planning_options.plan_only                 = False
        goal.planning_options.replan                    = True
        goal.planning_options.replan_attempts           = 5
        goal.planning_options.planning_scene_diff.is_diff = True

        future = self._action_client.send_goal_async(goal)
        future.add_done_callback(
            lambda f: self._goal_response_cb(f, name)
        )

    def _goal_response_cb(self, future, name: str):
        handle = future.result()
        if not handle.accepted:
            self.get_logger().warn(f"Goal for {name} was rejected.")
            self._executing = False
            return
        result_future = handle.get_result_async()
        result_future.add_done_callback(
            lambda f: self._result_cb(f, name)
        )

    def _result_cb(self, future, name: str):
        result = future.result().result
        if result.error_code.val == MoveItErrorCodes.SUCCESS:
            self.get_logger().info(f"Reached {name}.")
        else:
            self.get_logger().warn(
                f"Failed to reach {name}. "
                f"MoveIt error code: {result.error_code.val}"
            )
        self._executing = False

    # ── Coordinate transform ──────────────────────────────────────────────────

    def _map_to_base_link(self, target_map: tuple) -> tuple:
        """
        Convert a point from map frame to UR3e base_link frame.

        UR3 position in map frame: (0.0, 1.29, 0.9)
        UR3 orientation: arm faces +X direction in map frame
        base_link axes relative to map:
          base_link +X = map +X (forward into arena)
          base_link +Y = map +Y (left)
          base_link +Z = map +Z (up)

        So the transform is simply a translation by the UR3 position.
        The person is on the floor (z=0 in map) but the arm base is ~0.9m high.
        """
        # UR3 base position in map frame
        UR3_MAP_X = 0.0
        UR3_MAP_Y = 1.29
        UR3_BASE_HEIGHT = 1.25  # height of arm base above floor in meters (measured)

        mx, my, mz = target_map

        # Translate to base_link origin
        bx = mx - UR3_MAP_X
        by = my - UR3_MAP_Y
        bz = mz - UR3_BASE_HEIGHT  # person is on floor, arm base is elevated

        return (bx, by, bz)

    # ── POINT geometry ─────────────────────────────────────────────────────

    def _compute_point_pose(self, target_world: tuple) -> list | None:
        """
        Compute joint angles that point the arm toward a world-frame target.
        Uses a simplified approach: rotate shoulder_pan to face the target,
        then tilt shoulder_lift to reach toward it.

        target_world: (x, y, z) in the UR3e base_link frame
        """
        tx, ty, tz = target_world

        # Shoulder pan: rotate base to face target in XY plane
        # UR3 base joint rotates opposite to map Y axis — negate ty
        # Offset of 113.87° calibrated: base=103.55° points to map (2.80,1.80)
        PAN_OFFSET = math.radians(113.87)
        pan_angle = math.atan2(-ty, tx) + PAN_OFFSET
        # Normalize to [-pi, pi]
        while pan_angle > math.pi:
            pan_angle -= 2 * math.pi
        while pan_angle < -math.pi:
            pan_angle += 2 * math.pi

        # Distance in XY plane
        dist_xy = math.sqrt(tx**2 + ty**2)
        dist_xy = max(dist_xy, 0.05)  # avoid division by zero

        # Shoulder lift: tilt toward target elevation
        # Clamp to safe range [-120°, 0°]
        lift_angle = math.atan2(tz - 0.1, dist_xy)  # 0.1m = approx shoulder height
        lift_angle = max(math.radians(-120), min(0.0, lift_angle))

        # Use wrist angles from READY pose for a natural pointing posture
        return [
            pan_angle,           # shoulder_pan — faces target
            lift_angle,          # shoulder_lift — tilts toward target
            math.radians(-100),  # elbow — extended
            math.radians(-90),   # wrist_1
            math.radians(0),     # wrist_2
            math.radians(0),     # wrist_3
        ]

    # ── Status ─────────────────────────────────────────────────────────────

    def _publish_status(self, label: str):
        msg      = String()
        msg.data = label
        self._pub_status.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    node = ArmGestureController()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()