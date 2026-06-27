// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from octopus_interfaces:msg/ObjectDistance.idl
// generated code does not contain a copyright notice

#ifndef OCTOPUS_INTERFACES__MSG__DETAIL__OBJECT_DISTANCE__BUILDER_HPP_
#define OCTOPUS_INTERFACES__MSG__DETAIL__OBJECT_DISTANCE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "octopus_interfaces/msg/detail/object_distance__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace octopus_interfaces
{

namespace msg
{

namespace builder
{

class Init_ObjectDistance_right
{
public:
  explicit Init_ObjectDistance_right(::octopus_interfaces::msg::ObjectDistance & msg)
  : msg_(msg)
  {}
  ::octopus_interfaces::msg::ObjectDistance right(::octopus_interfaces::msg::ObjectDistance::_right_type arg)
  {
    msg_.right = std::move(arg);
    return std::move(msg_);
  }

private:
  ::octopus_interfaces::msg::ObjectDistance msg_;
};

class Init_ObjectDistance_middle
{
public:
  explicit Init_ObjectDistance_middle(::octopus_interfaces::msg::ObjectDistance & msg)
  : msg_(msg)
  {}
  Init_ObjectDistance_right middle(::octopus_interfaces::msg::ObjectDistance::_middle_type arg)
  {
    msg_.middle = std::move(arg);
    return Init_ObjectDistance_right(msg_);
  }

private:
  ::octopus_interfaces::msg::ObjectDistance msg_;
};

class Init_ObjectDistance_left
{
public:
  Init_ObjectDistance_left()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ObjectDistance_middle left(::octopus_interfaces::msg::ObjectDistance::_left_type arg)
  {
    msg_.left = std::move(arg);
    return Init_ObjectDistance_middle(msg_);
  }

private:
  ::octopus_interfaces::msg::ObjectDistance msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::octopus_interfaces::msg::ObjectDistance>()
{
  return octopus_interfaces::msg::builder::Init_ObjectDistance_left();
}

}  // namespace octopus_interfaces

#endif  // OCTOPUS_INTERFACES__MSG__DETAIL__OBJECT_DISTANCE__BUILDER_HPP_
