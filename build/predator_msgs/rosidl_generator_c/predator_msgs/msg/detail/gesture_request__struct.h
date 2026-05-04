// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from predator_msgs:msg/GestureRequest.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "predator_msgs/msg/gesture_request.h"


#ifndef PREDATOR_MSGS__MSG__DETAIL__GESTURE_REQUEST__STRUCT_H_
#define PREDATOR_MSGS__MSG__DETAIL__GESTURE_REQUEST__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Constant 'GESTURE_NONE'.
/**
  * Gesture type enum constants
 */
enum
{
  predator_msgs__msg__GestureRequest__GESTURE_NONE = 0
};

/// Constant 'GESTURE_READY'.
/**
  * "Ready" tracking posture
 */
enum
{
  predator_msgs__msg__GestureRequest__GESTURE_READY = 1
};

/// Constant 'GESTURE_POINT'.
/**
  * Point toward predicted intercept location
 */
enum
{
  predator_msgs__msg__GestureRequest__GESTURE_POINT = 2
};

/// Constant 'GESTURE_FREEZE'.
/**
  * Freeze / safety retreat posture
 */
enum
{
  predator_msgs__msg__GestureRequest__GESTURE_FREEZE = 3
};

/// Constant 'GESTURE_RESET'.
/**
  * Return to home/neutral position
 */
enum
{
  predator_msgs__msg__GestureRequest__GESTURE_RESET = 4
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'target_point'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/GestureRequest in the package predator_msgs.
/**
  * GestureRequest.msg
  * Published by: behavior_manager_node
  * Consumed by: arm_gesture_node
 */
typedef struct predator_msgs__msg__GestureRequest
{
  std_msgs__msg__Header header;
  /// Requested gesture (use constants above)
  uint8_t gesture_type;
  /// Used by GESTURE_POINT: world-frame target
  geometry_msgs__msg__Point target_point;
  /// Motion speed scale
  float urgency;
} predator_msgs__msg__GestureRequest;

// Struct for a sequence of predator_msgs__msg__GestureRequest.
typedef struct predator_msgs__msg__GestureRequest__Sequence
{
  predator_msgs__msg__GestureRequest * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} predator_msgs__msg__GestureRequest__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PREDATOR_MSGS__MSG__DETAIL__GESTURE_REQUEST__STRUCT_H_
