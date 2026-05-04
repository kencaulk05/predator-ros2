// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from predator_msgs:msg/GestureRequest.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "predator_msgs/msg/gesture_request.hpp"


#ifndef PREDATOR_MSGS__MSG__DETAIL__GESTURE_REQUEST__TRAITS_HPP_
#define PREDATOR_MSGS__MSG__DETAIL__GESTURE_REQUEST__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "predator_msgs/msg/detail/gesture_request__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'target_point'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace predator_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const GestureRequest & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: gesture_type
  {
    out << "gesture_type: ";
    rosidl_generator_traits::value_to_yaml(msg.gesture_type, out);
    out << ", ";
  }

  // member: target_point
  {
    out << "target_point: ";
    to_flow_style_yaml(msg.target_point, out);
    out << ", ";
  }

  // member: urgency
  {
    out << "urgency: ";
    rosidl_generator_traits::value_to_yaml(msg.urgency, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GestureRequest & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: gesture_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gesture_type: ";
    rosidl_generator_traits::value_to_yaml(msg.gesture_type, out);
    out << "\n";
  }

  // member: target_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_point:\n";
    to_block_style_yaml(msg.target_point, out, indentation + 2);
  }

  // member: urgency
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "urgency: ";
    rosidl_generator_traits::value_to_yaml(msg.urgency, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GestureRequest & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace predator_msgs

namespace rosidl_generator_traits
{

[[deprecated("use predator_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const predator_msgs::msg::GestureRequest & msg,
  std::ostream & out, size_t indentation = 0)
{
  predator_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use predator_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const predator_msgs::msg::GestureRequest & msg)
{
  return predator_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<predator_msgs::msg::GestureRequest>()
{
  return "predator_msgs::msg::GestureRequest";
}

template<>
inline const char * name<predator_msgs::msg::GestureRequest>()
{
  return "predator_msgs/msg/GestureRequest";
}

template<>
struct has_fixed_size<predator_msgs::msg::GestureRequest>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<predator_msgs::msg::GestureRequest>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<predator_msgs::msg::GestureRequest>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PREDATOR_MSGS__MSG__DETAIL__GESTURE_REQUEST__TRAITS_HPP_
