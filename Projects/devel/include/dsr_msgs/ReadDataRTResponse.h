// Generated by gencpp from file dsr_msgs/ReadDataRTResponse.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_READDATARTRESPONSE_H
#define DSR_MSGS_MESSAGE_READDATARTRESPONSE_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <dsr_msgs/RobotStateRT.h>

namespace dsr_msgs
{
template <class ContainerAllocator>
struct ReadDataRTResponse_
{
  typedef ReadDataRTResponse_<ContainerAllocator> Type;

  ReadDataRTResponse_()
    : data()  {
    }
  ReadDataRTResponse_(const ContainerAllocator& _alloc)
    : data(_alloc)  {
  (void)_alloc;
    }



   typedef  ::dsr_msgs::RobotStateRT_<ContainerAllocator>  _data_type;
  _data_type data;





  typedef boost::shared_ptr< ::dsr_msgs::ReadDataRTResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dsr_msgs::ReadDataRTResponse_<ContainerAllocator> const> ConstPtr;

}; // struct ReadDataRTResponse_

typedef ::dsr_msgs::ReadDataRTResponse_<std::allocator<void> > ReadDataRTResponse;

typedef boost::shared_ptr< ::dsr_msgs::ReadDataRTResponse > ReadDataRTResponsePtr;
typedef boost::shared_ptr< ::dsr_msgs::ReadDataRTResponse const> ReadDataRTResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dsr_msgs::ReadDataRTResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dsr_msgs::ReadDataRTResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::dsr_msgs::ReadDataRTResponse_<ContainerAllocator1> & lhs, const ::dsr_msgs::ReadDataRTResponse_<ContainerAllocator2> & rhs)
{
  return lhs.data == rhs.data;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::dsr_msgs::ReadDataRTResponse_<ContainerAllocator1> & lhs, const ::dsr_msgs::ReadDataRTResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace dsr_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::ReadDataRTResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::ReadDataRTResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::ReadDataRTResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::ReadDataRTResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::ReadDataRTResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::ReadDataRTResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dsr_msgs::ReadDataRTResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "1e1cb5234a76f1e708ea68842792bed5";
  }

  static const char* value(const ::dsr_msgs::ReadDataRTResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x1e1cb5234a76f1e7ULL;
  static const uint64_t static_value2 = 0x08ea68842792bed5ULL;
};

