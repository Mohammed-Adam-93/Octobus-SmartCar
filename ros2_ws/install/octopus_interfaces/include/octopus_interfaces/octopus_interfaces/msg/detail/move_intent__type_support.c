// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from octopus_interfaces:msg/MoveIntent.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "octopus_interfaces/msg/detail/move_intent__rosidl_typesupport_introspection_c.h"
#include "octopus_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "octopus_interfaces/msg/detail/move_intent__functions.h"
#include "octopus_interfaces/msg/detail/move_intent__struct.h"


// Include directives for member types
// Member `permission`
// Member `direction`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void octopus_interfaces__msg__MoveIntent__rosidl_typesupport_introspection_c__MoveIntent_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  octopus_interfaces__msg__MoveIntent__init(message_memory);
}

void octopus_interfaces__msg__MoveIntent__rosidl_typesupport_introspection_c__MoveIntent_fini_function(void * message_memory)
{
  octopus_interfaces__msg__MoveIntent__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember octopus_interfaces__msg__MoveIntent__rosidl_typesupport_introspection_c__MoveIntent_message_member_array[3] = {
  {
    "permission",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(octopus_interfaces__msg__MoveIntent, permission),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "direction",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(octopus_interfaces__msg__MoveIntent, direction),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "speed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(octopus_interfaces__msg__MoveIntent, speed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers octopus_interfaces__msg__MoveIntent__rosidl_typesupport_introspection_c__MoveIntent_message_members = {
  "octopus_interfaces__msg",  // message namespace
  "MoveIntent",  // message name
  3,  // number of fields
  sizeof(octopus_interfaces__msg__MoveIntent),
  octopus_interfaces__msg__MoveIntent__rosidl_typesupport_introspection_c__MoveIntent_message_member_array,  // message members
  octopus_interfaces__msg__MoveIntent__rosidl_typesupport_introspection_c__MoveIntent_init_function,  // function to initialize message memory (memory has to be allocated)
  octopus_interfaces__msg__MoveIntent__rosidl_typesupport_introspection_c__MoveIntent_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t octopus_interfaces__msg__MoveIntent__rosidl_typesupport_introspection_c__MoveIntent_message_type_support_handle = {
  0,
  &octopus_interfaces__msg__MoveIntent__rosidl_typesupport_introspection_c__MoveIntent_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_octopus_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, octopus_interfaces, msg, MoveIntent)() {
  if (!octopus_interfaces__msg__MoveIntent__rosidl_typesupport_introspection_c__MoveIntent_message_type_support_handle.typesupport_identifier) {
    octopus_interfaces__msg__MoveIntent__rosidl_typesupport_introspection_c__MoveIntent_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &octopus_interfaces__msg__MoveIntent__rosidl_typesupport_introspection_c__MoveIntent_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
