// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from predator_msgs:msg/BehaviorState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "predator_msgs/msg/behavior_state.hpp"


#ifndef PREDATOR_MSGS__MSG__DETAIL__BEHAVIOR_STATE__STRUCT_HPP_
#define PREDATOR_MSGS__MSG__DETAIL__BEHAVIOR_STATE__STRUCT_HPP_

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

#ifndef _WIN32
# define DEPRECATED__predator_msgs__msg__BehaviorState __attribute__((deprecated))
#else
# define DEPRECATED__predator_msgs__msg__BehaviorState __declspec(deprecated)
#endif

namespace predator_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BehaviorState_
{
  using Type = BehaviorState_<ContainerAllocator>;

  explicit BehaviorState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = 0;
      this->state_label = "";
      this->time_in_state = 0.0f;
      this->transition_reason = "";
    }
  }

  explicit BehaviorState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    state_label(_alloc),
    transition_reason(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = 0;
      this->state_label = "";
      this->time_in_state = 0.0f;
      this->transition_reason = "";
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _state_type =
    uint8_t;
  _state_type state;
  using _state_label_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _state_label_type state_label;
  using _time_in_state_type =
    float;
  _time_in_state_type time_in_state;
  using _transition_reason_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _transition_reason_type transition_reason;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__state(
    const uint8_t & _arg)
  {
    this->state = _arg;
    return *this;
  }
  Type & set__state_label(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->state_label = _arg;
    return *this;
  }
  Type & set__time_in_state(
    const float & _arg)
  {
    this->time_in_state = _arg;
    return *this;
  }
  Type & set__transition_reason(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->transition_reason = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t SEARCH =
    0u;
  static constexpr uint8_t ACQUIRE =
    1u;
  static constexpr uint8_t PURSUIT =
    2u;
  static constexpr uint8_t HERD =
    3u;
  static constexpr uint8_t ARM_ALERT =
    4u;
  static constexpr uint8_t SAFETY_STOP =
    5u;
  static constexpr uint8_t REACQUIRE =
    6u;

  // pointer types
  using RawPtr =
    predator_msgs::msg::BehaviorState_<ContainerAllocator> *;
  using ConstRawPtr =
    const predator_msgs::msg::BehaviorState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<predator_msgs::msg::BehaviorState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<predator_msgs::msg::BehaviorState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      predator_msgs::msg::BehaviorState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<predator_msgs::msg::BehaviorState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      predator_msgs::msg::BehaviorState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<predator_msgs::msg::BehaviorState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<predator_msgs::msg::BehaviorState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<predator_msgs::msg::BehaviorState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__predator_msgs__msg__BehaviorState
    std::shared_ptr<predator_msgs::msg::BehaviorState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__predator_msgs__msg__BehaviorState
    std::shared_ptr<predator_msgs::msg::BehaviorState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BehaviorState_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->state != other.state) {
      return false;
    }
    if (this->state_label != other.state_label) {
      return false;
    }
    if (this->time_in_state != other.time_in_state) {
      return false;
    }
    if (this->transition_reason != other.transition_reason) {
      return false;
    }
    return true;
  }
  bool operator!=(const BehaviorState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BehaviorState_

// alias to use template instance with default allocator
using BehaviorState =
  predator_msgs::msg::BehaviorState_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BehaviorState_<ContainerAllocator>::SEARCH;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BehaviorState_<ContainerAllocator>::ACQUIRE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BehaviorState_<ContainerAllocator>::PURSUIT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BehaviorState_<ContainerAllocator>::HERD;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BehaviorState_<ContainerAllocator>::ARM_ALERT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BehaviorState_<ContainerAllocator>::SAFETY_STOP;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BehaviorState_<ContainerAllocator>::REACQUIRE;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace predator_msgs

#endif  // PREDATOR_MSGS__MSG__DETAIL__BEHAVIOR_STATE__STRUCT_HPP_
