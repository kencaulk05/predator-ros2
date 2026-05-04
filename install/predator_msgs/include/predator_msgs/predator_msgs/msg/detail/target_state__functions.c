// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from predator_msgs:msg/TargetState.idl
// generated code does not contain a copyright notice
#include "predator_msgs/msg/detail/target_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `pose`
// Member `predicted_pose`
#include "geometry_msgs/msg/detail/pose_stamped__functions.h"
// Member `velocity`
#include "geometry_msgs/msg/detail/twist_stamped__functions.h"

bool
predator_msgs__msg__TargetState__init(predator_msgs__msg__TargetState * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    predator_msgs__msg__TargetState__fini(msg);
    return false;
  }
  // pose
  if (!geometry_msgs__msg__PoseStamped__init(&msg->pose)) {
    predator_msgs__msg__TargetState__fini(msg);
    return false;
  }
  // velocity
  if (!geometry_msgs__msg__TwistStamped__init(&msg->velocity)) {
    predator_msgs__msg__TargetState__fini(msg);
    return false;
  }
  // predicted_pose
  if (!geometry_msgs__msg__PoseStamped__init(&msg->predicted_pose)) {
    predator_msgs__msg__TargetState__fini(msg);
    return false;
  }
  // confidence
  // is_tracked
  // distance_to_robot
  return true;
}

void
predator_msgs__msg__TargetState__fini(predator_msgs__msg__TargetState * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // pose
  geometry_msgs__msg__PoseStamped__fini(&msg->pose);
  // velocity
  geometry_msgs__msg__TwistStamped__fini(&msg->velocity);
  // predicted_pose
  geometry_msgs__msg__PoseStamped__fini(&msg->predicted_pose);
  // confidence
  // is_tracked
  // distance_to_robot
}

bool
predator_msgs__msg__TargetState__are_equal(const predator_msgs__msg__TargetState * lhs, const predator_msgs__msg__TargetState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__PoseStamped__are_equal(
      &(lhs->pose), &(rhs->pose)))
  {
    return false;
  }
  // velocity
  if (!geometry_msgs__msg__TwistStamped__are_equal(
      &(lhs->velocity), &(rhs->velocity)))
  {
    return false;
  }
  // predicted_pose
  if (!geometry_msgs__msg__PoseStamped__are_equal(
      &(lhs->predicted_pose), &(rhs->predicted_pose)))
  {
    return false;
  }
  // confidence
  if (lhs->confidence != rhs->confidence) {
    return false;
  }
  // is_tracked
  if (lhs->is_tracked != rhs->is_tracked) {
    return false;
  }
  // distance_to_robot
  if (lhs->distance_to_robot != rhs->distance_to_robot) {
    return false;
  }
  return true;
}

bool
predator_msgs__msg__TargetState__copy(
  const predator_msgs__msg__TargetState * input,
  predator_msgs__msg__TargetState * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__PoseStamped__copy(
      &(input->pose), &(output->pose)))
  {
    return false;
  }
  // velocity
  if (!geometry_msgs__msg__TwistStamped__copy(
      &(input->velocity), &(output->velocity)))
  {
    return false;
  }
  // predicted_pose
  if (!geometry_msgs__msg__PoseStamped__copy(
      &(input->predicted_pose), &(output->predicted_pose)))
  {
    return false;
  }
  // confidence
  output->confidence = input->confidence;
  // is_tracked
  output->is_tracked = input->is_tracked;
  // distance_to_robot
  output->distance_to_robot = input->distance_to_robot;
  return true;
}

predator_msgs__msg__TargetState *
predator_msgs__msg__TargetState__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  predator_msgs__msg__TargetState * msg = (predator_msgs__msg__TargetState *)allocator.allocate(sizeof(predator_msgs__msg__TargetState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(predator_msgs__msg__TargetState));
  bool success = predator_msgs__msg__TargetState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
predator_msgs__msg__TargetState__destroy(predator_msgs__msg__TargetState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    predator_msgs__msg__TargetState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
predator_msgs__msg__TargetState__Sequence__init(predator_msgs__msg__TargetState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  predator_msgs__msg__TargetState * data = NULL;

  if (size) {
    data = (predator_msgs__msg__TargetState *)allocator.zero_allocate(size, sizeof(predator_msgs__msg__TargetState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = predator_msgs__msg__TargetState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        predator_msgs__msg__TargetState__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
predator_msgs__msg__TargetState__Sequence__fini(predator_msgs__msg__TargetState__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      predator_msgs__msg__TargetState__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

predator_msgs__msg__TargetState__Sequence *
predator_msgs__msg__TargetState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  predator_msgs__msg__TargetState__Sequence * array = (predator_msgs__msg__TargetState__Sequence *)allocator.allocate(sizeof(predator_msgs__msg__TargetState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = predator_msgs__msg__TargetState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
predator_msgs__msg__TargetState__Sequence__destroy(predator_msgs__msg__TargetState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    predator_msgs__msg__TargetState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
predator_msgs__msg__TargetState__Sequence__are_equal(const predator_msgs__msg__TargetState__Sequence * lhs, const predator_msgs__msg__TargetState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!predator_msgs__msg__TargetState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
predator_msgs__msg__TargetState__Sequence__copy(
  const predator_msgs__msg__TargetState__Sequence * input,
  predator_msgs__msg__TargetState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(predator_msgs__msg__TargetState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    predator_msgs__msg__TargetState * data =
      (predator_msgs__msg__TargetState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!predator_msgs__msg__TargetState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          predator_msgs__msg__TargetState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!predator_msgs__msg__TargetState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
