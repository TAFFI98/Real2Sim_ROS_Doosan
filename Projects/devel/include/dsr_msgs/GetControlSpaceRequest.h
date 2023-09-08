// Generated by gencpp from file dsr_msgs/GetControlSpaceRequest.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_GETCONTROLSPACEREQUEST_H
#define DSR_MSGS_MESSAGE_GETCONTROLSPACEREQUEST_H


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
struct GetControlSpaceRequest_
{
  typedef GetControlSpaceRequest_<ContainerAllocator> Type;

  GetControlSpaceRequest_()
    {
    }
  GetControlSpaceRequest_(const ContainerAllocator& _alloc)
    {
  (void)_alloc;
    }







  typedef boost::shared_ptr< ::dsr_msgs::GetControlSpaceRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dsr_msgs::GetControlSpaceRequest_<ContainerAllocator> const> ConstPtr;

}; // struct GetControlSpaceRequest_

typedef ::dsr_msgs::GetControlSpaceRequest_<std::allocator<void> > GetControlSpaceRequest;

typedef boost::shared_ptr< ::dsr_msgs::GetControlSpaceRequest > GetControlSpaceRequestPtr;
typedef boost::shared_ptr< ::dsr_msgs::GetControlSpaceRequest const> GetControlSpaceRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dsr_msgs::GetControlSpaceRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dsr_msgs::GetControlSpaceRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


} // namespace dsr_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::GetControlSpaceRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::GetControlSpaceRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::GetControlSpaceRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::GetControlSpaceRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::GetControlSpaceRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::GetControlSpaceRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dsr_msgs::GetControlSpaceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::dsr_msgs::GetControlSpaceRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::dsr_msgs::GetControlSpaceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dsr_msgs/GetControlSpaceRequest";
  }

  static const char* value(const ::dsr_msgs::GetControlSpaceRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dsr_msgs::GetControlSpaceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#____________________________________________________________________________________________\n"
"# get_control_space()  \n"
"#____________________________________________________________________________________________\n"
"# This service returns the current control space.\n"
"\n"
;
  }

  static const char* value(const ::dsr_msgs::GetControlSpaceRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dsr_msgs::GetControlSpaceRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GetControlSpaceRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dsr_msgs::GetControlSpaceRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::dsr_msgs::GetControlSpaceRequest_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // DSR_MSGS_MESSAGE_GETCONTROLSPACEREQUEST_H
