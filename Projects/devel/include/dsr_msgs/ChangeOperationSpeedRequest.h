// Generated by gencpp from file dsr_msgs/ChangeOperationSpeedRequest.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_CHANGEOPERATIONSPEEDREQUEST_H
#define DSR_MSGS_MESSAGE_CHANGEOPERATIONSPEEDREQUEST_H


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
struct ChangeOperationSpeedRequest_
{
  typedef ChangeOperationSpeedRequest_<ContainerAllocator> Type;

  ChangeOperationSpeedRequest_()
    : speed(0)  {
    }
  ChangeOperationSpeedRequest_(const ContainerAllocator& _alloc)
    : speed(0)  {
  (void)_alloc;
    }



   typedef int8_t _speed_type;
  _speed_type speed;





  typedef boost::shared_ptr< ::dsr_msgs::ChangeOperationSpeedRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dsr_msgs::ChangeOperationSpeedRequest_<ContainerAllocator> const> ConstPtr;

}; // struct ChangeOperationSpeedRequest_

typedef ::dsr_msgs::ChangeOperationSpeedRequest_<std::allocator<void> > ChangeOperationSpeedRequest;

typedef boost::shared_ptr< ::dsr_msgs::ChangeOperationSpeedRequest > ChangeOperationSpeedRequestPtr;
typedef boost::shared_ptr< ::dsr_msgs::ChangeOperationSpeedRequest const> ChangeOperationSpeedRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dsr_msgs::ChangeOperationSpeedRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dsr_msgs::ChangeOperationSpeedRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::dsr_msgs::ChangeOperationSpeedRequest_<ContainerAllocator1> & lhs, const ::dsr_msgs::ChangeOperationSpeedRequest_<ContainerAllocator2> & rhs)
{
  return lhs.speed == rhs.speed;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::dsr_msgs::ChangeOperationSpeedRequest_<ContainerAllocator1> & lhs, const ::dsr_msgs::ChangeOperationSpeedRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace dsr_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::ChangeOperationSpeedRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::ChangeOperationSpeedRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::ChangeOperationSpeedRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::ChangeOperationSpeedRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::ChangeOperationSpeedRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::ChangeOperationSpeedRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dsr_msgs::ChangeOperationSpeedRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "1f1b16c0f00410da01ce6cbe511e4fcc";
  }

  static const char* value(const ::dsr_msgs::ChangeOperationSpeedRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x1f1b16c0f00410daULL;
  static const uint64_t static_value2 = 0x01ce6cbe511e4fccULL;
};

template<class ContainerAllocator>
struct DataType< ::dsr_msgs::ChangeOperationSpeedRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dsr_msgs/ChangeOperationSpeedRequest";
  }

  static const char* value(const ::dsr_msgs::ChangeOperationSpeedRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dsr_msgs::ChangeOperationSpeedRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#____________________________________________________________________________________________\n"
"# change_operation_speed\n"
"#____________________________________________________________________________________________\n"
"\n"
"int8 speed              # operation speed: (1~100)\n"
;
  }

  static const char* value(const ::dsr_msgs::ChangeOperationSpeedRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dsr_msgs::ChangeOperationSpeedRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.speed);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ChangeOperationSpeedRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dsr_msgs::ChangeOperationSpeedRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dsr_msgs::ChangeOperationSpeedRequest_<ContainerAllocator>& v)
  {
    s << indent << "speed: ";
    Printer<int8_t>::stream(s, indent + "  ", v.speed);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DSR_MSGS_MESSAGE_CHANGEOPERATIONSPEEDREQUEST_H
