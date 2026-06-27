// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from octopus_interfaces:msg/MoveIntent.idl
// generated code does not contain a copyright notice

#ifndef OCTOPUS_INTERFACES__MSG__DETAIL__MOVE_INTENT__TRAITS_HPP_
#define OCTOPUS_INTERFACES__MSG__DETAIL__MOVE_INTENT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "octopus_interfaces/msg/detail/move_intent__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace octopus_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const MoveIntent & msg,
  std::ostream & out)
{
  out << "{";
  // member: permission
  {
    out << "permission: ";
    rosidl_generator_traits::value_to_yaml(msg.permission, out);
    out << ", ";
  }

  // member: direction
  {
    out << "direction: ";
    rosidl_generator_traits::value_to_yaml(msg.direction, out);
    out << ", ";
  }

  // member: speed
  {
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoveIntent & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: permission
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "permission: ";
    rosidl_generator_traits::value_to_yaml(msg.permission, out);
    out << "\n";
  }

  // member: direction
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "direction: ";
    rosidl_generator_traits::value_to_yaml(msg.direction, out);
    out << "\n";
  }

  // member: speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoveIntent & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace octopus_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use octopus_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const octopus_interfaces::msg::MoveIntent & msg,
  std::ostream & out, size_t indentation = 0)
{
  octopus_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use octopus_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const octopus_interfaces::msg::MoveIntent & msg)
{
  return octopus_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<octopus_interfaces::msg::MoveIntent>()
{
  return "octopus_interfaces::msg::MoveIntent";
}

template<>
inline const char * name<octopus_interfaces::msg::MoveIntent>()
{
  return "octopus_interfaces/msg/MoveIntent";
}

template<>
struct has_fixed_size<octopus_interfaces::msg::MoveIntent>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<octopus_interfaces::msg::MoveIntent>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<octopus_interfaces::msg::MoveIntent>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OCTOPUS_INTERFACES__MSG__DETAIL__MOVE_INTENT__TRAITS_HPP_
