// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from octopus_interfaces:msg/MoveIntent.idl
// generated code does not contain a copyright notice

#ifndef OCTOPUS_INTERFACES__MSG__DETAIL__MOVE_INTENT__STRUCT_HPP_
#define OCTOPUS_INTERFACES__MSG__DETAIL__MOVE_INTENT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__octopus_interfaces__msg__MoveIntent __attribute__((deprecated))
#else
# define DEPRECATED__octopus_interfaces__msg__MoveIntent __declspec(deprecated)
#endif

namespace octopus_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MoveIntent_
{
  using Type = MoveIntent_<ContainerAllocator>;

  explicit MoveIntent_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->permission = "";
      this->direction = "";
      this->speed = 0;
    }
  }

  explicit MoveIntent_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : permission(_alloc),
    direction(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->permission = "";
      this->direction = "";
      this->speed = 0;
    }
  }

  // field types and members
  using _permission_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _permission_type permission;
  using _direction_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _direction_type direction;
  using _speed_type =
    uint8_t;
  _speed_type speed;

  // setters for named parameter idiom
  Type & set__permission(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->permission = _arg;
    return *this;
  }
  Type & set__direction(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->direction = _arg;
    return *this;
  }
  Type & set__speed(
    const uint8_t & _arg)
  {
    this->speed = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    octopus_interfaces::msg::MoveIntent_<ContainerAllocator> *;
  using ConstRawPtr =
    const octopus_interfaces::msg::MoveIntent_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<octopus_interfaces::msg::MoveIntent_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<octopus_interfaces::msg::MoveIntent_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      octopus_interfaces::msg::MoveIntent_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<octopus_interfaces::msg::MoveIntent_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      octopus_interfaces::msg::MoveIntent_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<octopus_interfaces::msg::MoveIntent_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<octopus_interfaces::msg::MoveIntent_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<octopus_interfaces::msg::MoveIntent_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__octopus_interfaces__msg__MoveIntent
    std::shared_ptr<octopus_interfaces::msg::MoveIntent_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__octopus_interfaces__msg__MoveIntent
    std::shared_ptr<octopus_interfaces::msg::MoveIntent_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveIntent_ & other) const
  {
    if (this->permission != other.permission) {
      return false;
    }
    if (this->direction != other.direction) {
      return false;
    }
    if (this->speed != other.speed) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveIntent_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveIntent_

// alias to use template instance with default allocator
using MoveIntent =
  octopus_interfaces::msg::MoveIntent_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace octopus_interfaces

#endif  // OCTOPUS_INTERFACES__MSG__DETAIL__MOVE_INTENT__STRUCT_HPP_
