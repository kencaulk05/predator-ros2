// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from predator_msgs:msg/TargetState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "predator_msgs/msg/target_state.hpp"


#ifndef PREDATOR_MSGS__MSG__DETAIL__TARGET_STATE__BUILDER_HPP_
#define PREDATOR_MSGS__MSG__DETAIL__TARGET_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "predator_msgs/msg/detail/target_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace predator_msgs
{

namespace msg
{

namespace builder
{

class Init_TargetState_distance_to_robot
{
public:
  explicit Init_TargetState_distance_to_robot(::predator_msgs::msg::TargetState & msg)
  : msg_(msg)
  {}
  ::predator_msgs::msg::TargetState distance_to_robot(::predator_msgs::msg::TargetState::_distance_to_robot_type arg)
  {
    msg_.distance_to_robot = std::move(arg);
    return std::move(msg_);
  }

private:
  ::predator_msgs::msg::TargetState msg_;
};

class Init_TargetState_is_tracked
{
public:
  explicit Init_TargetState_is_tracked(::predator_msgs::msg::TargetState & msg)
  : msg_(msg)
  {}
  Init_TargetState_distance_to_robot is_tracked(::predator_msgs::msg::TargetState::_is_tracked_type arg)
  {
    msg_.is_tracked = std::move(arg);
    return Init_TargetState_distance_to_robot(msg_);
  }

private:
  ::predator_msgs::msg::TargetState msg_;
};

class Init_TargetState_confidence
{
public:
  explicit Init_TargetState_confidence(::predator_msgs::msg::TargetState & msg)
  : msg_(msg)
  {}
  Init_TargetState_is_tracked confidence(::predator_msgs::msg::TargetState::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_TargetState_is_tracked(msg_);
  }

private:
  ::predator_msgs::msg::TargetState msg_;
};

class Init_TargetState_predicted_pose
{
public:
  explicit Init_TargetState_predicted_pose(::predator_msgs::msg::TargetState & msg)
  : msg_(msg)
  {}
  Init_TargetState_confidence predicted_pose(::predator_msgs::msg::TargetState::_predicted_pose_type arg)
  {
    msg_.predicted_pose = std::move(arg);
    return Init_TargetState_confidence(msg_);
  }

private:
  ::predator_msgs::msg::TargetState msg_;
};

class Init_TargetState_velocity
{
public:
  explicit Init_TargetState_velocity(::predator_msgs::msg::TargetState & msg)
  : msg_(msg)
  {}
  Init_TargetState_predicted_pose velocity(::predator_msgs::msg::TargetState::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_TargetState_predicted_pose(msg_);
  }

private:
  ::predator_msgs::msg::TargetState msg_;
};

class Init_TargetState_pose
{
public:
  explicit Init_TargetState_pose(::predator_msgs::msg::TargetState & msg)
  : msg_(msg)
  {}
  Init_TargetState_velocity pose(::predator_msgs::msg::TargetState::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_TargetState_velocity(msg_);
  }

private:
  ::predator_msgs::msg::TargetState msg_;
};

class Init_TargetState_header
{
public:
  Init_TargetState_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TargetState_pose header(::predator_msgs::msg::TargetState::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_TargetState_pose(msg_);
  }

private:
  ::predator_msgs::msg::TargetState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::predator_msgs::msg::TargetState>()
{
  return predator_msgs::msg::builder::Init_TargetState_header();
}

}  // namespace predator_msgs

#endif  // PREDATOR_MSGS__MSG__DETAIL__TARGET_STATE__BUILDER_HPP_
