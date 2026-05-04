# GestureRequest.msg
# Published by: behavior_manager_node
# Consumed by: arm_gesture_node

std_msgs/Header header

# Gesture type enum constants
uint8 GESTURE_NONE    = 0
uint8 GESTURE_READY   = 1   # "Ready" tracking posture
uint8 GESTURE_POINT   = 2   # Point toward predicted intercept location
uint8 GESTURE_FREEZE  = 3   # Freeze / safety retreat posture
uint8 GESTURE_RESET   = 4   # Return to home/neutral position

uint8 gesture_type                      # Requested gesture (use constants above)
geometry_msgs/Point target_point        # Used by GESTURE_POINT: world-frame target
float32 urgency                         # Motion speed scale [0.0 slow - 1.0 fast]
