// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from predator_msgs:msg/GestureRequest.idl
// generated code does not contain a copyright notice
#ifndef PREDATOR_MSGS__MSG__DETAIL__GESTURE_REQUEST__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define PREDATOR_MSGS__MSG__DETAIL__GESTURE_REQUEST__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "predator_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "predator_msgs/msg/detail/gesture_request__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_predator_msgs
bool cdr_serialize_predator_msgs__msg__GestureRequest(
  const predator_msgs__msg__GestureRequest * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_predator_msgs
bool cdr_deserialize_predator_msgs__msg__GestureRequest(
  eprosima::fastcdr::Cdr &,
  predator_msgs__msg__GestureRequest * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_predator_msgs
size_t get_serialized_size_predator_msgs__msg__GestureRequest(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_predator_msgs
size_t max_serialized_size_predator_msgs__msg__GestureRequest(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_predator_msgs
bool cdr_serialize_key_predator_msgs__msg__GestureRequest(
  const predator_msgs__msg__GestureRequest * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_predator_msgs
size_t get_serialized_size_key_predator_msgs__msg__GestureRequest(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_predator_msgs
size_t max_serialized_size_key_predator_msgs__msg__GestureRequest(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_predator_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, predator_msgs, msg, GestureRequest)();

#ifdef __cplusplus
}
#endif

#endif  // PREDATOR_MSGS__MSG__DETAIL__GESTURE_REQUEST__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
