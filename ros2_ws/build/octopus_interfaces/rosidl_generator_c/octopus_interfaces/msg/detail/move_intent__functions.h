// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from octopus_interfaces:msg/MoveIntent.idl
// generated code does not contain a copyright notice

#ifndef OCTOPUS_INTERFACES__MSG__DETAIL__MOVE_INTENT__FUNCTIONS_H_
#define OCTOPUS_INTERFACES__MSG__DETAIL__MOVE_INTENT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "octopus_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "octopus_interfaces/msg/detail/move_intent__struct.h"

/// Initialize msg/MoveIntent message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * octopus_interfaces__msg__MoveIntent
 * )) before or use
 * octopus_interfaces__msg__MoveIntent__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_octopus_interfaces
bool
octopus_interfaces__msg__MoveIntent__init(octopus_interfaces__msg__MoveIntent * msg);

/// Finalize msg/MoveIntent message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_octopus_interfaces
void
octopus_interfaces__msg__MoveIntent__fini(octopus_interfaces__msg__MoveIntent * msg);

/// Create msg/MoveIntent message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * octopus_interfaces__msg__MoveIntent__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_octopus_interfaces
octopus_interfaces__msg__MoveIntent *
octopus_interfaces__msg__MoveIntent__create();

/// Destroy msg/MoveIntent message.
/**
 * It calls
 * octopus_interfaces__msg__MoveIntent__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_octopus_interfaces
void
octopus_interfaces__msg__MoveIntent__destroy(octopus_interfaces__msg__MoveIntent * msg);

/// Check for msg/MoveIntent message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_octopus_interfaces
bool
octopus_interfaces__msg__MoveIntent__are_equal(const octopus_interfaces__msg__MoveIntent * lhs, const octopus_interfaces__msg__MoveIntent * rhs);

/// Copy a msg/MoveIntent message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_octopus_interfaces
bool
octopus_interfaces__msg__MoveIntent__copy(
  const octopus_interfaces__msg__MoveIntent * input,
  octopus_interfaces__msg__MoveIntent * output);

/// Initialize array of msg/MoveIntent messages.
/**
 * It allocates the memory for the number of elements and calls
 * octopus_interfaces__msg__MoveIntent__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_octopus_interfaces
bool
octopus_interfaces__msg__MoveIntent__Sequence__init(octopus_interfaces__msg__MoveIntent__Sequence * array, size_t size);

/// Finalize array of msg/MoveIntent messages.
/**
 * It calls
 * octopus_interfaces__msg__MoveIntent__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_octopus_interfaces
void
octopus_interfaces__msg__MoveIntent__Sequence__fini(octopus_interfaces__msg__MoveIntent__Sequence * array);

/// Create array of msg/MoveIntent messages.
/**
 * It allocates the memory for the array and calls
 * octopus_interfaces__msg__MoveIntent__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_octopus_interfaces
octopus_interfaces__msg__MoveIntent__Sequence *
octopus_interfaces__msg__MoveIntent__Sequence__create(size_t size);

/// Destroy array of msg/MoveIntent messages.
/**
 * It calls
 * octopus_interfaces__msg__MoveIntent__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_octopus_interfaces
void
octopus_interfaces__msg__MoveIntent__Sequence__destroy(octopus_interfaces__msg__MoveIntent__Sequence * array);

/// Check for msg/MoveIntent message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_octopus_interfaces
bool
octopus_interfaces__msg__MoveIntent__Sequence__are_equal(const octopus_interfaces__msg__MoveIntent__Sequence * lhs, const octopus_interfaces__msg__MoveIntent__Sequence * rhs);

/// Copy an array of msg/MoveIntent messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_octopus_interfaces
bool
octopus_interfaces__msg__MoveIntent__Sequence__copy(
  const octopus_interfaces__msg__MoveIntent__Sequence * input,
  octopus_interfaces__msg__MoveIntent__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // OCTOPUS_INTERFACES__MSG__DETAIL__MOVE_INTENT__FUNCTIONS_H_
