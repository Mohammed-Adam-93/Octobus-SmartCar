// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from octopus_interfaces:msg/SensorIndex.idl
// generated code does not contain a copyright notice

#ifndef OCTOPUS_INTERFACES__MSG__DETAIL__SENSOR_INDEX__STRUCT_H_
#define OCTOPUS_INTERFACES__MSG__DETAIL__SENSOR_INDEX__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'sensor'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/SensorIndex in the package octopus_interfaces.
typedef struct octopus_interfaces__msg__SensorIndex
{
  rosidl_runtime_c__String sensor;
  int8_t index;
} octopus_interfaces__msg__SensorIndex;

// Struct for a sequence of octopus_interfaces__msg__SensorIndex.
typedef struct octopus_interfaces__msg__SensorIndex__Sequence
{
  octopus_interfaces__msg__SensorIndex * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} octopus_interfaces__msg__SensorIndex__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OCTOPUS_INTERFACES__MSG__DETAIL__SENSOR_INDEX__STRUCT_H_
