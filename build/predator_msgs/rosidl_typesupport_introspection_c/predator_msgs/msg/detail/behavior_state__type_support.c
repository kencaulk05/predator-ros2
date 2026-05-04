// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from predator_msgs:msg/BehaviorState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "predator_msgs/msg/detail/behavior_state__rosidl_typesupport_introspection_c.h"
#include "predator_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "predator_msgs/msg/detail/behavior_state__functions.h"
#include "predator_msgs/msg/detail/behavior_state__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `state_label`
// Member `transition_reason`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void predator_msgs__msg__BehaviorState__rosidl_typesupport_introspection_c__BehaviorState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  predator_msgs__msg__BehaviorState__init(message_memory);
}

void predator_msgs__msg__BehaviorState__rosidl_typesupport_introspection_c__BehaviorState_fini_function(void * message_memory)
{
  predator_msgs__msg__BehaviorState__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember predator_msgs__msg__BehaviorState__rosidl_typesupport_introspection_c__BehaviorState_message_member_array[5] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(predator_msgs__msg__BehaviorState, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(predator_msgs__msg__BehaviorState, state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "state_label",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(predator_msgs__msg__BehaviorState, state_label),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "time_in_state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(predator_msgs__msg__BehaviorState, time_in_state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "transition_reason",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(predator_msgs__msg__BehaviorState, transition_reason),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers predator_msgs__msg__BehaviorState__rosidl_typesupport_introspection_c__BehaviorState_message_members = {
  "predator_msgs__msg",  // message namespace
  "BehaviorState",  // message name
  5,  // number of fields
  sizeof(predator_msgs__msg__BehaviorState),
  false,  // has_any_key_member_
  predator_msgs__msg__BehaviorState__rosidl_typesupport_introspection_c__BehaviorState_message_member_array,  // message members
  predator_msgs__msg__BehaviorState__rosidl_typesupport_introspection_c__BehaviorState_init_function,  // function to initialize message memory (memory has to be allocated)
  predator_msgs__msg__BehaviorState__rosidl_typesupport_introspection_c__BehaviorState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t predator_msgs__msg__BehaviorState__rosidl_typesupport_introspection_c__BehaviorState_message_type_support_handle = {
  0,
  &predator_msgs__msg__BehaviorState__rosidl_typesupport_introspection_c__BehaviorState_message_members,
  get_message_typesupport_handle_function,
  &predator_msgs__msg__BehaviorState__get_type_hash,
  &predator_msgs__msg__BehaviorState__get_type_description,
  &predator_msgs__msg__BehaviorState__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_predator_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, predator_msgs, msg, BehaviorState)() {
  predator_msgs__msg__BehaviorState__rosidl_typesupport_introspection_c__BehaviorState_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!predator_msgs__msg__BehaviorState__rosidl_typesupport_introspection_c__BehaviorState_message_type_support_handle.typesupport_identifier) {
    predator_msgs__msg__BehaviorState__rosidl_typesupport_introspection_c__BehaviorState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &predator_msgs__msg__BehaviorState__rosidl_typesupport_introspection_c__BehaviorState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
