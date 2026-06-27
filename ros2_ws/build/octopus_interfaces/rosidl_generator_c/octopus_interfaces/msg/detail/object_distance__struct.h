// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from octopus_interfaces:msg/ObjectDistance.idl
// generated code does not contain a copyright notice

#ifndef OCTOPUS_INTERFACES__MSG__DETAIL__OBJECT_DISTANCE__STRUCT_H_
#define OCTOPUS_INTERFACES__MSG__DETAIL__OBJECT_DISTANCE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/ObjectDistance in the package octopus_interfaces.
typedef struct octopus_interfaces__msg__ObjectDistance
{
  float left;
  float middle;
  float right;
} octopus_interfaces__msg__ObjectDistance;

// Struct for a sequence of octopus_interfaces__msg__ObjectDistance.
typedef struct octopus_interfaces__msg__ObjectDistance__Sequence
{
  octopus_interfaces__msg__ObjectDistance * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} octopus_interfaces__msg__ObjectDistance__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OCTOPUS_INTERFACES__MSG__DETAIL__OBJECT_DISTANCE__STRUCT_H_
