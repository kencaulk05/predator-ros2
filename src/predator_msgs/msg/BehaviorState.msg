# BehaviorState.msg
# Published by: behavior_manager_node
# Consumed by: pursuit_planner_node, arm_gesture_node, safety_supervisor_node

std_msgs/Header header

# State enum constants
uint8 SEARCH       = 0
uint8 ACQUIRE      = 1
uint8 PURSUIT      = 2
uint8 HERD         = 3
uint8 ARM_ALERT    = 4
uint8 SAFETY_STOP  = 5
uint8 REACQUIRE    = 6

uint8 state                  # Current behavior state (use constants above)
string state_label           # Human-readable state name for debugging
float32 time_in_state        # Seconds spent in current state
string transition_reason     # Why the last state transition occurred
