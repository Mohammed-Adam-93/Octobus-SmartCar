// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from octopus_interfaces:msg/ObjectDistance.idl
// generated code does not contain a copyright notice

#ifndef OCTOPUS_INTERFACES__MSG__DETAIL__OBJECT_DISTANCE__TRAITS_HPP_
#define OCTOPUS_INTERFACES__MSG__DETAIL__OBJECT_DISTANCE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "octopus_interfaces/msg/detail/object_distance__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace octopus_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ObjectDistance & msg,
  std::ostream & out)
{
  out << "{";
  // member: left
  {
    out << "left: ";
    rosidl_generator_traits::value_to_yaml(msg.left, out);
    out << ", ";
  }

  // member: middle
  {
    out << "middle: ";
    rosidl_generator_traits::value_to_yaml(msg.middle, out);
    out << ", ";
  }

  // member: right
  {
    out << "right: ";
    rosidl_generator_traits::value_to_yaml(msg.right, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ObjectDistance & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: left
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left: ";
    rosidl_generator_traits::value_to_yaml(msg.left, out);
    out << "\n";
  }

  // member: middle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "middle: ";
    rosidl_generator_traits::value_to_yaml(msg.middle, out);
    out << "\n";
  }

  // member: right
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right: ";
    rosidl_generator_traits::value_to_yaml(msg.right, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ObjectDistance & msg, bool use_flow_style = false)
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
  const octopus_interfaces::msg::ObjectDistance & msg,
  std::ostream & out, size_t indentation = 0)
{
  octopus_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use octopus_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const octopus_interfaces::msg::ObjectDistance & msg)
{
  return octopus_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<octopus_interfaces::msg::ObjectDistance>()
{
  return "octopus_interfaces::msg::ObjectDistance";
}

template<>
inline const char * name<octopus_interfaces::msg::ObjectDistance>()
{
  return "octopus_interfaces/msg/ObjectDistance";
}

template<>
struct has_fixed_size<octopus_interfaces::msg::ObjectDistance>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<octopus_interfaces::msg::ObjectDistance>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<octopus_interfaces::msg::ObjectDistance>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OCTOPUS_INTERFACES__MSG__DETAIL__OBJECT_DISTANCE__TRAITS_HPP_
