// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from predator_msgs:msg/ZoneStatus.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "predator_msgs/msg/detail/zone_status__rosidl_typesupport_introspection_c.h"
#include "predator_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "predator_msgs/msg/detail/zone_status__functions.h"
#include "predator_msgs/msg/detail/zone_status__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `zone_center`
#include "geometry_msgs/msg/point.h"
// Member `zone_center`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void predator_msgs__msg__ZoneStatus__rosidl_typesupport_introspection_c__ZoneStatus_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  predator_msgs__msg__ZoneStatus__init(message_memory);
}

void predator_msgs__msg__ZoneStatus__rosidl_typesupport_introspection_c__ZoneStatus_fini_function(void * message_memory)
{
  predator_msgs__msg__ZoneStatus__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember predator_msgs__msg__ZoneStatus__rosidl_typesupport_introspection_c__ZoneStatus_message_member_array[6] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(predator_msgs__msg__ZoneStatus, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "target_in_ur3_zone",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(predator_msgs__msg__ZoneStatus, target_in_ur3_zone),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "target_in_safety_zone",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(predator_msgs__msg__ZoneStatus, target_in_safety_zone),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "distance_to_zone_center",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(predator_msgs__msg__ZoneStatus, distance_to_zone_center),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "zone_radius",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(predator_msgs__msg__ZoneStatus, zone_radius),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "zone_center",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(predator_msgs__msg__ZoneStatus, zone_center),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers predator_msgs__msg__ZoneStatus__rosidl_typesupport_introspection_c__ZoneStatus_message_members = {
  "predator_msgs__msg",  // message namespace
  "ZoneStatus",  // message name
  6,  // number of fields
  sizeof(predator_msgs__msg__ZoneStatus),
  false,  // has_any_key_member_
  predator_msgs__msg__ZoneStatus__rosidl_typesupport_introspection_c__ZoneStatus_message_member_array,  // message members
  predator_msgs__msg__ZoneStatus__rosidl_typesupport_introspection_c__ZoneStatus_init_function,  // function to initialize message memory (memory has to be allocated)
  predator_msgs__msg__ZoneStatus__rosidl_typesupport_introspection_c__ZoneStatus_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t predator_msgs__msg__ZoneStatus__rosidl_typesupport_introspection_c__ZoneStatus_message_type_support_handle = {
  0,
  &predator_msgs__msg__ZoneStatus__rosidl_typesupport_introspection_c__ZoneStatus_message_members,
  get_message_typesupport_handle_function,
  &predator_msgs__msg__ZoneStatus__get_type_hash,
  &predator_msgs__msg__ZoneStatus__get_type_description,
  &predator_msgs__msg__ZoneStatus__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_predator_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, predator_msgs, msg, ZoneStatus)() {
  predator_msgs__msg__ZoneStatus__rosidl_typesupport_introspection_c__ZoneStatus_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  predator_msgs__msg__ZoneStatus__rosidl_typesupport_introspection_c__ZoneStatus_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!predator_msgs__msg__ZoneStatus__rosidl_typesupport_introspection_c__ZoneStatus_message_type_support_handle.typesupport_identifier) {
    predator_msgs__msg__ZoneStatus__rosidl_typesupport_introspection_c__ZoneStatus_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &predator_msgs__msg__ZoneStatus__rosidl_typesupport_introspection_c__ZoneStatus_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
