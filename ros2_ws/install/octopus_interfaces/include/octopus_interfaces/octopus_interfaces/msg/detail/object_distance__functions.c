// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from octopus_interfaces:msg/ObjectDistance.idl
// generated code does not contain a copyright notice
#include "octopus_interfaces/msg/detail/object_distance__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
octopus_interfaces__msg__ObjectDistance__init(octopus_interfaces__msg__ObjectDistance * msg)
{
  if (!msg) {
    return false;
  }
  // left
  // middle
  // right
  return true;
}

void
octopus_interfaces__msg__ObjectDistance__fini(octopus_interfaces__msg__ObjectDistance * msg)
{
  if (!msg) {
    return;
  }
  // left
  // middle
  // right
}

bool
octopus_interfaces__msg__ObjectDistance__are_equal(const octopus_interfaces__msg__ObjectDistance * lhs, const octopus_interfaces__msg__ObjectDistance * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // left
  if (lhs->left != rhs->left) {
    return false;
  }
  // middle
  if (lhs->middle != rhs->middle) {
    return false;
  }
  // right
  if (lhs->right != rhs->right) {
    return false;
  }
  return true;
}

bool
octopus_interfaces__msg__ObjectDistance__copy(
  const octopus_interfaces__msg__ObjectDistance * input,
  octopus_interfaces__msg__ObjectDistance * output)
{
  if (!input || !output) {
    return false;
  }
  // left
  output->left = input->left;
  // middle
  output->middle = input->middle;
  // right
  output->right = input->right;
  return true;
}

octopus_interfaces__msg__ObjectDistance *
octopus_interfaces__msg__ObjectDistance__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  octopus_interfaces__msg__ObjectDistance * msg = (octopus_interfaces__msg__ObjectDistance *)allocator.allocate(sizeof(octopus_interfaces__msg__ObjectDistance), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(octopus_interfaces__msg__ObjectDistance));
  bool success = octopus_interfaces__msg__ObjectDistance__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
octopus_interfaces__msg__ObjectDistance__destroy(octopus_interfaces__msg__ObjectDistance * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    octopus_interfaces__msg__ObjectDistance__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
octopus_interfaces__msg__ObjectDistance__Sequence__init(octopus_interfaces__msg__ObjectDistance__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  octopus_interfaces__msg__ObjectDistance * data = NULL;

  if (size) {
    data = (octopus_interfaces__msg__ObjectDistance *)allocator.zero_allocate(size, sizeof(octopus_interfaces__msg__ObjectDistance), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = octopus_interfaces__msg__ObjectDistance__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        octopus_interfaces__msg__ObjectDistance__fini(&data[i - 1]);
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
octopus_interfaces__msg__ObjectDistance__Sequence__fini(octopus_interfaces__msg__ObjectDistance__Sequence * array)
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
      octopus_interfaces__msg__ObjectDistance__fini(&array->data[i]);
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

octopus_interfaces__msg__ObjectDistance__Sequence *
octopus_interfaces__msg__ObjectDistance__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  octopus_interfaces__msg__ObjectDistance__Sequence * array = (octopus_interfaces__msg__ObjectDistance__Sequence *)allocator.allocate(sizeof(octopus_interfaces__msg__ObjectDistance__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = octopus_interfaces__msg__ObjectDistance__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
octopus_interfaces__msg__ObjectDistance__Sequence__destroy(octopus_interfaces__msg__ObjectDistance__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    octopus_interfaces__msg__ObjectDistance__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
octopus_interfaces__msg__ObjectDistance__Sequence__are_equal(const octopus_interfaces__msg__ObjectDistance__Sequence * lhs, const octopus_interfaces__msg__ObjectDistance__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!octopus_interfaces__msg__ObjectDistance__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
octopus_interfaces__msg__ObjectDistance__Sequence__copy(
  const octopus_interfaces__msg__ObjectDistance__Sequence * input,
  octopus_interfaces__msg__ObjectDistance__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(octopus_interfaces__msg__ObjectDistance);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    octopus_interfaces__msg__ObjectDistance * data =
      (octopus_interfaces__msg__ObjectDistance *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!octopus_interfaces__msg__ObjectDistance__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          octopus_interfaces__msg__ObjectDistance__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!octopus_interfaces__msg__ObjectDistance__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
