# ZoneStatus.msg
# Published by: zone_monitor_node
# Consumed by: behavior_manager_node, arm_gesture_node

std_msgs/Header header

bool target_in_ur3_zone          # True if target is within UR3 interaction region
bool target_in_safety_zone       # True if target is within minimum safe distance
float32 distance_to_zone_center  # Distance from target to UR3 zone center [m]
float32 zone_radius              # Configured radius of the UR3 interaction zone [m]
geometry_msgs/Point zone_center  # Center of the UR3 interaction zone in map frame
