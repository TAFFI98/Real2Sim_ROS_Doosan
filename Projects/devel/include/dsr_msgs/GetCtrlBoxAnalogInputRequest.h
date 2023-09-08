// Generated by gencpp from file dsr_msgs/GetCtrlBoxAnalogInputRequest.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_GETCTRLBOXANALOGINPUTREQUEST_H
#define DSR_MSGS_MESSAGE_GETCTRLBOXANALOGINPUTREQUEST_H


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
struct GetCtrlBoxAnalogInputRequest_
{
  typedef GetCtrlBoxAnalogInputRequest_<ContainerAllocator> Type;

  GetCtrlBoxAnalogInputRequest_()
    : channel(0)  {
    }
  GetCtrlBoxAnalogInputRequest_(const ContainerAllocator& _alloc)
    : channel(0)  {
  (void)_alloc;
    }



   typedef int8_t _channel_type;
  _channel_type channel;





  typedef boost::shared_ptr< ::dsr_msgs::GetCtrlBoxAnalogInputRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dsr_msgs::GetCtrlBoxAnalogInputRequest_<ContainerAllocator> const> ConstPtr;

}; // struct GetCtrlBoxAnalogInputRequest_

typedef ::dsr_msgs::GetCtrlBoxAnalogInputRequest_<std::allocator<void> > GetCtrlBoxAnalogInputRequest;

typedef boost::shared_ptr< ::dsr_msgs::GetCtrlBoxAnalogInputRequest > GetCtrlBoxAnalogInputRequestPtr;
typedef boost::shared_ptr< ::dsr_msgs::GetCtrlBoxAnalogInputRequest const> GetCtrlBoxAnalogInputRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dsr_msgs::GetCtrlBoxAnalogInputRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dsr_msgs::GetCtrlBoxAnalogInputRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::dsr_msgs::GetCtrlBoxAnalogInputRequest_<ContainerAllocator1> & lhs, const ::dsr_msgs::GetCtrlBoxAnalogInputRequest_<ContainerAllocator2> & rhs)
{
  return lhs.channel == rhs.channel;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::dsr_msgs::GetCtrlBoxAnalogInputRequest_<ContainerAllocator1> & lhs, const ::dsr_msgs::GetCtrlBoxAnalogInputRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace dsr_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::GetCtrlBoxAnalogInputRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::GetCtrlBoxAnalogInputRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::GetCtrlBoxAnalogInputRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::GetCtrlBoxAnalogInputRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::GetCtrlBoxAnalogInputRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::GetCtrlBoxAnalogInputRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dsr_msgs::GetCtrlBoxAnalogInputRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a5a84cde6f0483759aed632b8b0994a9";
  }

  static const char* value(const ::dsr_msgs::GetCtrlBoxAnalogInputRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa5a84cde6f048375ULL;
  static const uint64_t static_value2 = 0x9aed632b8b0994a9ULL;
};

template<class ContainerAllocator>
struct DataType< ::dsr_msgs::GetCtrlBoxAnalogInputRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dsr_msgs/GetCtrlBoxAnalogInputRequest";
  }

  static const char* value(const ::dsr_msgs::GetCtrlBoxAnalogInputRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dsr_msgs::GetCtrlBoxAnalogInputRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#____________________________________________________________________________________________\n"
"# get_analog_input \n"
"#____________________________________________________________________________________________\n"
"\n"
"int8        channel    # 1 = ch1, 2= ch2\n"
;
  }

  static const char* value(const ::dsr_msgs::GetCtrlBoxAnalogInputRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dsr_msgs::GetCtrlBoxAnalogInputRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.channel);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GetCtrlBoxAnalogInputRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dsr_msgs::GetCtrlBoxAnalogInputRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dsr_msgs::GetCtrlBoxAnalogInputRequest_<ContainerAllocator>& v)
  {
    s << indent << "channel: ";
    Printer<int8_t>::stream(s, indent + "  ", v.channel);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DSR_MSGS_MESSAGE_GETCTRLBOXANALOGINPUTREQUEST_H
