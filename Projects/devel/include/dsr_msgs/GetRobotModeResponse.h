// Generated by gencpp from file dsr_msgs/GetRobotModeResponse.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_GETROBOTMODERESPONSE_H
#define DSR_MSGS_MESSAGE_GETROBOTMODERESPONSE_H


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
struct GetRobotModeResponse_
{
  typedef GetRobotModeResponse_<ContainerAllocator> Type;

  GetRobotModeResponse_()
    : robot_mode(0)
    , success(false)  {
    }
  GetRobotModeResponse_(const ContainerAllocator& _alloc)
    : robot_mode(0)
    , success(false)  {
  (void)_alloc;
    }



   typedef int8_t _robot_mode_type;
  _robot_mode_type robot_mode;

   typedef uint8_t _success_type;
  _success_type success;





  typedef boost::shared_ptr< ::dsr_msgs::GetRobotModeResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dsr_msgs::GetRobotModeResponse_<ContainerAllocator> const> ConstPtr;

}; // struct GetRobotModeResponse_

typedef ::dsr_msgs::GetRobotModeResponse_<std::allocator<void> > GetRobotModeResponse;

typedef boost::shared_ptr< ::dsr_msgs::GetRobotModeResponse > GetRobotModeResponsePtr;
typedef boost::shared_ptr< ::dsr_msgs::GetRobotModeResponse const> GetRobotModeResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dsr_msgs::GetRobotModeResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dsr_msgs::GetRobotModeResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::dsr_msgs::GetRobotModeResponse_<ContainerAllocator1> & lhs, const ::dsr_msgs::GetRobotModeResponse_<ContainerAllocator2> & rhs)
{
  return lhs.robot_mode == rhs.robot_mode &&
    lhs.success == rhs.success;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::dsr_msgs::GetRobotModeResponse_<ContainerAllocator1> & lhs, const ::dsr_msgs::GetRobotModeResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace dsr_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::GetRobotModeResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::GetRobotModeResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::GetRobotModeResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::GetRobotModeResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::GetRobotModeResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::GetRobotModeResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dsr_msgs::GetRobotModeResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "020eb3bd52e8053b30ef11386e0bba83";
  }

  static const char* value(const ::dsr_msgs::GetRobotModeResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x020eb3bd52e8053bULL;
  static const uint64_t static_value2 = 0x30ef11386e0bba83ULL;
};

template<class ContainerAllocator>
struct DataType< ::dsr_msgs::GetRobotModeResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dsr_msgs/GetRobotModeResponse";
  }

  static const char* value(const ::dsr_msgs::GetRobotModeResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dsr_msgs::GetRobotModeResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int8 robot_mode\n"
"bool        success\n"
;
  }

  static const char* value(const ::dsr_msgs::GetRobotModeResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dsr_msgs::GetRobotModeResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.robot_mode);
      stream.next(m.success);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GetRobotModeResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dsr_msgs::GetRobotModeResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dsr_msgs::GetRobotModeResponse_<ContainerAllocator>& v)
  {
    s << indent << "robot_mode: ";
    Printer<int8_t>::stream(s, indent + "  ", v.robot_mode);
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DSR_MSGS_MESSAGE_GETROBOTMODERESPONSE_H
