// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from octopus_interfaces:msg/SensorIndex.idl
// generated code does not contain a copyright notice

#ifndef OCTOPUS_INTERFACES__MSG__DETAIL__SENSOR_INDEX__TRAITS_HPP_
#define OCTOPUS_INTERFACES__MSG__DETAIL__SENSOR_INDEX__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "octopus_interfaces/msg/detail/sensor_index__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace octopus_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const SensorIndex & msg,
  std::ostream & out)
{
  out << "{";
  // member: sensor
  {
    out << "sensor: ";
    rosidl_generator_traits::value_to_yaml(msg.sensor, out);
    out << ", ";
  }

  // member: index
  {
    out << "index: ";
    rosidl_generator_traits::value_to_yaml(msg.index, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SensorIndex & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: sensor
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sensor: ";
    rosidl_generator_traits::value_to_yaml(msg.sensor, out);
    out << "\n";
  }

  // member: index
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "index: ";
    rosidl_generator_traits::value_to_yaml(msg.index, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SensorIndex & msg, bool use_flow_style = false)
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
  const octopus_interfaces::msg::SensorIndex & msg,
  std::ostream & out, size_t indentation = 0)
{
  octopus_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use octopus_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const octopus_interfaces::msg::SensorIndex & msg)
{
  return octopus_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<octopus_interfaces::msg::SensorIndex>()
{
  return "octopus_interfaces::msg::SensorIndex";
}

template<>
inline const char * name<octopus_interfaces::msg::SensorIndex>()
{
  return "octopus_interfaces/msg/SensorIndex";
}

template<>
struct has_fixed_size<octopus_interfaces::msg::SensorIndex>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<octopus_interfaces::msg::SensorIndex>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<octopus_interfaces::msg::SensorIndex>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OCTOPUS_INTERFACES__MSG__DETAIL__SENSOR_INDEX__TRAITS_HPP_
