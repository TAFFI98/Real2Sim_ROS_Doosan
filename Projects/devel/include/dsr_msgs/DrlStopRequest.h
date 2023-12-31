// Generated by gencpp from file dsr_msgs/DrlStopRequest.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_DRLSTOPREQUEST_H
#define DSR_MSGS_MESSAGE_DRLSTOPREQUEST_H


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
struct DrlStopRequest_
{
  typedef DrlStopRequest_<ContainerAllocator> Type;

  DrlStopRequest_()
    : stop_mode(0)  {
    }
  DrlStopRequest_(const ContainerAllocator& _alloc)
    : stop_mode(0)  {
  (void)_alloc;
    }



   typedef int8_t _stop_mode_type;
  _stop_mode_type stop_mode;





  typedef boost::shared_ptr< ::dsr_msgs::DrlStopRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dsr_msgs::DrlStopRequest_<ContainerAllocator> const> ConstPtr;

}; // struct DrlStopRequest_

typedef ::dsr_msgs::DrlStopRequest_<std::allocator<void> > DrlStopRequest;

typedef boost::shared_ptr< ::dsr_msgs::DrlStopRequest > DrlStopRequestPtr;
typedef boost::shared_ptr< ::dsr_msgs::DrlStopRequest const> DrlStopRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dsr_msgs::DrlStopRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dsr_msgs::DrlStopRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::dsr_msgs::DrlStopRequest_<ContainerAllocator1> & lhs, const ::dsr_msgs::DrlStopRequest_<ContainerAllocator2> & rhs)
{
  return lhs.stop_mode == rhs.stop_mode;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::dsr_msgs::DrlStopRequest_<ContainerAllocator1> & lhs, const ::dsr_msgs::DrlStopRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace dsr_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::DrlStopRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::DrlStopRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::DrlStopRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::DrlStopRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::DrlStopRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::DrlStopRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dsr_msgs::DrlStopRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "0adf90a96bdab6d3a2cf8b6c4744e5bb";
  }

  static const char* value(const ::dsr_msgs::DrlStopRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x0adf90a96bdab6d3ULL;
  static const uint64_t static_value2 = 0xa2cf8b6c4744e5bbULL;
};

template<class ContainerAllocator>
struct DataType< ::dsr_msgs::DrlStopRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dsr_msgs/DrlStopRequest";
  }

  static const char* value(const ::dsr_msgs::DrlStopRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dsr_msgs::DrlStopRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#____________________________________________________________________________________________\n"
"# drl_script_stop  \n"
"# STOP_TYPE_QUICK_STO = 0\n"
"# STOP_TYPE_QUICK     = 1\n"
"# STOP_TYPE_SLOW      = 2\n"
"# STOP_TYPE_HOLD = STOP_TYPE_EMERGENCY = 3  \n"
"#____________________________________________________________________________________________\n"
"\n"
"int8    stop_mode       # <STOP_TYPE> stop_mode       \n"
;
  }

  static const char* value(const ::dsr_msgs::DrlStopRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dsr_msgs::DrlStopRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.stop_mode);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct DrlStopRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dsr_msgs::DrlStopRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dsr_msgs::DrlStopRequest_<ContainerAllocator>& v)
  {
    s << indent << "stop_mode: ";
    Printer<int8_t>::stream(s, indent + "  ", v.stop_mode);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DSR_MSGS_MESSAGE_DRLSTOPREQUEST_H
