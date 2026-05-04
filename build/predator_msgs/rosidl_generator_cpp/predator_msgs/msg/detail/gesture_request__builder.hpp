// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from predator_msgs:msg/GestureRequest.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "predator_msgs/msg/gesture_request.hpp"


#ifndef PREDATOR_MSGS__MSG__DETAIL__GESTURE_REQUEST__BUILDER_HPP_
#define PREDATOR_MSGS__MSG__DETAIL__GESTURE_REQUEST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "predator_msgs/msg/detail/gesture_request__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace predator_msgs
{

namespace msg
{

namespace builder
{

class Init_GestureRequest_urgency
{
public:
  explicit Init_GestureRequest_urgency(::predator_msgs::msg::GestureRequest & msg)
  : msg_(msg)
  {}
  ::predator_msgs::msg::GestureRequest urgency(::predator_msgs::msg::GestureRequest::_urgency_type arg)
  {
    msg_.urgency = std::move(arg);
    return std::move(msg_);
  }

private:
  ::predator_msgs::msg::GestureRequest msg_;
};

class Init_GestureRequest_target_point
{
public:
  explicit Init_GestureRequest_target_point(::predator_msgs::msg::GestureRequest & msg)
  : msg_(msg)
  {}
  Init_GestureRequest_urgency target_point(::predator_msgs::msg::GestureRequest::_target_point_type arg)
  {
    msg_.target_point = std::move(arg);
    return Init_GestureRequest_urgency(msg_);
  }

private:
  ::predator_msgs::msg::GestureRequest msg_;
};

class Init_GestureRequest_gesture_type
{
public:
  explicit Init_GestureRequest_gesture_type(::predator_msgs::msg::GestureRequest & msg)
  : msg_(msg)
  {}
  Init_GestureRequest_target_point gesture_type(::predator_msgs::msg::GestureRequest::_gesture_type_type arg)
  {
    msg_.gesture_type = std::move(arg);
    return Init_GestureRequest_target_point(msg_);
  }

private:
  ::predator_msgs::msg::GestureRequest msg_;
};

class Init_GestureRequest_header
{
public:
  Init_GestureRequest_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GestureRequest_gesture_type header(::predator_msgs::msg::GestureRequest::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_GestureRequest_gesture_type(msg_);
  }

private:
  ::predator_msgs::msg::GestureRequest msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::predator_msgs::msg::GestureRequest>()
{
  return predator_msgs::msg::builder::Init_GestureRequest_header();
}

}  // namespace predator_msgs

#endif  // PREDATOR_MSGS__MSG__DETAIL__GESTURE_REQUEST__BUILDER_HPP_
