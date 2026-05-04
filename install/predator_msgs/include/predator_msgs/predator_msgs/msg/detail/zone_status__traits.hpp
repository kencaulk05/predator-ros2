// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from predator_msgs:msg/ZoneStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "predator_msgs/msg/zone_status.hpp"


#ifndef PREDATOR_MSGS__MSG__DETAIL__ZONE_STATUS__TRAITS_HPP_
#define PREDATOR_MSGS__MSG__DETAIL__ZONE_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "predator_msgs/msg/detail/zone_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'zone_center'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace predator_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ZoneStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: target_in_ur3_zone
  {
    out << "target_in_ur3_zone: ";
    rosidl_generator_traits::value_to_yaml(msg.target_in_ur3_zone, out);
    out << ", ";
  }

  // member: target_in_safety_zone
  {
    out << "target_in_safety_zone: ";
    rosidl_generator_traits::value_to_yaml(msg.target_in_safety_zone, out);
    out << ", ";
  }

  // member: distance_to_zone_center
  {
    out << "distance_to_zone_center: ";
    rosidl_generator_traits::value_to_yaml(msg.distance_to_zone_center, out);
    out << ", ";
  }

  // member: zone_radius
  {
    out << "zone_radius: ";
    rosidl_generator_traits::value_to_yaml(msg.zone_radius, out);
    out << ", ";
  }

  // member: zone_center
  {
    out << "zone_center: ";
    to_flow_style_yaml(msg.zone_center, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ZoneStatus & msg,
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

  // member: target_in_ur3_zone
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_in_ur3_zone: ";
    rosidl_generator_traits::value_to_yaml(msg.target_in_ur3_zone, out);
    out << "\n";
  }

  // member: target_in_safety_zone
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_in_safety_zone: ";
    rosidl_generator_traits::value_to_yaml(msg.target_in_safety_zone, out);
    out << "\n";
  }

  // member: distance_to_zone_center
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distance_to_zone_center: ";
    rosidl_generator_traits::value_to_yaml(msg.distance_to_zone_center, out);
    out << "\n";
  }

  // member: zone_radius
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "zone_radius: ";
    rosidl_generator_traits::value_to_yaml(msg.zone_radius, out);
    out << "\n";
  }

  // member: zone_center
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "zone_center:\n";
    to_block_style_yaml(msg.zone_center, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ZoneStatus & msg, bool use_flow_style = false)
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
  const predator_msgs::msg::ZoneStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  predator_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use predator_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const predator_msgs::msg::ZoneStatus & msg)
{
  return predator_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<predator_msgs::msg::ZoneStatus>()
{
  return "predator_msgs::msg::ZoneStatus";
}

template<>
inline const char * name<predator_msgs::msg::ZoneStatus>()
{
  return "predator_msgs/msg/ZoneStatus";
}

template<>
struct has_fixed_size<predator_msgs::msg::ZoneStatus>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<predator_msgs::msg::ZoneStatus>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<predator_msgs::msg::ZoneStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PREDATOR_MSGS__MSG__DETAIL__ZONE_STATUS__TRAITS_HPP_
