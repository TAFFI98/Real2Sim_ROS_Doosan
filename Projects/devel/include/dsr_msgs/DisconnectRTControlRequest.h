// Generated by gencpp from file dsr_msgs/DisconnectRTControlRequest.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_DISCONNECTRTCONTROLREQUEST_H
#define DSR_MSGS_MESSAGE_DISCONNECTRTCONTROLREQUEST_H


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
struct DisconnectRTControlRequest_
{
  typedef DisconnectRTControlRequest_<ContainerAllocator> Type;

  DisconnectRTControlRequest_()
    {
    }
  DisconnectRTControlRequest_(const ContainerAllocator& _alloc)
    {
  (void)_alloc;
    }







  typedef boost::shared_ptr< ::dsr_msgs::DisconnectRTControlRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dsr_msgs::DisconnectRTControlRequest_<ContainerAllocator> const> ConstPtr;

}; // struct DisconnectRTControlRequest_

typedef ::dsr_msgs::DisconnectRTControlRequest_<std::allocator<void> > DisconnectRTControlRequest;

typedef boost::shared_ptr< ::dsr_msgs::DisconnectRTControlRequest > DisconnectRTControlRequestPtr;
typedef boost::shared_ptr< ::dsr_msgs::DisconnectRTControlRequest const> DisconnectRTControlRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dsr_msgs::DisconnectRTControlRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dsr_msgs::DisconnectRTControlRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


} // namespace dsr_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::DisconnectRTControlRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::DisconnectRTControlRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::DisconnectRTControlRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::DisconnectRTControlRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::DisconnectRTControlRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::DisconnectRTControlRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dsr_msgs::DisconnectRTControlRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::dsr_msgs::DisconnectRTControlRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::dsr_msgs::DisconnectRTControlRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dsr_msgs/DisconnectRTControlRequest";
  }

  static const char* value(const ::dsr_msgs::DisconnectRTControlRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dsr_msgs::DisconnectRTControlRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#____________________________________________________________________________________________\n"
"# disconnect_rt_control\n"
"#____________________________________________________________________________________________\n"
;
  }

  static const char* value(const ::dsr_msgs::DisconnectRTControlRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dsr_msgs::DisconnectRTControlRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct DisconnectRTControlRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dsr_msgs::DisconnectRTControlRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::dsr_msgs::DisconnectRTControlRequest_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // DSR_MSGS_MESSAGE_DISCONNECTRTCONTROLREQUEST_H