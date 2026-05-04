// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from predator_msgs:msg/BehaviorState.idl
// generated code does not contain a copyright notice

#include "predator_msgs/msg/detail/behavior_state__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_predator_msgs
const rosidl_type_hash_t *
predator_msgs__msg__BehaviorState__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x3b, 0x2a, 0x2f, 0x9a, 0x13, 0xff, 0xb0, 0x85,
      0x0e, 0xc2, 0x6d, 0x4f, 0xc4, 0xc2, 0xde, 0xee,
      0xaf, 0xe3, 0x96, 0x70, 0xf7, 0x3c, 0x67, 0x8a,
      0xe0, 0x82, 0x53, 0xc7, 0x18, 0xec, 0x7b, 0x9b,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "std_msgs/msg/detail/header__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t std_msgs__msg__Header__EXPECTED_HASH = {1, {
    0xf4, 0x9f, 0xb3, 0xae, 0x2c, 0xf0, 0x70, 0xf7,
    0x93, 0x64, 0x5f, 0xf7, 0x49, 0x68, 0x3a, 0xc6,
    0xb0, 0x62, 0x03, 0xe4, 0x1c, 0x89, 0x1e, 0x17,
    0x70, 0x1b, 0x1c, 0xb5, 0x97, 0xce, 0x6a, 0x01,
  }};
#endif

static char predator_msgs__msg__BehaviorState__TYPE_NAME[] = "predator_msgs/msg/BehaviorState";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";

// Define type names, field names, and default values
static char predator_msgs__msg__BehaviorState__FIELD_NAME__header[] = "header";
static char predator_msgs__msg__BehaviorState__FIELD_NAME__state[] = "state";
static char predator_msgs__msg__BehaviorState__FIELD_NAME__state_label[] = "state_label";
static char predator_msgs__msg__BehaviorState__FIELD_NAME__time_in_state[] = "time_in_state";
static char predator_msgs__msg__BehaviorState__FIELD_NAME__transition_reason[] = "transition_reason";

static rosidl_runtime_c__type_description__Field predator_msgs__msg__BehaviorState__FIELDS[] = {
  {
    {predator_msgs__msg__BehaviorState__FIELD_NAME__header, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    },
    {NULL, 0, 0},
  },
  {
    {predator_msgs__msg__BehaviorState__FIELD_NAME__state, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {predator_msgs__msg__BehaviorState__FIELD_NAME__state_label, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {predator_msgs__msg__BehaviorState__FIELD_NAME__time_in_state, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {predator_msgs__msg__BehaviorState__FIELD_NAME__transition_reason, 17, 17},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription predator_msgs__msg__BehaviorState__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
predator_msgs__msg__BehaviorState__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {predator_msgs__msg__BehaviorState__TYPE_NAME, 31, 31},
      {predator_msgs__msg__BehaviorState__FIELDS, 5, 5},
    },
    {predator_msgs__msg__BehaviorState__REFERENCED_TYPE_DESCRIPTIONS, 2, 2},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# BehaviorState.msg\n"
  "# Published by: behavior_manager_node\n"
  "# Consumed by: pursuit_planner_node, arm_gesture_node, safety_supervisor_node\n"
  "\n"
  "std_msgs/Header header\n"
  "\n"
  "# State enum constants\n"
  "uint8 SEARCH       = 0\n"
  "uint8 ACQUIRE      = 1\n"
  "uint8 PURSUIT      = 2\n"
  "uint8 HERD         = 3\n"
  "uint8 ARM_ALERT    = 4\n"
  "uint8 SAFETY_STOP  = 5\n"
  "uint8 REACQUIRE    = 6\n"
  "\n"
  "uint8 state                  # Current behavior state (use constants above)\n"
  "string state_label           # Human-readable state name for debugging\n"
  "float32 time_in_state        # Seconds spent in current state\n"
  "string transition_reason     # Why the last state transition occurred";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
predator_msgs__msg__BehaviorState__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {predator_msgs__msg__BehaviorState__TYPE_NAME, 31, 31},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 625, 625},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
predator_msgs__msg__BehaviorState__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[3];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 3, 3};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *predator_msgs__msg__BehaviorState__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
