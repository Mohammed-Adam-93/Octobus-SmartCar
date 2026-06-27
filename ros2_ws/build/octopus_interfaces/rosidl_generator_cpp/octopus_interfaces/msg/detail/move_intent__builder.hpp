// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from octopus_interfaces:msg/MoveIntent.idl
// generated code does not contain a copyright notice

#ifndef OCTOPUS_INTERFACES__MSG__DETAIL__MOVE_INTENT__BUILDER_HPP_
#define OCTOPUS_INTERFACES__MSG__DETAIL__MOVE_INTENT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "octopus_interfaces/msg/detail/move_intent__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace octopus_interfaces
{

namespace msg
{

namespace builder
{

class Init_MoveIntent_speed
{
public:
  explicit Init_MoveIntent_speed(::octopus_interfaces::msg::MoveIntent & msg)
  : msg_(msg)
  {}
  ::octopus_interfaces::msg::MoveIntent speed(::octopus_interfaces::msg::MoveIntent::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::octopus_interfaces::msg::MoveIntent msg_;
};

class Init_MoveIntent_direction
{
public:
  explicit Init_MoveIntent_direction(::octopus_interfaces::msg::MoveIntent & msg)
  : msg_(msg)
  {}
  Init_MoveIntent_speed direction(::octopus_interfaces::msg::MoveIntent::_direction_type arg)
  {
    msg_.direction = std::move(arg);
    return Init_MoveIntent_speed(msg_);
  }

private:
  ::octopus_interfaces::msg::MoveIntent msg_;
};

class Init_MoveIntent_permission
{
public:
  Init_MoveIntent_permission()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveIntent_direction permission(::octopus_interfaces::msg::MoveIntent::_permission_type arg)
  {
    msg_.permission = std::move(arg);
    return Init_MoveIntent_direction(msg_);
  }

private:
  ::octopus_interfaces::msg::MoveIntent msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::octopus_interfaces::msg::MoveIntent>()
{
  return octopus_interfaces::msg::builder::Init_MoveIntent_permission();
}

}  // namespace octopus_interfaces

#endif  // OCTOPUS_INTERFACES__MSG__DETAIL__MOVE_INTENT__BUILDER_HPP_
