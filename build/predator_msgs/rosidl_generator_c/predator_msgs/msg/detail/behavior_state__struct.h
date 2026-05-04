// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from predator_msgs:msg/BehaviorState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "predator_msgs/msg/behavior_state.h"


#ifndef PREDATOR_MSGS__MSG__DETAIL__BEHAVIOR_STATE__STRUCT_H_
#define PREDATOR_MSGS__MSG__DETAIL__BEHAVIOR_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Constant 'SEARCH'.
/**
  * State enum constants
 */
enum
{
  predator_msgs__msg__BehaviorState__SEARCH = 0
};

/// Constant 'ACQUIRE'.
enum
{
  predator_msgs__msg__BehaviorState__ACQUIRE = 1
};

/// Constant 'PURSUIT'.
enum
{
  predator_msgs__msg__BehaviorState__PURSUIT = 2
};

/// Constant 'HERD'.
enum
{
  predator_msgs__msg__BehaviorState__HERD = 3
};

/// Constant 'ARM_ALERT'.
enum
{
  predator_msgs__msg__BehaviorState__ARM_ALERT = 4
};

/// Constant 'SAFETY_STOP'.
enum
{
  predator_msgs__msg__BehaviorState__SAFETY_STOP = 5
};

/// Constant 'REACQUIRE'.
enum
{
  predator_msgs__msg__BehaviorState__REACQUIRE = 6
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'state_label'
// Member 'transition_reason'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/BehaviorState in the package predator_msgs.
/**
  * BehaviorState.msg
  * Published by: behavior_manager_node
  * Consumed by: pursuit_planner_node, arm_gesture_node, safety_supervisor_node
 */
typedef struct predator_msgs__msg__BehaviorState
{
  std_msgs__msg__Header header;
  /// Current behavior state (use constants above)
  uint8_t state;
  /// Human-readable state name for debugging
  rosidl_runtime_c__String state_label;
  /// Seconds spent in current state
  float time_in_state;
  /// Why the last state transition occurred
  rosidl_runtime_c__String transition_reason;
} predator_msgs__msg__BehaviorState;

// Struct for a sequence of predator_msgs__msg__BehaviorState.
typedef struct predator_msgs__msg__BehaviorState__Sequence
{
  predator_msgs__msg__BehaviorState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} predator_msgs__msg__BehaviorState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PREDATOR_MSGS__MSG__DETAIL__BEHAVIOR_STATE__STRUCT_H_
