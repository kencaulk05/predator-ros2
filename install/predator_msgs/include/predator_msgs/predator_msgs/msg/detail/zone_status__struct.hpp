// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from predator_msgs:msg/ZoneStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "predator_msgs/msg/zone_status.hpp"


#ifndef PREDATOR_MSGS__MSG__DETAIL__ZONE_STATUS__STRUCT_HPP_
#define PREDATOR_MSGS__MSG__DETAIL__ZONE_STATUS__STRUCT_HPP_

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
// Member 'zone_center'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__predator_msgs__msg__ZoneStatus __attribute__((deprecated))
#else
# define DEPRECATED__predator_msgs__msg__ZoneStatus __declspec(deprecated)
#endif

namespace predator_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ZoneStatus_
{
  using Type = ZoneStatus_<ContainerAllocator>;

  explicit ZoneStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    zone_center(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->target_in_ur3_zone = false;
      this->target_in_safety_zone = false;
      this->distance_to_zone_center = 0.0f;
      this->zone_radius = 0.0f;
    }
  }

  explicit ZoneStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    zone_center(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->target_in_ur3_zone = false;
      this->target_in_safety_zone = false;
      this->distance_to_zone_center = 0.0f;
      this->zone_radius = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _target_in_ur3_zone_type =
    bool;
  _target_in_ur3_zone_type target_in_ur3_zone;
  using _target_in_safety_zone_type =
    bool;
  _target_in_safety_zone_type target_in_safety_zone;
  using _distance_to_zone_center_type =
    float;
  _distance_to_zone_center_type distance_to_zone_center;
  using _zone_radius_type =
    float;
  _zone_radius_type zone_radius;
  using _zone_center_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _zone_center_type zone_center;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__target_in_ur3_zone(
    const bool & _arg)
  {
    this->target_in_ur3_zone = _arg;
    return *this;
  }
  Type & set__target_in_safety_zone(
    const bool & _arg)
  {
    this->target_in_safety_zone = _arg;
    return *this;
  }
  Type & set__distance_to_zone_center(
    const float & _arg)
  {
    this->distance_to_zone_center = _arg;
    return *this;
  }
  Type & set__zone_radius(
    const float & _arg)
  {
    this->zone_radius = _arg;
    return *this;
  }
  Type & set__zone_center(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->zone_center = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    predator_msgs::msg::ZoneStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const predator_msgs::msg::ZoneStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<predator_msgs::msg::ZoneStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<predator_msgs::msg::ZoneStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      predator_msgs::msg::ZoneStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<predator_msgs::msg::ZoneStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      predator_msgs::msg::ZoneStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<predator_msgs::msg::ZoneStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<predator_msgs::msg::ZoneStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<predator_msgs::msg::ZoneStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__predator_msgs__msg__ZoneStatus
    std::shared_ptr<predator_msgs::msg::ZoneStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__predator_msgs__msg__ZoneStatus
    std::shared_ptr<predator_msgs::msg::ZoneStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ZoneStatus_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->target_in_ur3_zone != other.target_in_ur3_zone) {
      return false;
    }
    if (this->target_in_safety_zone != other.target_in_safety_zone) {
      return false;
    }
    if (this->distance_to_zone_center != other.distance_to_zone_center) {
      return false;
    }
    if (this->zone_radius != other.zone_radius) {
      return false;
    }
    if (this->zone_center != other.zone_center) {
      return false;
    }
    return true;
  }
  bool operator!=(const ZoneStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ZoneStatus_

// alias to use template instance with default allocator
using ZoneStatus =
  predator_msgs::msg::ZoneStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace predator_msgs

#endif  // PREDATOR_MSGS__MSG__DETAIL__ZONE_STATUS__STRUCT_HPP_
