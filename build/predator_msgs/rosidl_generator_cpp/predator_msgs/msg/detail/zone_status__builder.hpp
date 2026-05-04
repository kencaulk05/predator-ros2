// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from predator_msgs:msg/ZoneStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "predator_msgs/msg/zone_status.hpp"


#ifndef PREDATOR_MSGS__MSG__DETAIL__ZONE_STATUS__BUILDER_HPP_
#define PREDATOR_MSGS__MSG__DETAIL__ZONE_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "predator_msgs/msg/detail/zone_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace predator_msgs
{

namespace msg
{

namespace builder
{

class Init_ZoneStatus_zone_center
{
public:
  explicit Init_ZoneStatus_zone_center(::predator_msgs::msg::ZoneStatus & msg)
  : msg_(msg)
  {}
  ::predator_msgs::msg::ZoneStatus zone_center(::predator_msgs::msg::ZoneStatus::_zone_center_type arg)
  {
    msg_.zone_center = std::move(arg);
    return std::move(msg_);
  }

private:
  ::predator_msgs::msg::ZoneStatus msg_;
};

class Init_ZoneStatus_zone_radius
{
public:
  explicit Init_ZoneStatus_zone_radius(::predator_msgs::msg::ZoneStatus & msg)
  : msg_(msg)
  {}
  Init_ZoneStatus_zone_center zone_radius(::predator_msgs::msg::ZoneStatus::_zone_radius_type arg)
  {
    msg_.zone_radius = std::move(arg);
    return Init_ZoneStatus_zone_center(msg_);
  }

private:
  ::predator_msgs::msg::ZoneStatus msg_;
};

class Init_ZoneStatus_distance_to_zone_center
{
public:
  explicit Init_ZoneStatus_distance_to_zone_center(::predator_msgs::msg::ZoneStatus & msg)
  : msg_(msg)
  {}
  Init_ZoneStatus_zone_radius distance_to_zone_center(::predator_msgs::msg::ZoneStatus::_distance_to_zone_center_type arg)
  {
    msg_.distance_to_zone_center = std::move(arg);
    return Init_ZoneStatus_zone_radius(msg_);
  }

private:
  ::predator_msgs::msg::ZoneStatus msg_;
};

class Init_ZoneStatus_target_in_safety_zone
{
public:
  explicit Init_ZoneStatus_target_in_safety_zone(::predator_msgs::msg::ZoneStatus & msg)
  : msg_(msg)
  {}
  Init_ZoneStatus_distance_to_zone_center target_in_safety_zone(::predator_msgs::msg::ZoneStatus::_target_in_safety_zone_type arg)
  {
    msg_.target_in_safety_zone = std::move(arg);
    return Init_ZoneStatus_distance_to_zone_center(msg_);
  }

private:
  ::predator_msgs::msg::ZoneStatus msg_;
};

class Init_ZoneStatus_target_in_ur3_zone
{
public:
  explicit Init_ZoneStatus_target_in_ur3_zone(::predator_msgs::msg::ZoneStatus & msg)
  : msg_(msg)
  {}
  Init_ZoneStatus_target_in_safety_zone target_in_ur3_zone(::predator_msgs::msg::ZoneStatus::_target_in_ur3_zone_type arg)
  {
    msg_.target_in_ur3_zone = std::move(arg);
    return Init_ZoneStatus_target_in_safety_zone(msg_);
  }

private:
  ::predator_msgs::msg::ZoneStatus msg_;
};

class Init_ZoneStatus_header
{
public:
  Init_ZoneStatus_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ZoneStatus_target_in_ur3_zone header(::predator_msgs::msg::ZoneStatus::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ZoneStatus_target_in_ur3_zone(msg_);
  }

private:
  ::predator_msgs::msg::ZoneStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::predator_msgs::msg::ZoneStatus>()
{
  return predator_msgs::msg::builder::Init_ZoneStatus_header();
}

}  // namespace predator_msgs

#endif  // PREDATOR_MSGS__MSG__DETAIL__ZONE_STATUS__BUILDER_HPP_
