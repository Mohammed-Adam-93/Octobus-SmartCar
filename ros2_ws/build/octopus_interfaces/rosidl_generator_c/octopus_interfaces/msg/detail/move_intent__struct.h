// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from octopus_interfaces:msg/MoveIntent.idl
// generated code does not contain a copyright notice

#ifndef OCTOPUS_INTERFACES__MSG__DETAIL__MOVE_INTENT__STRUCT_H_
#define OCTOPUS_INTERFACES__MSG__DETAIL__MOVE_INTENT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'permission'
// Member 'direction'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/MoveIntent in the package octopus_interfaces.
typedef struct octopus_interfaces__msg__MoveIntent
{
  rosidl_runtime_c__String permission;
  rosidl_runtime_c__String direction;
  uint8_t speed;
} octopus_interfaces__msg__MoveIntent;

// Struct for a sequence of octopus_interfaces__msg__MoveIntent.
typedef struct octopus_interfaces__msg__MoveIntent__Sequence
{
  octopus_interfaces__msg__MoveIntent * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} octopus_interfaces__msg__MoveIntent__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OCTOPUS_INTERFACES__MSG__DETAIL__MOVE_INTENT__STRUCT_H_
