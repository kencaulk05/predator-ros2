// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from predator_msgs:msg/GestureRequest.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "predator_msgs/msg/gesture_request.hpp"


#ifndef PREDATOR_MSGS__MSG__DETAIL__GESTURE_REQUEST__STRUCT_HPP_
#define PREDATOR_MSGS__MSG__DETAIL__GESTURE_REQUEST__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'target_point'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__predator_msgs__msg__GestureRequest __attribute__((deprecated))
#else
# define DEPRECATED__predator_msgs__msg__GestureRequest __declspec(deprecated)
#endif

namespace predator_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GestureRequest_
{
  using Type = GestureRequest_<ContainerAllocator>;

  explicit GestureRequest_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    target_point(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->gesture_type = 0;
      this->urgency = 0.0f;
    }
  }

  explicit GestureRequest_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    target_point(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->gesture_type = 0;
      this->urgency = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _gesture_type_type =
    uint8_t;
  _gesture_type_type gesture_type;
  using _target_point_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _target_point_type target_point;
  using _urgency_type =
    float;
  _urgency_type urgency;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__gesture_type(
    const uint8_t & _arg)
  {
    this->gesture_type = _arg;
    return *this;
  }
  Type & set__target_point(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->target_point = _arg;
    return *this;
  }
  Type & set__urgency(
    const float & _arg)
  {
    this->urgency = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t GESTURE_NONE =
    0u;
  static constexpr uint8_t GESTURE_READY =
    1u;
  static constexpr uint8_t GESTURE_POINT =
    2u;
  static constexpr uint8_t GESTURE_FREEZE =
    3u;
  static constexpr uint8_t GESTURE_RESET =
    4u;

  // pointer types
  using RawPtr =
    predator_msgs::msg::GestureRequest_<ContainerAllocator> *;
  using ConstRawPtr =
    const predator_msgs::msg::GestureRequest_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<predator_msgs::msg::GestureRequest_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<predator_msgs::msg::GestureRequest_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      predator_msgs::msg::GestureRequest_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<predator_msgs::msg::GestureRequest_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      predator_msgs::msg::GestureRequest_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<predator_msgs::msg::GestureRequest_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<predator_msgs::msg::GestureRequest_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<predator_msgs::msg::GestureRequest_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__predator_msgs__msg__GestureRequest
    std::shared_ptr<predator_msgs::msg::GestureRequest_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__predator_msgs__msg__GestureRequest
    std::shared_ptr<predator_msgs::msg::GestureRequest_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GestureRequest_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->gesture_type != other.gesture_type) {
      return false;
    }
    if (this->target_point != other.target_point) {
      return false;
    }
    if (this->urgency != other.urgency) {
      return false;
    }
    return true;
  }
  bool operator!=(const GestureRequest_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GestureRequest_

// alias to use template instance with default allocator
using GestureRequest =
  predator_msgs::msg::GestureRequest_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t GestureRequest_<ContainerAllocator>::GESTURE_NONE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t GestureRequest_<ContainerAllocator>::GESTURE_READY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t GestureRequest_<ContainerAllocator>::GESTURE_POINT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t GestureRequest_<ContainerAllocator>::GESTURE_FREEZE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t GestureRequest_<ContainerAllocator>::GESTURE_RESET;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace predator_msgs

#endif  // PREDATOR_MSGS__MSG__DETAIL__GESTURE_REQUEST__STRUCT_HPP_
