// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from predator_msgs:msg/BehaviorState.idl
// generated code does not contain a copyright notice

#ifndef PREDATOR_MSGS__MSG__DETAIL__BEHAVIOR_STATE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define PREDATOR_MSGS__MSG__DETAIL__BEHAVIOR_STATE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include <cstddef>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "predator_msgs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "predator_msgs/msg/detail/behavior_state__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace predator_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_predator_msgs
cdr_serialize(
  const predator_msgs::msg::BehaviorState & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_predator_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  predator_msgs::msg::BehaviorState & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_predator_msgs
get_serialized_size(
  const predator_msgs::msg::BehaviorState & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_predator_msgs
max_serialized_size_BehaviorState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_predator_msgs
cdr_serialize_key(
  const predator_msgs::msg::BehaviorState & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_predator_msgs
get_serialized_size_key(
  const predator_msgs::msg::BehaviorState & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_predator_msgs
max_serialized_size_key_BehaviorState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace predator_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_predator_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, predator_msgs, msg, BehaviorState)();

#ifdef __cplusplus
}
#endif

#endif  // PREDATOR_MSGS__MSG__DETAIL__BEHAVIOR_STATE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
