// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from predator_msgs:msg/ZoneStatus.idl
// generated code does not contain a copyright notice

#include "predator_msgs/msg/detail/zone_status__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_predator_msgs
const rosidl_type_hash_t *
predator_msgs__msg__ZoneStatus__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x02, 0xea, 0xdd, 0x6a, 0x3d, 0x1f, 0x34, 0x71,
      0xde, 0x01, 0x62, 0xb9, 0x0f, 0xd0, 0xce, 0x0d,
      0xc9, 0x12, 0x67, 0x73, 0xaf, 0x6a, 0x19, 0x4a,
      0x6a, 0x24, 0x18, 0xdb, 0xde, 0x73, 0x76, 0xc7,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "geometry_msgs/msg/detail/point__functions.h"
#include "std_msgs/msg/detail/header__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__Point__EXPECTED_HASH = {1, {
    0x69, 0x63, 0x08, 0x48, 0x42, 0xa9, 0xb0, 0x44,
    0x94, 0xd6, 0xb2, 0x94, 0x1d, 0x11, 0x44, 0x47,
    0x08, 0xd8, 0x92, 0xda, 0x2f, 0x4b, 0x09, 0x84,
    0x3b, 0x9c, 0x43, 0xf4, 0x2a, 0x7f, 0x68, 0x81,
  }};
static const rosidl_type_hash_t std_msgs__msg__Header__EXPECTED_HASH = {1, {
    0xf4, 0x9f, 0xb3, 0xae, 0x2c, 0xf0, 0x70, 0xf7,
    0x93, 0x64, 0x5f, 0xf7, 0x49, 0x68, 0x3a, 0xc6,
    0xb0, 0x62, 0x03, 0xe4, 0x1c, 0x89, 0x1e, 0x17,
    0x70, 0x1b, 0x1c, 0xb5, 0x97, 0xce, 0x6a, 0x01,
  }};
#endif

static char predator_msgs__msg__ZoneStatus__TYPE_NAME[] = "predator_msgs/msg/ZoneStatus";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char geometry_msgs__msg__Point__TYPE_NAME[] = "geometry_msgs/msg/Point";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";

// Define type names, field names, and default values
static char predator_msgs__msg__ZoneStatus__FIELD_NAME__header[] = "header";
static char predator_msgs__msg__ZoneStatus__FIELD_NAME__target_in_ur3_zone[] = "target_in_ur3_zone";
static char predator_msgs__msg__ZoneStatus__FIELD_NAME__target_in_safety_zone[] = "target_in_safety_zone";
static char predator_msgs__msg__ZoneStatus__FIELD_NAME__distance_to_zone_center[] = "distance_to_zone_center";
static char predator_msgs__msg__ZoneStatus__FIELD_NAME__zone_radius[] = "zone_radius";
static char predator_msgs__msg__ZoneStatus__FIELD_NAME__zone_center[] = "zone_center";

static rosidl_runtime_c__type_description__Field predator_msgs__msg__ZoneStatus__FIELDS[] = {
  {
    {predator_msgs__msg__ZoneStatus__FIELD_NAME__header, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    },
    {NULL, 0, 0},
  },
  {
    {predator_msgs__msg__ZoneStatus__FIELD_NAME__target_in_ur3_zone, 18, 18},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {predator_msgs__msg__ZoneStatus__FIELD_NAME__target_in_safety_zone, 21, 21},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {predator_msgs__msg__ZoneStatus__FIELD_NAME__distance_to_zone_center, 23, 23},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {predator_msgs__msg__ZoneStatus__FIELD_NAME__zone_radius, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {predator_msgs__msg__ZoneStatus__FIELD_NAME__zone_center, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription predator_msgs__msg__ZoneStatus__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
predator_msgs__msg__ZoneStatus__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {predator_msgs__msg__ZoneStatus__TYPE_NAME, 28, 28},
      {predator_msgs__msg__ZoneStatus__FIELDS, 6, 6},
    },
    {predator_msgs__msg__ZoneStatus__REFERENCED_TYPE_DESCRIPTIONS, 3, 3},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Point__EXPECTED_HASH, geometry_msgs__msg__Point__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = geometry_msgs__msg__Point__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# ZoneStatus.msg\n"
  "# Published by: zone_monitor_node\n"
  "# Consumed by: behavior_manager_node, arm_gesture_node\n"
  "\n"
  "std_msgs/Header header\n"
  "\n"
  "bool target_in_ur3_zone          # True if target is within UR3 interaction region\n"
  "bool target_in_safety_zone       # True if target is within minimum safe distance\n"
  "float32 distance_to_zone_center  # Distance from target to UR3 zone center [m]\n"
  "float32 zone_radius              # Configured radius of the UR3 interaction zone [m]\n"
  "geometry_msgs/Point zone_center  # Center of the UR3 interaction zone in map frame";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
predator_msgs__msg__ZoneStatus__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {predator_msgs__msg__ZoneStatus__TYPE_NAME, 28, 28},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 543, 543},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
predator_msgs__msg__ZoneStatus__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[4];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 4, 4};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *predator_msgs__msg__ZoneStatus__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *geometry_msgs__msg__Point__get_individual_type_description_source(NULL);
    sources[3] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
