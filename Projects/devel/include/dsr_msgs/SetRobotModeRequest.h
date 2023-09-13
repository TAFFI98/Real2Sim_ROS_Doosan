// Generated by gencpp from file dsr_msgs/SetRobotModeRequest.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_SETROBOTMODEREQUEST_H
#define DSR_MSGS_MESSAGE_SETROBOTMODEREQUEST_H


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
struct SetRobotModeRequest_
{
  typedef SetRobotModeRequest_<ContainerAllocator> Type;

  SetRobotModeRequest_()
    : robot_mode(0)  {
    }
  SetRobotModeRequest_(const ContainerAllocator& _alloc)
    : robot_mode(0)  {
  (void)_alloc;
    }



   typedef int8_t _robot_mode_type;
  _robot_mode_type robot_mode;





  typedef boost::shared_ptr< ::dsr_msgs::SetRobotModeRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dsr_msgs::SetRobotModeRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SetRobotModeRequest_

typedef ::dsr_msgs::SetRobotModeRequest_<std::allocator<void> > SetRobotModeRequest;

typedef boost::shared_ptr< ::dsr_msgs::SetRobotModeRequest > SetRobotModeRequestPtr;
typedef boost::shared_ptr< ::dsr_msgs::SetRobotModeRequest const> SetRobotModeRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dsr_msgs::SetRobotModeRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dsr_msgs::SetRobotModeRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::dsr_msgs::SetRobotModeRequest_<ContainerAllocator1> & lhs, const ::dsr_msgs::SetRobotModeRequest_<ContainerAllocator2> & rhs)
{
  return lhs.robot_mode == rhs.robot_mode;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::dsr_msgs::SetRobotModeRequest_<ContainerAllocator1> & lhs, const ::dsr_msgs::SetRobotModeRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace dsr_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::SetRobotModeRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::SetRobotModeRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::SetRobotModeRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::SetRobotModeRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::SetRobotModeRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::SetRobotModeRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dsr_msgs::SetRobotModeRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "e693f8d2a4951cec41fb83aa5891c822";
  }

  static const char* value(const ::dsr_msgs::SetRobotModeRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xe693f8d2a4951cecULL;
  static const uint64_t static_value2 = 0x41fb83aa5891c822ULL;
};

template<class ContainerAllocator>
struct DataType< ::dsr_msgs::SetRobotModeRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dsr_msgs/SetRobotModeRequest";
  }

  static const char* value(const ::dsr_msgs::SetRobotModeRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dsr_msgs::SetRobotModeRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#____________________________________________________________________________________________\n"
"# set_robot_mode\n"
"# Change the robot-mode\n"
"# 0 : ROBOT_MODE_MANUAL\n"
"# 1 : ROBOT_MODE_AUTONOMOUS\n"
"# 2 :ROBOT_MODE_MEASURE\n"
"# drfl.SetRobotMode()\n"
"#____________________________________________________________________________________________\n"
"\n"
"int8 robot_mode # <Robot_Mode>\n"
;
  }

  static const char* value(const ::dsr_msgs::SetRobotModeRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dsr_msgs::SetRobotModeRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.robot_mode);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SetRobotModeRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dsr_msgs::SetRobotModeRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dsr_msgs::SetRobotModeRequest_<ContainerAllocator>& v)
  {
    s << indent << "robot_mode: ";
    Printer<int8_t>::stream(s, indent + "  ", v.robot_mode);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DSR_MSGS_MESSAGE_SETROBOTMODEREQUEST_H