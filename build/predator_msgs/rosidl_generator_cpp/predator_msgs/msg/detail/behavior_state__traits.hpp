// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from predator_msgs:msg/BehaviorState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "predator_msgs/msg/behavior_state.hpp"


#ifndef PREDATOR_MSGS__MSG__DETAIL__BEHAVIOR_STATE__TRAITS_HPP_
#define PREDATOR_MSGS__MSG__DETAIL__BEHAVIOR_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "predator_msgs/msg/detail/behavior_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace predator_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const BehaviorState & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: state
  {
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
    out << ", ";
  }

  // member: state_label
  {
    out << "state_label: ";
    rosidl_generator_traits::value_to_yaml(msg.state_label, out);
    out << ", ";
  }

  // member: time_in_state
  {
    out << "time_in_state: ";
    rosidl_generator_traits::value_to_yaml(msg.time_in_state, out);
    out << ", ";
  }

  // member: transition_reason
  {
    out << "transition_reason: ";
    rosidl_generator_traits::value_to_yaml(msg.transition_reason, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BehaviorState & msg,
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

  // member: state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
    out << "\n";
  }

  // member: state_label
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state_label: ";
    rosidl_generator_traits::value_to_yaml(msg.state_label, out);
    out << "\n";
  }

  // member: time_in_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time_in_state: ";
    rosidl_generator_traits::value_to_yaml(msg.time_in_state, out);
    out << "\n";
  }

  // member: transition_reason
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "transition_reason: ";
    rosidl_generator_traits::value_to_yaml(msg.transition_reason, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BehaviorState & msg, bool use_flow_style = false)
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
  const predator_msgs::msg::BehaviorState & msg,
  std::ostream & out, size_t indentation = 0)
{
  predator_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use predator_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const predator_msgs::msg::BehaviorState & msg)
{
  return predator_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<predator_msgs::msg::BehaviorState>()
{
  return "predator_msgs::msg::BehaviorState";
}

template<>
inline const char * name<predator_msgs::msg::BehaviorState>()
{
  return "predator_msgs/msg/BehaviorState";
}

template<>
struct has_fixed_size<predator_msgs::msg::BehaviorState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<predator_msgs::msg::BehaviorState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<predator_msgs::msg::BehaviorState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PREDATOR_MSGS__MSG__DETAIL__BEHAVIOR_STATE__TRAITS_HPP_
