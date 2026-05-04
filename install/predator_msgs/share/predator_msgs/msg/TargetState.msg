# TargetState.msg
# Published by: target_tracker_node, velocity_estimator_node
# Consumed by: behavior_manager_node, pursuit_planner_node, safety_supervisor_node

std_msgs/Header header

geometry_msgs/PoseStamped pose          # Current estimated pose in map frame
geometry_msgs/TwistStamped velocity     # Estimated linear + angular velocity
geometry_msgs/PoseStamped predicted_pose  # Short-horizon predicted position

float32 confidence                      # Tracking confidence [0.0 - 1.0]
bool is_tracked                         # True if target is actively tracked
float32 distance_to_robot               # Euclidean distance from robot base [m]
