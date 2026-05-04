// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from predator_msgs:msg/ZoneStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "predator_msgs/msg/zone_status.h"


#ifndef PREDATOR_MSGS__MSG__DETAIL__ZONE_STATUS__STRUCT_H_
#define PREDATOR_MSGS__MSG__DETAIL__ZONE_STATUS__STRUCT_H_

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
// Member 'zone_center'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/ZoneStatus in the package predator_msgs.
/**
  * ZoneStatus.msg
  * Published by: zone_monitor_node
  * Consumed by: behavior_manager_node, arm_gesture_node
 */
typedef struct predator_msgs__msg__ZoneStatus
{
  std_msgs__msg__Header header;
  /// True if target is within UR3 interaction region
  bool target_in_ur3_zone;
  /// True if target is within minimum safe distance
  bool target_in_safety_zone;
  /// Distance from target to UR3 zone center
  float distance_to_zone_center;
  /// Configured radius of the UR3 interaction zone
  float zone_radius;
  /// Center of the UR3 interaction zone in map frame
  geometry_msgs__msg__Point zone_center;
} predator_msgs__msg__ZoneStatus;

// Struct for a sequence of predator_msgs__msg__ZoneStatus.
typedef struct predator_msgs__msg__ZoneStatus__Sequence
{
  predator_msgs__msg__ZoneStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} predator_msgs__msg__ZoneStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PREDATOR_MSGS__MSG__DETAIL__ZONE_STATUS__STRUCT_H_
