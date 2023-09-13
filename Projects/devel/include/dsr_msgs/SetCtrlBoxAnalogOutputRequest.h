// Generated by gencpp from file dsr_msgs/SetCtrlBoxAnalogOutputRequest.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_SETCTRLBOXANALOGOUTPUTREQUEST_H
#define DSR_MSGS_MESSAGE_SETCTRLBOXANALOGOUTPUTREQUEST_H


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
struct SetCtrlBoxAnalogOutputRequest_
{
  typedef SetCtrlBoxAnalogOutputRequest_<ContainerAllocator> Type;

  SetCtrlBoxAnalogOutputRequest_()
    : channel(0)
    , value(0.0)  {
    }
  SetCtrlBoxAnalogOutputRequest_(const ContainerAllocator& _alloc)
    : channel(0)
    , value(0.0)  {
  (void)_alloc;
    }



   typedef int8_t _channel_type;
  _channel_type channel;

   typedef double _value_type;
  _value_type value;





  typedef boost::shared_ptr< ::dsr_msgs::SetCtrlBoxAnalogOutputRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dsr_msgs::SetCtrlBoxAnalogOutputRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SetCtrlBoxAnalogOutputRequest_

typedef ::dsr_msgs::SetCtrlBoxAnalogOutputRequest_<std::allocator<void> > SetCtrlBoxAnalogOutputRequest;

typedef boost::shared_ptr< ::dsr_msgs::SetCtrlBoxAnalogOutputRequest > SetCtrlBoxAnalogOutputRequestPtr;
typedef boost::shared_ptr< ::dsr_msgs::SetCtrlBoxAnalogOutputRequest const> SetCtrlBoxAnalogOutputRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dsr_msgs::SetCtrlBoxAnalogOutputRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dsr_msgs::SetCtrlBoxAnalogOutputRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::dsr_msgs::SetCtrlBoxAnalogOutputRequest_<ContainerAllocator1> & lhs, const ::dsr_msgs::SetCtrlBoxAnalogOutputRequest_<ContainerAllocator2> & rhs)
{
  return lhs.channel == rhs.channel &&
    lhs.value == rhs.value;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::dsr_msgs::SetCtrlBoxAnalogOutputRequest_<ContainerAllocator1> & lhs, const ::dsr_msgs::SetCtrlBoxAnalogOutputRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace dsr_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::SetCtrlBoxAnalogOutputRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::SetCtrlBoxAnalogOutputRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::SetCtrlBoxAnalogOutputRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::SetCtrlBoxAnalogOutputRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::SetCtrlBoxAnalogOutputRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::SetCtrlBoxAnalogOutputRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dsr_msgs::SetCtrlBoxAnalogOutputRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "53e4d7ae00f0ca2783c40d0e24800b82";
  }

  static const char* value(const ::dsr_msgs::SetCtrlBoxAnalogOutputRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x53e4d7ae00f0ca27ULL;
  static const uint64_t static_value2 = 0x83c40d0e24800b82ULL;
};

template<class ContainerAllocator>
struct DataType< ::dsr_msgs::SetCtrlBoxAnalogOutputRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dsr_msgs/SetCtrlBoxAnalogOutputRequest";
  }

  static const char* value(const ::dsr_msgs::SetCtrlBoxAnalogOutputRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dsr_msgs::SetCtrlBoxAnalogOutputRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#____________________________________________________________________________________________\n"
"# set_ctrl_box_analog_output  \n"
"#____________________________________________________________________________________________\n"
"\n"
"int8        channel  # 1 = ch1, 2= ch2 \n"
"float64     value   #\n"
;
  }

  static const char* value(const ::dsr_msgs::SetCtrlBoxAnalogOutputRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dsr_msgs::SetCtrlBoxAnalogOutputRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.channel);
      stream.next(m.value);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SetCtrlBoxAnalogOutputRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dsr_msgs::SetCtrlBoxAnalogOutputRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dsr_msgs::SetCtrlBoxAnalogOutputRequest_<ContainerAllocator>& v)
  {
    s << indent << "channel: ";
    Printer<int8_t>::stream(s, indent + "  ", v.channel);
    s << indent << "value: ";
    Printer<double>::stream(s, indent + "  ", v.value);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DSR_MSGS_MESSAGE_SETCTRLBOXANALOGOUTPUTREQUEST_H