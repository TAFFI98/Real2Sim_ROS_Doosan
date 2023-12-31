// Generated by gencpp from file dsr_msgs/SetRobotControlRequest.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_SETROBOTCONTROLREQUEST_H
#define DSR_MSGS_MESSAGE_SETROBOTCONTROLREQUEST_H


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
struct SetRobotControlRequest_
{
  typedef SetRobotControlRequest_<ContainerAllocator> Type;

  SetRobotControlRequest_()
    : robot_control(0)  {
    }
  SetRobotControlRequest_(const ContainerAllocator& _alloc)
    : robot_control(0)  {
  (void)_alloc;
    }



   typedef int8_t _robot_control_type;
  _robot_control_type robot_control;





  typedef boost::shared_ptr< ::dsr_msgs::SetRobotControlRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dsr_msgs::SetRobotControlRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SetRobotControlRequest_

typedef ::dsr_msgs::SetRobotControlRequest_<std::allocator<void> > SetRobotControlRequest;

typedef boost::shared_ptr< ::dsr_msgs::SetRobotControlRequest > SetRobotControlRequestPtr;
typedef boost::shared_ptr< ::dsr_msgs::SetRobotControlRequest const> SetRobotControlRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dsr_msgs::SetRobotControlRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dsr_msgs::SetRobotControlRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::dsr_msgs::SetRobotControlRequest_<ContainerAllocator1> & lhs, const ::dsr_msgs::SetRobotControlRequest_<ContainerAllocator2> & rhs)
{
  return lhs.robot_control == rhs.robot_control;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::dsr_msgs::SetRobotControlRequest_<ContainerAllocator1> & lhs, const ::dsr_msgs::SetRobotControlRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace dsr_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::SetRobotControlRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::SetRobotControlRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::SetRobotControlRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::SetRobotControlRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::SetRobotControlRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::SetRobotControlRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dsr_msgs::SetRobotControlRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "69dab02916cb4890b887d4a33beaa620";
  }

  static const char* value(const ::dsr_msgs::SetRobotControlRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x69dab02916cb4890ULL;
  static const uint64_t static_value2 = 0xb887d4a33beaa620ULL;
};

template<class ContainerAllocator>
struct DataType< ::dsr_msgs::SetRobotControlRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dsr_msgs/SetRobotControlRequest";
  }

  static const char* value(const ::dsr_msgs::SetRobotControlRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dsr_msgs::SetRobotControlRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#____________________________________________________________________________________________\n"
"# set_robot_control\n"
"#____________________________________________________________________________________________\n"
"\n"
"int8 robot_control # 0 : CONTROL_INIT_CONFIG\n"
"                   # 1 : CONTROL_ENABLE_OPERATION\n"
"                   # 2 : CONTROL_RESET_SAFET_STOP\n"
"                   # 3 : CONTROL_RESET_SAFE_STOP = CONTROL_RESET_SAFET_STOP,\n"
"                   # 4 : CONTROL_RESET_SAFET_OFF,\n"
"                   # 5 : CONTROL_RESET_SAFE_OFF = CONTROL_RESET_SAFET_OFF,\n"
"                   # 6 : CONTROL_SERVO_ON = CONTROL_RESET_SAFET_OFF,\n"
"                   # 7 : CONTROL_RECOVERY_SAFE_STOP,\n"
"                   # 8 : CONTROL_RECOVERY_SAFE_OFF,\n"
"                   # 9 : CONTROL_RECOVERY_BACKDRIVE,\n"
"                   # 10: CONTROL_RESET_RECOVERY,\n"
"                   # 11: CONTROL_LAST\n"
;
  }

  static const char* value(const ::dsr_msgs::SetRobotControlRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dsr_msgs::SetRobotControlRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.robot_control);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SetRobotControlRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dsr_msgs::SetRobotControlRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dsr_msgs::SetRobotControlRequest_<ContainerAllocator>& v)
  {
    s << indent << "robot_control: ";
    Printer<int8_t>::stream(s, indent + "  ", v.robot_control);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DSR_MSGS_MESSAGE_SETROBOTCONTROLREQUEST_H
