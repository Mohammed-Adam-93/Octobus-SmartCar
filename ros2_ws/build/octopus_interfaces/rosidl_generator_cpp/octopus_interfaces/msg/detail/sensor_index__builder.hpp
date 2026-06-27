// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from octopus_interfaces:msg/SensorIndex.idl
// generated code does not contain a copyright notice

#ifndef OCTOPUS_INTERFACES__MSG__DETAIL__SENSOR_INDEX__BUILDER_HPP_
#define OCTOPUS_INTERFACES__MSG__DETAIL__SENSOR_INDEX__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "octopus_interfaces/msg/detail/sensor_index__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace octopus_interfaces
{

namespace msg
{

namespace builder
{

class Init_SensorIndex_index
{
public:
  explicit Init_SensorIndex_index(::octopus_interfaces::msg::SensorIndex & msg)
  : msg_(msg)
  {}
  ::octopus_interfaces::msg::SensorIndex index(::octopus_interfaces::msg::SensorIndex::_index_type arg)
  {
    msg_.index = std::move(arg);
    return std::move(msg_);
  }

private:
  ::octopus_interfaces::msg::SensorIndex msg_;
};

class Init_SensorIndex_sensor
{
public:
  Init_SensorIndex_sensor()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SensorIndex_index sensor(::octopus_interfaces::msg::SensorIndex::_sensor_type arg)
  {
    msg_.sensor = std::move(arg);
    return Init_SensorIndex_index(msg_);
  }

private:
  ::octopus_interfaces::msg::SensorIndex msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::octopus_interfaces::msg::SensorIndex>()
{
  return octopus_interfaces::msg::builder::Init_SensorIndex_sensor();
}

}  // namespace octopus_interfaces

#endif  // OCTOPUS_INTERFACES__MSG__DETAIL__SENSOR_INDEX__BUILDER_HPP_
