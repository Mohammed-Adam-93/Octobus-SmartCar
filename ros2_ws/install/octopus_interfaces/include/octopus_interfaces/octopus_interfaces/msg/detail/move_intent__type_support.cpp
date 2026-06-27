// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from octopus_interfaces:msg/MoveIntent.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "octopus_interfaces/msg/detail/move_intent__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace octopus_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void MoveIntent_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) octopus_interfaces::msg::MoveIntent(_init);
}

void MoveIntent_fini_function(void * message_memory)
{
  auto typed_message = static_cast<octopus_interfaces::msg::MoveIntent *>(message_memory);
  typed_message->~MoveIntent();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MoveIntent_message_member_array[3] = {
  {
    "permission",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(octopus_interfaces::msg::MoveIntent, permission),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "direction",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(octopus_interfaces::msg::MoveIntent, direction),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "speed",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(octopus_interfaces::msg::MoveIntent, speed),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MoveIntent_message_members = {
  "octopus_interfaces::msg",  // message namespace
  "MoveIntent",  // message name
  3,  // number of fields
  sizeof(octopus_interfaces::msg::MoveIntent),
  MoveIntent_message_member_array,  // message members
  MoveIntent_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveIntent_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MoveIntent_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MoveIntent_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace octopus_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<octopus_interfaces::msg::MoveIntent>()
{
  return &::octopus_interfaces::msg::rosidl_typesupport_introspection_cpp::MoveIntent_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, octopus_interfaces, msg, MoveIntent)() {
  return &::octopus_interfaces::msg::rosidl_typesupport_introspection_cpp::MoveIntent_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
