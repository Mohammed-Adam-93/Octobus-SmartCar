// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from octopus_interfaces:msg/SensorIndex.idl
// generated code does not contain a copyright notice
#include "octopus_interfaces/msg/detail/sensor_index__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `sensor`
#include "rosidl_runtime_c/string_functions.h"

bool
octopus_interfaces__msg__SensorIndex__init(octopus_interfaces__msg__SensorIndex * msg)
{
  if (!msg) {
    return false;
  }
  // sensor
  if (!rosidl_runtime_c__String__init(&msg->sensor)) {
    octopus_interfaces__msg__SensorIndex__fini(msg);
    return false;
  }
  // index
  return true;
}

void
octopus_interfaces__msg__SensorIndex__fini(octopus_interfaces__msg__SensorIndex * msg)
{
  if (!msg) {
    return;
  }
  // sensor
  rosidl_runtime_c__String__fini(&msg->sensor);
  // index
}

bool
octopus_interfaces__msg__SensorIndex__are_equal(const octopus_interfaces__msg__SensorIndex * lhs, const octopus_interfaces__msg__SensorIndex * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // sensor
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->sensor), &(rhs->sensor)))
  {
    return false;
  }
  // index
  if (lhs->index != rhs->index) {
    return false;
  }
  return true;
}

bool
octopus_interfaces__msg__SensorIndex__copy(
  const octopus_interfaces__msg__SensorIndex * input,
  octopus_interfaces__msg__SensorIndex * output)
{
  if (!input || !output) {
    return false;
  }
  // sensor
  if (!rosidl_runtime_c__String__copy(
      &(input->sensor), &(output->sensor)))
  {
    return false;
  }
  // index
  output->index = input->index;
  return true;
}

octopus_interfaces__msg__SensorIndex *
octopus_interfaces__msg__SensorIndex__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  octopus_interfaces__msg__SensorIndex * msg = (octopus_interfaces__msg__SensorIndex *)allocator.allocate(sizeof(octopus_interfaces__msg__SensorIndex), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(octopus_interfaces__msg__SensorIndex));
  bool success = octopus_interfaces__msg__SensorIndex__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
octopus_interfaces__msg__SensorIndex__destroy(octopus_interfaces__msg__SensorIndex * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    octopus_interfaces__msg__SensorIndex__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
octopus_interfaces__msg__SensorIndex__Sequence__init(octopus_interfaces__msg__SensorIndex__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  octopus_interfaces__msg__SensorIndex * data = NULL;

  if (size) {
    data = (octopus_interfaces__msg__SensorIndex *)allocator.zero_allocate(size, sizeof(octopus_interfaces__msg__SensorIndex), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = octopus_interfaces__msg__SensorIndex__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        octopus_interfaces__msg__SensorIndex__fini(&data[i - 1]);
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
octopus_interfaces__msg__SensorIndex__Sequence__fini(octopus_interfaces__msg__SensorIndex__Sequence * array)
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
      octopus_interfaces__msg__SensorIndex__fini(&array->data[i]);
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

octopus_interfaces__msg__SensorIndex__Sequence *
octopus_interfaces__msg__SensorIndex__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  octopus_interfaces__msg__SensorIndex__Sequence * array = (octopus_interfaces__msg__SensorIndex__Sequence *)allocator.allocate(sizeof(octopus_interfaces__msg__SensorIndex__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = octopus_interfaces__msg__SensorIndex__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
octopus_interfaces__msg__SensorIndex__Sequence__destroy(octopus_interfaces__msg__SensorIndex__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    octopus_interfaces__msg__SensorIndex__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
octopus_interfaces__msg__SensorIndex__Sequence__are_equal(const octopus_interfaces__msg__SensorIndex__Sequence * lhs, const octopus_interfaces__msg__SensorIndex__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!octopus_interfaces__msg__SensorIndex__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
octopus_interfaces__msg__SensorIndex__Sequence__copy(
  const octopus_interfaces__msg__SensorIndex__Sequence * input,
  octopus_interfaces__msg__SensorIndex__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(octopus_interfaces__msg__SensorIndex);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    octopus_interfaces__msg__SensorIndex * data =
      (octopus_interfaces__msg__SensorIndex *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!octopus_interfaces__msg__SensorIndex__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          octopus_interfaces__msg__SensorIndex__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!octopus_interfaces__msg__SensorIndex__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
