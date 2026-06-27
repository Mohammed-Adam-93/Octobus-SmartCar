// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from octopus_interfaces:msg/ObjectDistance.idl
// generated code does not contain a copyright notice

#ifndef OCTOPUS_INTERFACES__MSG__DETAIL__OBJECT_DISTANCE__STRUCT_HPP_
#define OCTOPUS_INTERFACES__MSG__DETAIL__OBJECT_DISTANCE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__octopus_interfaces__msg__ObjectDistance __attribute__((deprecated))
#else
# define DEPRECATED__octopus_interfaces__msg__ObjectDistance __declspec(deprecated)
#endif

namespace octopus_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ObjectDistance_
{
  using Type = ObjectDistance_<ContainerAllocator>;

  explicit ObjectDistance_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->left = 0.0f;
      this->middle = 0.0f;
      this->right = 0.0f;
    }
  }

  explicit ObjectDistance_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->left = 0.0f;
      this->middle = 0.0f;
      this->right = 0.0f;
    }
  }

  // field types and members
  using _left_type =
    float;
  _left_type left;
  using _middle_type =
    float;
  _middle_type middle;
  using _right_type =
    float;
  _right_type right;

  // setters for named parameter idiom
  Type & set__left(
    const float & _arg)
  {
    this->left = _arg;
    return *this;
  }
  Type & set__middle(
    const float & _arg)
  {
    this->middle = _arg;
    return *this;
  }
  Type & set__right(
    const float & _arg)
  {
    this->right = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    octopus_interfaces::msg::ObjectDistance_<ContainerAllocator> *;
  using ConstRawPtr =
    const octopus_interfaces::msg::ObjectDistance_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<octopus_interfaces::msg::ObjectDistance_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<octopus_interfaces::msg::ObjectDistance_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      octopus_interfaces::msg::ObjectDistance_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<octopus_interfaces::msg::ObjectDistance_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      octopus_interfaces::msg::ObjectDistance_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<octopus_interfaces::msg::ObjectDistance_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<octopus_interfaces::msg::ObjectDistance_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<octopus_interfaces::msg::ObjectDistance_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__octopus_interfaces__msg__ObjectDistance
    std::shared_ptr<octopus_interfaces::msg::ObjectDistance_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__octopus_interfaces__msg__ObjectDistance
    std::shared_ptr<octopus_interfaces::msg::ObjectDistance_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ObjectDistance_ & other) const
  {
    if (this->left != other.left) {
      return false;
    }
    if (this->middle != other.middle) {
      return false;
    }
    if (this->right != other.right) {
      return false;
    }
    return true;
  }
  bool operator!=(const ObjectDistance_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ObjectDistance_

// alias to use template instance with default allocator
using ObjectDistance =
  octopus_interfaces::msg::ObjectDistance_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace octopus_interfaces

#endif  // OCTOPUS_INTERFACES__MSG__DETAIL__OBJECT_DISTANCE__STRUCT_HPP_
