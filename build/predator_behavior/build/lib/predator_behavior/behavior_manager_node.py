#!/usr/bin/env python3
"""
behavior_manager_node.py
========================
7-state FSM that drives the Predator robot system.

States:
  SEARCH      → No target. Arm in HOME. Turtlebot at standby.
  ACQUIRE     → Target detected but not yet confirmed stable.
                Arm moves to READY. Wait for confidence to stabilize.
  PURSUIT     → Target confirmed. Turtlebot drives toward intercept.
                Arm stays READY.
  HERD        → Turtlebot has reached intercept range. Robot herds
                person toward UR3 arm. Arm POINT at target.
  ARM_ALERT   → Target inside UR3 interaction zone.
                Turtlebot holds position. Arm POINT at full urgency.
  SAFETY_STOP → Safety zone breached or safety_supervisor override.
                All motion stops. Arm FREEZE.
  REACQUIRE   → Tracking lost mid-interaction. Wait for reacquisition.
                Arm holds READY. Turtlebot holds position.

Subscriptions:
  /target_confidence    (std_msgs/Float32)
  /target_pose_map       (geometry_msgs/PoseStamped)
  /zone_status          (predator_msgs/ZoneStatus)
  /safety_status        (std_msgs/Bool)

Publications:
  /behavior_state       (predator_msgs/BehaviorState)
  /gesture_request      (predator_msgs/GestureRequest)
"""

import rclpy
from rclpy.node import Node

from std_msgs.msg import Float32, Bool
from geometry_msgs.msg import Point, PoseStamped
from predator_msgs.msg import BehaviorState, ZoneStatus, GestureRequest

# ── State constants ──────────────────────────────────────────────────────────
SEARCH      = BehaviorState.SEARCH
ACQUIRE     = BehaviorState.ACQUIRE
PURSUIT     = BehaviorState.PURSUIT
HERD        = BehaviorState.HERD
ARM_ALERT   = BehaviorState.ARM_ALERT
SAFETY_STOP = BehaviorState.SAFETY_STOP
REACQUIRE   = BehaviorState.REACQUIRE

STATE_LABELS = {
    SEARCH:      "SEARCH",
    ACQUIRE:     "ACQUIRE",
    PURSUIT:     "PURSUIT",
    HERD:        "HERD",
    ARM_ALERT:   "ARM_ALERT",
    SAFETY_STOP: "SAFETY_STOP",
    REACQUIRE:   "REACQUIRE",
}

# ── Gesture constants ────────────────────────────────────────────────────────
GESTURE_NONE   = GestureRequest.GESTURE_NONE
GESTURE_READY  = GestureRequest.GESTURE_READY
GESTURE_POINT  = GestureRequest.GESTURE_POINT
GESTURE_FREEZE = GestureRequest.GESTURE_FREEZE
GESTURE_RESET  = GestureRequest.GESTURE_RESET


