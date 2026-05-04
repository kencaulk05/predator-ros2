// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from predator_msgs:msg/BehaviorState.idl
// generated code does not contain a copyright notice
#include "predator_msgs/msg/detail/behavior_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `state_label`
// Member `transition_reason`
#include "rosidl_runtime_c/string_functions.h"

bool
predator_msgs__msg__BehaviorState__init(predator_msgs__msg__BehaviorState * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    predator_msgs__msg__BehaviorState__fini(msg);
    return false;
  }
  // state
  // state_label
  if (!rosidl_runtime_c__String__init(&msg->state_label)) {
    predator_msgs__msg__BehaviorState__fini(msg);
    return false;
  }
  // time_in_state
  // transition_reason
  if (!rosidl_runtime_c__String__init(&msg->transition_reason)) {
    predator_msgs__msg__BehaviorState__fini(msg);
    return false;
  }
  return true;
}

void
predator_msgs__msg__BehaviorState__fini(predator_msgs__msg__BehaviorState * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // state
  // state_label
  rosidl_runtime_c__String__fini(&msg->state_label);
  // time_in_state
  // transition_reason
  rosidl_runtime_c__String__fini(&msg->transition_reason);
}

bool
predator_msgs__msg__BehaviorState__are_equal(const predator_msgs__msg__BehaviorState * lhs, const predator_msgs__msg__BehaviorState * rhs)
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
  // state
  if (lhs->state != rhs->state) {
    return false;
  }
  // state_label
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->state_label), &(rhs->state_label)))
  {
    return false;
  }
  // time_in_state
  if (lhs->time_in_state != rhs->time_in_state) {
    return false;
  }
  // transition_reason
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->transition_reason), &(rhs->transition_reason)))
  {
    return false;
  }
  return true;
}

bool
predator_msgs__msg__BehaviorState__copy(
  const predator_msgs__msg__BehaviorState * input,
  predator_msgs__msg__BehaviorState * output)
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
  // state
  output->state = input->state;
  // state_label
  if (!rosidl_runtime_c__String__copy(
      &(input->state_label), &(output->state_label)))
  {
    return false;
  }
  // time_in_state
  output->time_in_state = input->time_in_state;
  // transition_reason
  if (!rosidl_runtime_c__String__copy(
      &(input->transition_reason), &(output->transition_reason)))
  {
    return false;
  }
  return true;
}

predator_msgs__msg__BehaviorState *
predator_msgs__msg__BehaviorState__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  predator_msgs__msg__BehaviorState * msg = (predator_msgs__msg__BehaviorState *)allocator.allocate(sizeof(predator_msgs__msg__BehaviorState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(predator_msgs__msg__BehaviorState));
  bool success = predator_msgs__msg__BehaviorState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
predator_msgs__msg__BehaviorState__destroy(predator_msgs__msg__BehaviorState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    predator_msgs__msg__BehaviorState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
predator_msgs__msg__BehaviorState__Sequence__init(predator_msgs__msg__BehaviorState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  predator_msgs__msg__BehaviorState * data = NULL;

  if (size) {
    data = (predator_msgs__msg__BehaviorState *)allocator.zero_allocate(size, sizeof(predator_msgs__msg__BehaviorState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = predator_msgs__msg__BehaviorState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        predator_msgs__msg__BehaviorState__fini(&data[i - 1]);
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
predator_msgs__msg__BehaviorState__Sequence__fini(predator_msgs__msg__BehaviorState__Sequence * array)
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
      predator_msgs__msg__BehaviorState__fini(&array->data[i]);
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

predator_msgs__msg__BehaviorState__Sequence *
predator_msgs__msg__BehaviorState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  predator_msgs__msg__BehaviorState__Sequence * array = (predator_msgs__msg__BehaviorState__Sequence *)allocator.allocate(sizeof(predator_msgs__msg__BehaviorState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = predator_msgs__msg__BehaviorState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
predator_msgs__msg__BehaviorState__Sequence__destroy(predator_msgs__msg__BehaviorState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    predator_msgs__msg__BehaviorState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
predator_msgs__msg__BehaviorState__Sequence__are_equal(const predator_msgs__msg__BehaviorState__Sequence * lhs, const predator_msgs__msg__BehaviorState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!predator_msgs__msg__BehaviorState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
predator_msgs__msg__BehaviorState__Sequence__copy(
  const predator_msgs__msg__BehaviorState__Sequence * input,
  predator_msgs__msg__BehaviorState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(predator_msgs__msg__BehaviorState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    predator_msgs__msg__BehaviorState * data =
      (predator_msgs__msg__BehaviorState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!predator_msgs__msg__BehaviorState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          predator_msgs__msg__BehaviorState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!predator_msgs__msg__BehaviorState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
