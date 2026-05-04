// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from predator_msgs:msg/TargetState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "predator_msgs/msg/target_state.h"


#ifndef PREDATOR_MSGS__MSG__DETAIL__TARGET_STATE__STRUCT_H_
#define PREDATOR_MSGS__MSG__DETAIL__TARGET_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'pose'
// Member 'predicted_pose'
#include "geometry_msgs/msg/detail/pose_stamped__struct.h"
// Member 'velocity'
#include "geometry_msgs/msg/detail/twist_stamped__struct.h"

/// Struct defined in msg/TargetState in the package predator_msgs.
/**
  * TargetState.msg
  * Published by: target_tracker_node, velocity_estimator_node
  * Consumed by: behavior_manager_node, pursuit_planner_node, safety_supervisor_node
 */
typedef struct predator_msgs__msg__TargetState
{
  std_msgs__msg__Header header;
  /// Current estimated pose in map frame
  geometry_msgs__msg__PoseStamped pose;
  /// Estimated linear + angular velocity
  geometry_msgs__msg__TwistStamped velocity;
  /// Short-horizon predicted position
  geometry_msgs__msg__PoseStamped predicted_pose;
  /// Tracking confidence
  float confidence;
  /// True if target is actively tracked
  bool is_tracked;
  /// Euclidean distance from robot base
  float distance_to_robot;
} predator_msgs__msg__TargetState;

// Struct for a sequence of predator_msgs__msg__TargetState.
typedef struct predator_msgs__msg__TargetState__Sequence
{
  predator_msgs__msg__TargetState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} predator_msgs__msg__TargetState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PREDATOR_MSGS__MSG__DETAIL__TARGET_STATE__STRUCT_H_