template<class ContainerAllocator>
struct DataType< ::dsr_msgs::ReadDataRTResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dsr_msgs/ReadDataRTResponse";
  }

  static const char* value(const ::dsr_msgs::ReadDataRTResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dsr_msgs::ReadDataRTResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "RobotStateRT       data\n"
"\n"
"================================================================================\n"
"MSG: dsr_msgs/RobotStateRT\n"
"# timestamp at the data of data acquisition\n"
"float64                      time_stamp\n"
"# actual joint position from incremental encoder at motor side(used for control) [deg]\n"
"float64[6]                   actual_joint_position\n"
"# actual joint position from absolute encoder at link side (used for exact link position) [deg]\n"
"float64[6]                   actual_joint_position_abs\n"
"# actual joint velocity from incremental encoder at motor side [deg/s]\n"
"float64[6]                   actual_joint_velocity\n"
"# actual joint velocity from absolute encoder at link side [deg/s]\n"
"float64[6]                   actual_joint_velocity_abs\n"
"# actual robot tcp position w.r.t. base coordinates: (x, y, z, a, b, c), where (a, b, c) follows Euler ZYZ notation [mm, deg]\n"
"float64[6]                   actual_tcp_position\n"
"# actual robot tcp velocity w.r.t. base coordinates [mm, deg/s]\n"
"float64[6]                   actual_tcp_velocity\n"
"# actual robot flange position w.r.t. base coordinates: (x, y, z, a, b, c), where (a, b, c) follows Euler ZYZ notation [mm, deg]\n"
"float64[6]                   actual_flange_position\n"
"# robot flange velocity w.r.t. base coordinates [mm, deg/s]\n"
"float64[6]                   actual_flange_velocity\n"
"# actual motor torque applying gear ratio = gear_ratio * current2torque_constant * motor current [Nm]\n"
"float64[6]                   actual_motor_torque\n"
"# estimated joint torque by robot controller [Nm]\n"
"float64[6]                   actual_joint_torque\n"
"# calibrated joint torque sensor data [Nm]\n"
"float64[6]                   raw_joint_torque\n"
"# calibrated force torque sensor data w.r.t. flange coordinates [N, Nm]\n"
"float64[6]                   raw_force_torque\n"
"# estimated external joint torque [Nm]\n"
"float64[6]                   external_joint_torque\n"
"# estimated tcp force w.r.t. base coordinates [N, Nm] \n"
"float64[6]                   external_tcp_force\n"
"# target joint position [deg]\n"
"float64[6]                   target_joint_position\n"
"# target joint velocity [deg/s]\n"
"float64[6]                   target_joint_velocity\n"
"# target joint acceleration [deg/s^2] \n"
"float64[6]                   target_joint_acceleration\n"
"# target motor torque [Nm] \n"
"float64[6]                   target_motor_torque\n"
"# target tcp position w.r.t. base coordinates: (x, y, z, a, b, c), where (a, b, c) follows Euler ZYZ notation [mm, deg] \n"
"float64[6]                   target_tcp_position\n"
"# target tcp velocity w.r.t. base coordinates [mm, deg/s]\n"
"float64[6]                   target_tcp_velocity\n"
"# jacobian matrix=J(q) w.r.t. base coordinates\n"
"std_msgs/Float64MultiArray[] jacobian_matrix\n"
"# gravity torque=g(q) [Nm]\n"
"float64[6]                   gravity_torque\n"
"# coriolis matrix=C(q,q_dot)  [6][6]\n"
"std_msgs/Float64MultiArray[] coriolis_matrix\n"
"# mass matrix=M(q) [6][6]\n"
"std_msgs/Float64MultiArray[] mass_matrix\n"
"# robot configuration \n"
"uint16                       solution_space\n"
"# minimum singular value \n"
"float64                      singularity\n"
"# current operation speed rate(1~100 %) \n"
"float64                      operation_speed_rate\n"
"# joint temperature(celsius) \n"
"float64[6]                   joint_temperature\n"
"# controller digital input(16 channel) \n"
"uint16                       controller_digital_input\n"
"# controller digital output(16 channel) \n"
"uint16                       controller_digital_output\n"
"# controller analog input type(2 channel) \n"
"uint8[2]                      controller_analog_input_type\n"
"# controller analog input(2 channel) \n"
"float64[2]                   controller_analog_input\n"
"# controller analog output type(2 channel) \n"
"uint8[2]                     controller_analog_output_type\n"
"# controller analog output(2 channel) \n"
"float64[2]                   controller_analog_output\n"
"# flange digital input(A-Series: 2 channel, M/H-Series: 6 channel) \n"
"uint8                        flange_digital_input\n"
"# flange digital output(A-Series: 2 channel, M/H-Series: 6 channel) \n"
"uint8                        flange_digital_output\n"
"# flange analog input(A-Series: 2 channel, M/H-Series: 4 channel) \n"
"float64[4]                   flange_analog_input\n"
"# strobe count(increased by 1 when detecting setting edge) \n"
"uint8[2]                     external_encoder_strobe_count\n"
"# external encoder count \n"
"uint16[2]                    external_encoder_count\n"
"# final goal joint position (reserved) \n"
"float64[6]                   goal_joint_position\n"
"# final goal tcp position (reserved) \n"
"float64[6]                   goal_tcp_position\n"
"# ROBOT_MODE_MANUAL(0), ROBOT_MODE_AUTONOMOUS(1), ROBOT_MODE_MEASURE(2) \n"
"uint8                        robot_mode\n"
"# STATE_INITIALIZING(0), STATE_STANDBY(1), STATE_MOVING(2), STATE_SAFE_OFF(3), STATE_TEACHING(4), STATE_SAFE_STOP(5), STATE_EMERGENCY_STOP, STATE_HOMMING, STATE_RECOVERY, STATE_SAFE_STOP2, STATE_SAFE_OFF2, \n"
"uint8                        robot_state\n"
"# position control mode, torque mode \n"
"uint16                       control_mode\n"
"# Reserved \n"
"uint8[256]                   reserved\n"
"================================================================================\n"
"MSG: std_msgs/Float64MultiArray\n"
"# Please look at the MultiArrayLayout message definition for\n"
"# documentation on all multiarrays.\n"
"\n"
"MultiArrayLayout  layout        # specification of data layout\n"
"float64[]         data          # array of data\n"
"\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/MultiArrayLayout\n"
"# The multiarray declares a generic multi-dimensional array of a\n"
"# particular data type.  Dimensions are ordered from outer most\n"
"# to inner most.\n"
"\n"
"MultiArrayDimension[] dim # Array of dimension properties\n"
"uint32 data_offset        # padding elements at front of data\n"
"\n"
"# Accessors should ALWAYS be written in terms of dimension stride\n"
"# and specified outer-most dimension first.\n"
"# \n"
"# multiarray(i,j,k) = data[data_offset + dim_stride[1]*i + dim_stride[2]*j + k]\n"
"#\n"
"# A standard, 3-channel 640x480 image with interleaved color channels\n"
"# would be specified as:\n"
"#\n"
"# dim[0].label  = \"height\"\n"
"# dim[0].size   = 480\n"
"# dim[0].stride = 3*640*480 = 921600  (note dim[0] stride is just size of image)\n"
"# dim[1].label  = \"width\"\n"
"# dim[1].size   = 640\n"
"# dim[1].stride = 3*640 = 1920\n"
"# dim[2].label  = \"channel\"\n"
"# dim[2].size   = 3\n"
"# dim[2].stride = 3\n"
"#\n"
"# multiarray(i,j,k) refers to the ith row, jth column, and kth channel.\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/MultiArrayDimension\n"
"string label   # label of given dimension\n"
"uint32 size    # size of given dimension (in type units)\n"
"uint32 stride  # stride of given dimension\n"
;
  }

  static const char* value(const ::dsr_msgs::ReadDataRTResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dsr_msgs::ReadDataRTResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.data);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ReadDataRTResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dsr_msgs::ReadDataRTResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dsr_msgs::ReadDataRTResponse_<ContainerAllocator>& v)
  {
    s << indent << "data: ";
    s << std::endl;
    Printer< ::dsr_msgs::RobotStateRT_<ContainerAllocator> >::stream(s, indent + "  ", v.data);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DSR_MSGS_MESSAGE_READDATARTRESPONSE_H