class BehaviorManager(Node):

    def __init__(self):
        super().__init__("behavior_manager_node")

        # ── Parameters ───────────────────────────────────────────────────────
        self.declare_parameter("acquire_confidence_threshold", 0.6)
        self.declare_parameter("lost_confidence_threshold",    0.2)
        self.declare_parameter("acquire_stable_duration_s",    1.5)
        self.declare_parameter("reacquire_timeout_s",          4.0)
        self.declare_parameter("herd_distance_threshold_m",    1.2)
        self.declare_parameter("state_publish_rate_hz",        10.0)
        self.declare_parameter("gesture_publish_rate_hz",       2.0)

        self._acquire_threshold  = self.get_parameter("acquire_confidence_threshold").value
        self._lost_threshold     = self.get_parameter("lost_confidence_threshold").value
        self._acquire_stable_dur = self.get_parameter("acquire_stable_duration_s").value
        self._reacquire_timeout  = self.get_parameter("reacquire_timeout_s").value
        self._herd_dist_thresh   = self.get_parameter("herd_distance_threshold_m").value
        state_rate               = self.get_parameter("state_publish_rate_hz").value
        gesture_rate             = self.get_parameter("gesture_publish_rate_hz").value

        # ── Internal state ───────────────────────────────────────────────────
        self._state              = SEARCH
        self._prev_state         = SEARCH
        self._state_entry_time   = self.get_clock().now()
        self._transition_reason  = "startup"

        self._confidence         = 0.0
        self._in_ur3_zone        = False
        self._in_safety_zone     = False
        self._safety_override    = False
        self._distance_to_ur3    = float('inf')

        # Target position (updated from /target_pose_map)
        self._target_point       = Point()
        self._target_available   = False

        # Track when we first exceeded acquire threshold (for stable duration)
        self._acquire_start_time = None

        # Track last gesture published to avoid spamming
        self._last_gesture_type  = GESTURE_NONE
        self._last_gesture_state = None

        # ── Publishers ───────────────────────────────────────────────────────
        self._pub_state   = self.create_publisher(
            BehaviorState,  "/behavior_state",  10)
        self._pub_gesture = self.create_publisher(
            GestureRequest, "/gesture_request", 10)

        # ── Subscribers ──────────────────────────────────────────────────────
        self.create_subscription(
            Float32,     "/target_confidence", self._confidence_cb, 10)
        self.create_subscription(
            PoseStamped, "/target_pose_map",        self._target_pose_cb, 10)
        self.create_subscription(
            ZoneStatus,  "/zone_status",        self._zone_cb,       10)
        self.create_subscription(
            Bool,        "/safety_status",      self._safety_cb,     10)

        # ── Timers ───────────────────────────────────────────────────────────
        self.create_timer(1.0 / state_rate,   self._update_tick)
        self.create_timer(1.0 / gesture_rate, self._gesture_tick)

        self.get_logger().info(
            f"BehaviorManager ready — starting in SEARCH.\n"
            f"  acquire_threshold={self._acquire_threshold}, "
            f"  stable_duration={self._acquire_stable_dur}s, "
            f"  reacquire_timeout={self._reacquire_timeout}s, "
            f"  herd_dist_threshold={self._herd_dist_thresh}m")

    # ── Subscriber callbacks ─────────────────────────────────────────────────

    def _confidence_cb(self, msg: Float32):
        self._confidence = msg.data

        # Track when confidence first exceeded acquire threshold
        if self._confidence >= self._acquire_threshold:
            if self._acquire_start_time is None:
                self._acquire_start_time = self.get_clock().now()
        else:
            self._acquire_start_time = None

    def _target_pose_cb(self, msg: PoseStamped):
        self._target_point.x = msg.pose.position.x
        self._target_point.y = msg.pose.position.y
        self._target_point.z = msg.pose.position.z
        self._target_available = True

    def _zone_cb(self, msg: ZoneStatus):
        self._in_ur3_zone      = msg.target_in_ur3_zone
        self._in_safety_zone   = msg.target_in_safety_zone
        self._distance_to_ur3  = msg.distance_to_zone_center

    def _safety_cb(self, msg: Bool):
        self._safety_override = msg.data

    # ── Main FSM update tick ─────────────────────────────────────────────────

    def _update_tick(self):
        new_state, reason = self._evaluate_transitions()
        if new_state != self._state:
            self._transition(new_state, reason)
        self._publish_state()

    def _evaluate_transitions(self) -> tuple:
        """
        Evaluate all transition conditions in priority order.
        Returns (next_state, reason_string).
        """

        # ── Priority 1: Safety always wins ──────────────────────────────────
        if self._safety_override or self._in_safety_zone:
            return SAFETY_STOP, "safety override or target in safety zone"

        # ── Priority 2: Recover from SAFETY_STOP when safe again ────────────
        if self._state == SAFETY_STOP:
            if not self._safety_override and not self._in_safety_zone:
                return SEARCH, "safety cleared — resetting to SEARCH"

        # ── Priority 3: Target in UR3 zone ───────────────────────────────────
        if self._in_ur3_zone and self._confidence >= self._lost_threshold:
            return ARM_ALERT, "target entered UR3 interaction zone"

        # ── Priority 4: Leave ARM_ALERT if target exits zone ─────────────────
        if self._state == ARM_ALERT:
            if not self._in_ur3_zone:
                return PURSUIT, "target left UR3 zone — resuming pursuit"

        # ── Priority 5: Tracking lost ─────────────────────────────────────────
        if self._confidence < self._lost_threshold:
            if self._state == SEARCH:
                return SEARCH, "searching..."
            if self._state == REACQUIRE:
                elapsed = self._time_in_state()
                if elapsed > self._reacquire_timeout:
                    return SEARCH, f"reacquire timeout ({elapsed:.1f}s) — back to SEARCH"
                return REACQUIRE, f"reacquiring... ({elapsed:.1f}s)"
            # Was tracking — try to reacquire
            return REACQUIRE, f"tracking lost (conf={self._confidence:.2f})"

        # ── Priority 6: Confidence-based transitions ──────────────────────────
        if self._confidence >= self._acquire_threshold:

            if self._state in (SEARCH, REACQUIRE):
                return ACQUIRE, f"target detected (conf={self._confidence:.2f})"

            if self._state == ACQUIRE:
                # Require stable confidence for acquire_stable_duration_s
                if self._acquire_start_time is not None:
                    stable_s = (
                        self.get_clock().now() - self._acquire_start_time
                    ).nanoseconds * 1e-9
                    if stable_s >= self._acquire_stable_dur:
                        return PURSUIT, f"target confirmed stable for {stable_s:.1f}s"
                return ACQUIRE, f"acquiring... (conf={self._confidence:.2f})"

            if self._state == PURSUIT:
                # Transition to HERD when close enough to the target
                if (self._target_available and
                        self._distance_to_ur3 <= self._herd_dist_thresh * 2):
                    return HERD, (f"target close to UR3 zone "
                                  f"(dist={self._distance_to_ur3:.2f}m) — herding")
                return PURSUIT, f"pursuing (conf={self._confidence:.2f})"

            if self._state == HERD:
                # Stay in HERD until target enters UR3 zone or tracking lost
                return HERD, f"herding (dist_to_ur3={self._distance_to_ur3:.2f}m)"

        # ── Default: hold current state ───────────────────────────────────────
        return self._state, f"holding {STATE_LABELS.get(self._state,'?')}"

    # ── State transition ──────────────────────────────────────────────────────

    def _transition(self, new_state: int, reason: str):
        old_label = STATE_LABELS.get(self._state, "?")
        new_label = STATE_LABELS.get(new_state, "?")
        self.get_logger().info(
            f"[FSM] {old_label} → {new_label} | {reason}")
        self._prev_state        = self._state
        self._state             = new_state
        self._state_entry_time  = self.get_clock().now()
        self._transition_reason = reason

        # Reset acquire timer on any non-ACQUIRE transition
        if new_state != ACQUIRE:
            self._acquire_start_time = None

    # ── Gesture tick (runs at gesture_publish_rate_hz) ────────────────────────

    def _gesture_tick(self):
        """
        Publish gesture requests appropriate for current state.
        Only publishes when state changes to avoid spamming the arm.
        """
        gesture_type, urgency = self._gesture_for_state()

        # Only republish if state changed or gesture type changed
        if (self._state == self._last_gesture_state and
                gesture_type == self._last_gesture_type):
            return

        req              = GestureRequest()
        req.header.stamp = self.get_clock().now().to_msg()
        req.gesture_type = gesture_type
        req.urgency      = float(urgency)
        req.target_point = self._target_point
        self._pub_gesture.publish(req)

        self._last_gesture_type  = gesture_type
        self._last_gesture_state = self._state

    def _gesture_for_state(self) -> tuple:
        """Returns (gesture_type, urgency) for the current state."""
        if self._state == SEARCH:
            return GESTURE_RESET, 0.3

        elif self._state == ACQUIRE:
            return GESTURE_READY, 0.5

        elif self._state == PURSUIT:
            return GESTURE_READY, 0.7

        elif self._state == HERD:
            return GESTURE_POINT, 0.8

        elif self._state == ARM_ALERT:
            return GESTURE_POINT, 1.0

        elif self._state == SAFETY_STOP:
            return GESTURE_FREEZE, 1.0

        elif self._state == REACQUIRE:
            return GESTURE_READY, 0.4

        return GESTURE_NONE, 0.0

    # ── State publisher ───────────────────────────────────────────────────────

    def _publish_state(self):
        msg                   = BehaviorState()
        msg.header.stamp      = self.get_clock().now().to_msg()
        msg.header.frame_id   = "map"
        msg.state             = self._state
        msg.state_label       = STATE_LABELS.get(self._state, "UNKNOWN")
        msg.time_in_state     = float(self._time_in_state())
        msg.transition_reason = self._transition_reason
        self._pub_state.publish(msg)

    # ── Helpers ───────────────────────────────────────────────────────────────

    def _time_in_state(self) -> float:
        elapsed = self.get_clock().now() - self._state_entry_time
        return elapsed.nanoseconds * 1e-9


def main(args=None):
    rclpy.init(args=args)
    node = BehaviorManager()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
