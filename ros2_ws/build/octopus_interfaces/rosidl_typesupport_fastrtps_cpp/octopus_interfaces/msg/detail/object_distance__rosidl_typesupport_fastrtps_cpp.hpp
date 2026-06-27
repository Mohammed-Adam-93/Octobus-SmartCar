// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from octopus_interfaces:msg/ObjectDistance.idl
// generated code does not contain a copyright notice

#ifndef OCTOPUS_INTERFACES__MSG__DETAIL__OBJECT_DISTANCE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define OCTOPUS_INTERFACES__MSG__DETAIL__OBJECT_DISTANCE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "octopus_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "octopus_interfaces/msg/detail/object_distance__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace octopus_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_octopus_interfaces
cdr_serialize(
  const octopus_interfaces::msg::ObjectDistance & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_octopus_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  octopus_interfaces::msg::ObjectDistance & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_octopus_interfaces
get_serialized_size(
  const octopus_interfaces::msg::ObjectDistance & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_octopus_interfaces
max_serialized_size_ObjectDistance(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace octopus_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_octopus_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, octopus_interfaces, msg, ObjectDistance)();

#ifdef __cplusplus
}
#endif

#endif  // OCTOPUS_INTERFACES__MSG__DETAIL__OBJECT_DISTANCE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
