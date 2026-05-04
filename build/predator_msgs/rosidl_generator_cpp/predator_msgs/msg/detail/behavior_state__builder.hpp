// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from predator_msgs:msg/BehaviorState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "predator_msgs/msg/behavior_state.hpp"


#ifndef PREDATOR_MSGS__MSG__DETAIL__BEHAVIOR_STATE__BUILDER_HPP_
#define PREDATOR_MSGS__MSG__DETAIL__BEHAVIOR_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "predator_msgs/msg/detail/behavior_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace predator_msgs
{

namespace msg
{

namespace builder
{

class Init_BehaviorState_transition_reason
{
public:
  explicit Init_BehaviorState_transition_reason(::predator_msgs::msg::BehaviorState & msg)
  : msg_(msg)
  {}
  ::predator_msgs::msg::BehaviorState transition_reason(::predator_msgs::msg::BehaviorState::_transition_reason_type arg)
  {
    msg_.transition_reason = std::move(arg);
    return std::move(msg_);
  }

private:
  ::predator_msgs::msg::BehaviorState msg_;
};

class Init_BehaviorState_time_in_state
{
public:
  explicit Init_BehaviorState_time_in_state(::predator_msgs::msg::BehaviorState & msg)
  : msg_(msg)
  {}
  Init_BehaviorState_transition_reason time_in_state(::predator_msgs::msg::BehaviorState::_time_in_state_type arg)
  {
    msg_.time_in_state = std::move(arg);
    return Init_BehaviorState_transition_reason(msg_);
  }

private:
  ::predator_msgs::msg::BehaviorState msg_;
};

class Init_BehaviorState_state_label
{
public:
  explicit Init_BehaviorState_state_label(::predator_msgs::msg::BehaviorState & msg)
  : msg_(msg)
  {}
  Init_BehaviorState_time_in_state state_label(::predator_msgs::msg::BehaviorState::_state_label_type arg)
  {
    msg_.state_label = std::move(arg);
    return Init_BehaviorState_time_in_state(msg_);
  }

private:
  ::predator_msgs::msg::BehaviorState msg_;
};

class Init_BehaviorState_state
{
public:
  explicit Init_BehaviorState_state(::predator_msgs::msg::BehaviorState & msg)
  : msg_(msg)
  {}
  Init_BehaviorState_state_label state(::predator_msgs::msg::BehaviorState::_state_type arg)
  {
    msg_.state = std::move(arg);
    return Init_BehaviorState_state_label(msg_);
  }

private:
  ::predator_msgs::msg::BehaviorState msg_;
};

class Init_BehaviorState_header
{
public:
  Init_BehaviorState_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BehaviorState_state header(::predator_msgs::msg::BehaviorState::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_BehaviorState_state(msg_);
  }

private:
  ::predator_msgs::msg::BehaviorState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::predator_msgs::msg::BehaviorState>()
{
  return predator_msgs::msg::builder::Init_BehaviorState_header();
}

}  // namespace predator_msgs

#endif  // PREDATOR_MSGS__MSG__DETAIL__BEHAVIOR_STATE__BUILDER_HPP_
