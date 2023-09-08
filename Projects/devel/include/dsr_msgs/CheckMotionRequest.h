// Generated by gencpp from file dsr_msgs/CheckMotionRequest.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_CHECKMOTIONREQUEST_H
#define DSR_MSGS_MESSAGE_CHECKMOTIONREQUEST_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace dsr_msgs
{
template <class ContainerAllocator>
struct CheckMotionRequest_
{
  typedef CheckMotionRequest_<ContainerAllocator> Type;

  CheckMotionRequest_()
    {
    }
  CheckMotionRequest_(const ContainerAllocator& _alloc)
    {
  (void)_alloc;
    }







  typedef boost::shared_ptr< ::dsr_msgs::CheckMotionRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dsr_msgs::CheckMotionRequest_<ContainerAllocator> const> ConstPtr;

}; // struct CheckMotionRequest_

typedef ::dsr_msgs::CheckMotionRequest_<std::allocator<void> > CheckMotionRequest;

typedef boost::shared_ptr< ::dsr_msgs::CheckMotionRequest > CheckMotionRequestPtr;
typedef boost::shared_ptr< ::dsr_msgs::CheckMotionRequest const> CheckMotionRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dsr_msgs::CheckMotionRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dsr_msgs::CheckMotionRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


} // namespace dsr_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::CheckMotionRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::CheckMotionRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::CheckMotionRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::CheckMotionRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::CheckMotionRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::CheckMotionRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dsr_msgs::CheckMotionRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::dsr_msgs::CheckMotionRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::dsr_msgs::CheckMotionRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dsr_msgs/CheckMotionRequest";
  }

  static const char* value(const ::dsr_msgs::CheckMotionRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dsr_msgs::CheckMotionRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#____________________________________________________________________________________________\n"
"# check_motion\n"
"# return status of the currently active motion.\n"
"# Homing is performed by moving to the joint motion to the mechanical or user defined home position.\n"
"# According to the input parameter [target], it moves to the mechanical home defined in the system or the home set by the user.\n"
"#____________________________________________________________________________________________\n"
"\n"
;
  }

  static const char* value(const ::dsr_msgs::CheckMotionRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dsr_msgs::CheckMotionRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct CheckMotionRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dsr_msgs::CheckMotionRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::dsr_msgs::CheckMotionRequest_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // DSR_MSGS_MESSAGE_CHECKMOTIONREQUEST_H
