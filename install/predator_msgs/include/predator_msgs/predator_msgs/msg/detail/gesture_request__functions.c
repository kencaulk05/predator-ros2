// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from predator_msgs:msg/GestureRequest.idl
// generated code does not contain a copyright notice
#include "predator_msgs/msg/detail/gesture_request__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `target_point`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
predator_msgs__msg__GestureRequest__init(predator_msgs__msg__GestureRequest * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    predator_msgs__msg__GestureRequest__fini(msg);
    return false;
  }
  // gesture_type
  // target_point
  if (!geometry_msgs__msg__Point__init(&msg->target_point)) {
    predator_msgs__msg__GestureRequest__fini(msg);
    return false;
  }
  // urgency
  return true;
}

void
predator_msgs__msg__GestureRequest__fini(predator_msgs__msg__GestureRequest * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // gesture_type
  // target_point
  geometry_msgs__msg__Point__fini(&msg->target_point);
  // urgency
}

bool
predator_msgs__msg__GestureRequest__are_equal(const predator_msgs__msg__GestureRequest * lhs, const predator_msgs__msg__GestureRequest * rhs)
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
  // gesture_type
  if (lhs->gesture_type != rhs->gesture_type) {
    return false;
  }
  // target_point
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->target_point), &(rhs->target_point)))
  {
    return false;
  }
  // urgency
  if (lhs->urgency != rhs->urgency) {
    return false;
  }
  return true;
}

bool
predator_msgs__msg__GestureRequest__copy(
  const predator_msgs__msg__GestureRequest * input,
  predator_msgs__msg__GestureRequest * output)
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
  // gesture_type
  output->gesture_type = input->gesture_type;
  // target_point
  if (!geometry_msgs__msg__Point__copy(
      &(input->target_point), &(output->target_point)))
  {
    return false;
  }
  // urgency
  output->urgency = input->urgency;
  return true;
}

predator_msgs__msg__GestureRequest *
predator_msgs__msg__GestureRequest__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  predator_msgs__msg__GestureRequest * msg = (predator_msgs__msg__GestureRequest *)allocator.allocate(sizeof(predator_msgs__msg__GestureRequest), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(predator_msgs__msg__GestureRequest));
  bool success = predator_msgs__msg__GestureRequest__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
predator_msgs__msg__GestureRequest__destroy(predator_msgs__msg__GestureRequest * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    predator_msgs__msg__GestureRequest__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
predator_msgs__msg__GestureRequest__Sequence__init(predator_msgs__msg__GestureRequest__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  predator_msgs__msg__GestureRequest * data = NULL;

  if (size) {
    data = (predator_msgs__msg__GestureRequest *)allocator.zero_allocate(size, sizeof(predator_msgs__msg__GestureRequest), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = predator_msgs__msg__GestureRequest__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        predator_msgs__msg__GestureRequest__fini(&data[i - 1]);
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
predator_msgs__msg__GestureRequest__Sequence__fini(predator_msgs__msg__GestureRequest__Sequence * array)
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
      predator_msgs__msg__GestureRequest__fini(&array->data[i]);
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

predator_msgs__msg__GestureRequest__Sequence *
predator_msgs__msg__GestureRequest__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  predator_msgs__msg__GestureRequest__Sequence * array = (predator_msgs__msg__GestureRequest__Sequence *)allocator.allocate(sizeof(predator_msgs__msg__GestureRequest__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = predator_msgs__msg__GestureRequest__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
predator_msgs__msg__GestureRequest__Sequence__destroy(predator_msgs__msg__GestureRequest__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    predator_msgs__msg__GestureRequest__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
predator_msgs__msg__GestureRequest__Sequence__are_equal(const predator_msgs__msg__GestureRequest__Sequence * lhs, const predator_msgs__msg__GestureRequest__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!predator_msgs__msg__GestureRequest__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
predator_msgs__msg__GestureRequest__Sequence__copy(
  const predator_msgs__msg__GestureRequest__Sequence * input,
  predator_msgs__msg__GestureRequest__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(predator_msgs__msg__GestureRequest);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    predator_msgs__msg__GestureRequest * data =
      (predator_msgs__msg__GestureRequest *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!predator_msgs__msg__GestureRequest__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          predator_msgs__msg__GestureRequest__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!predator_msgs__msg__GestureRequest__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
