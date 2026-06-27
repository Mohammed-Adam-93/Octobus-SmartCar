// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from octopus_interfaces:msg/SensorIndex.idl
// generated code does not contain a copyright notice

#ifndef OCTOPUS_INTERFACES__MSG__DETAIL__SENSOR_INDEX__STRUCT_HPP_
#define OCTOPUS_INTERFACES__MSG__DETAIL__SENSOR_INDEX__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__octopus_interfaces__msg__SensorIndex __attribute__((deprecated))
#else
# define DEPRECATED__octopus_interfaces__msg__SensorIndex __declspec(deprecated)
#endif

namespace octopus_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SensorIndex_
{
  using Type = SensorIndex_<ContainerAllocator>;

  explicit SensorIndex_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sensor = "";
      this->index = 0;
    }
  }

  explicit SensorIndex_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : sensor(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sensor = "";
      this->index = 0;
    }
  }

  // field types and members
  using _sensor_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _sensor_type sensor;
  using _index_type =
    int8_t;
  _index_type index;

  // setters for named parameter idiom
  Type & set__sensor(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->sensor = _arg;
    return *this;
  }
  Type & set__index(
    const int8_t & _arg)
  {
    this->index = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    octopus_interfaces::msg::SensorIndex_<ContainerAllocator> *;
  using ConstRawPtr =
    const octopus_interfaces::msg::SensorIndex_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<octopus_interfaces::msg::SensorIndex_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<octopus_interfaces::msg::SensorIndex_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      octopus_interfaces::msg::SensorIndex_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<octopus_interfaces::msg::SensorIndex_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      octopus_interfaces::msg::SensorIndex_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<octopus_interfaces::msg::SensorIndex_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<octopus_interfaces::msg::SensorIndex_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<octopus_interfaces::msg::SensorIndex_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__octopus_interfaces__msg__SensorIndex
    std::shared_ptr<octopus_interfaces::msg::SensorIndex_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__octopus_interfaces__msg__SensorIndex
    std::shared_ptr<octopus_interfaces::msg::SensorIndex_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SensorIndex_ & other) const
  {
    if (this->sensor != other.sensor) {
      return false;
    }
    if (this->index != other.index) {
      return false;
    }
    return true;
  }
  bool operator!=(const SensorIndex_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SensorIndex_

// alias to use template instance with default allocator
using SensorIndex =
  octopus_interfaces::msg::SensorIndex_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace octopus_interfaces

#endif  // OCTOPUS_INTERFACES__MSG__DETAIL__SENSOR_INDEX__STRUCT_HPP_
