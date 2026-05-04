// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from predator_msgs:msg/TargetState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "predator_msgs/msg/target_state.hpp"


#ifndef PREDATOR_MSGS__MSG__DETAIL__TARGET_STATE__TRAITS_HPP_
#define PREDATOR_MSGS__MSG__DETAIL__TARGET_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "predator_msgs/msg/detail/target_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'pose'
// Member 'predicted_pose'
#include "geometry_msgs/msg/detail/pose_stamped__traits.hpp"
// Member 'velocity'
#include "geometry_msgs/msg/detail/twist_stamped__traits.hpp"

namespace predator_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const TargetState & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: pose
  {
    out << "pose: ";
    to_flow_style_yaml(msg.pose, out);
    out << ", ";
  }

  // member: velocity
  {
    out << "velocity: ";
    to_flow_style_yaml(msg.velocity, out);
    out << ", ";
  }

  // member: predicted_pose
  {
    out << "predicted_pose: ";
    to_flow_style_yaml(msg.predicted_pose, out);
    out << ", ";
  }

  // member: confidence
  {
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << ", ";
  }

  // member: is_tracked
  {
    out << "is_tracked: ";
    rosidl_generator_traits::value_to_yaml(msg.is_tracked, out);
    out << ", ";
  }

  // member: distance_to_robot
  {
    out << "distance_to_robot: ";
    rosidl_generator_traits::value_to_yaml(msg.distance_to_robot, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TargetState & msg,
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

  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_block_style_yaml(msg.pose, out, indentation + 2);
  }

  // member: velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "velocity:\n";
    to_block_style_yaml(msg.velocity, out, indentation + 2);
  }

  // member: predicted_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "predicted_pose:\n";
    to_block_style_yaml(msg.predicted_pose, out, indentation + 2);
  }

  // member: confidence
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << "\n";
  }

  // member: is_tracked
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_tracked: ";
    rosidl_generator_traits::value_to_yaml(msg.is_tracked, out);
    out << "\n";
  }

  // member: distance_to_robot
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distance_to_robot: ";
    rosidl_generator_traits::value_to_yaml(msg.distance_to_robot, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TargetState & msg, bool use_flow_style = false)
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
  const predator_msgs::msg::TargetState & msg,
  std::ostream & out, size_t indentation = 0)
{
  predator_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use predator_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const predator_msgs::msg::TargetState & msg)
{
  return predator_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<predator_msgs::msg::TargetState>()
{
  return "predator_msgs::msg::TargetState";
}

template<>
inline const char * name<predator_msgs::msg::TargetState>()
{
  return "predator_msgs/msg/TargetState";
}

template<>
struct has_fixed_size<predator_msgs::msg::TargetState>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::PoseStamped>::value && has_fixed_size<geometry_msgs::msg::TwistStamped>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<predator_msgs::msg::TargetState>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::PoseStamped>::value && has_bounded_size<geometry_msgs::msg::TwistStamped>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<predator_msgs::msg::TargetState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PREDATOR_MSGS__MSG__DETAIL__TARGET_STATE__TRAITS_HPP_
