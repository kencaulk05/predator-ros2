// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from predator_msgs:msg/TargetState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "predator_msgs/msg/target_state.hpp"


#ifndef PREDATOR_MSGS__MSG__DETAIL__TARGET_STATE__STRUCT_HPP_
#define PREDATOR_MSGS__MSG__DETAIL__TARGET_STATE__STRUCT_HPP_

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
// Member 'pose'
// Member 'predicted_pose'
#include "geometry_msgs/msg/detail/pose_stamped__struct.hpp"
// Member 'velocity'
#include "geometry_msgs/msg/detail/twist_stamped__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__predator_msgs__msg__TargetState __attribute__((deprecated))
#else
# define DEPRECATED__predator_msgs__msg__TargetState __declspec(deprecated)
#endif

namespace predator_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TargetState_
{
  using Type = TargetState_<ContainerAllocator>;

  explicit TargetState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    pose(_init),
    velocity(_init),
    predicted_pose(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->confidence = 0.0f;
      this->is_tracked = false;
      this->distance_to_robot = 0.0f;
    }
  }

  explicit TargetState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    pose(_alloc, _init),
    velocity(_alloc, _init),
    predicted_pose(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->confidence = 0.0f;
      this->is_tracked = false;
      this->distance_to_robot = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _pose_type =
    geometry_msgs::msg::PoseStamped_<ContainerAllocator>;
  _pose_type pose;
  using _velocity_type =
    geometry_msgs::msg::TwistStamped_<ContainerAllocator>;
  _velocity_type velocity;
  using _predicted_pose_type =
    geometry_msgs::msg::PoseStamped_<ContainerAllocator>;
  _predicted_pose_type predicted_pose;
  using _confidence_type =
    float;
  _confidence_type confidence;
  using _is_tracked_type =
    bool;
  _is_tracked_type is_tracked;
  using _distance_to_robot_type =
    float;
  _distance_to_robot_type distance_to_robot;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__pose(
    const geometry_msgs::msg::PoseStamped_<ContainerAllocator> & _arg)
  {
    this->pose = _arg;
    return *this;
  }
  Type & set__velocity(
    const geometry_msgs::msg::TwistStamped_<ContainerAllocator> & _arg)
  {
    this->velocity = _arg;
    return *this;
  }
  Type & set__predicted_pose(
    const geometry_msgs::msg::PoseStamped_<ContainerAllocator> & _arg)
  {
    this->predicted_pose = _arg;
    return *this;
  }
  Type & set__confidence(
    const float & _arg)
  {
    this->confidence = _arg;
    return *this;
  }
  Type & set__is_tracked(
    const bool & _arg)
  {
    this->is_tracked = _arg;
    return *this;
  }
  Type & set__distance_to_robot(
    const float & _arg)
  {
    this->distance_to_robot = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    predator_msgs::msg::TargetState_<ContainerAllocator> *;
  using ConstRawPtr =
    const predator_msgs::msg::TargetState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<predator_msgs::msg::TargetState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<predator_msgs::msg::TargetState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      predator_msgs::msg::TargetState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<predator_msgs::msg::TargetState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      predator_msgs::msg::TargetState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<predator_msgs::msg::TargetState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<predator_msgs::msg::TargetState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<predator_msgs::msg::TargetState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__predator_msgs__msg__TargetState
    std::shared_ptr<predator_msgs::msg::TargetState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__predator_msgs__msg__TargetState
    std::shared_ptr<predator_msgs::msg::TargetState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TargetState_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->pose != other.pose) {
      return false;
    }
    if (this->velocity != other.velocity) {
      return false;
    }
    if (this->predicted_pose != other.predicted_pose) {
      return false;
    }
    if (this->confidence != other.confidence) {
      return false;
    }
    if (this->is_tracked != other.is_tracked) {
      return false;
    }
    if (this->distance_to_robot != other.distance_to_robot) {
      return false;
    }
    return true;
  }
  bool operator!=(const TargetState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TargetState_

// alias to use template instance with default allocator
using TargetState =
  predator_msgs::msg::TargetState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace predator_msgs

#endif  // PREDATOR_MSGS__MSG__DETAIL__TARGET_STATE__STRUCT_HPP_
