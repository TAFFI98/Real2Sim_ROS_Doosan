// Generated by gencpp from file dsr_msgs/RobotStateRT.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_ROBOTSTATERT_H
#define DSR_MSGS_MESSAGE_ROBOTSTATERT_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Float64MultiArray.h>
#include <std_msgs/Float64MultiArray.h>
#include <std_msgs/Float64MultiArray.h>

namespace dsr_msgs
{
template <class ContainerAllocator>
struct RobotStateRT_
{
  typedef RobotStateRT_<ContainerAllocator> Type;

  RobotStateRT_()
    : time_stamp(0.0)
    , actual_joint_position()
    , actual_joint_position_abs()
    , actual_joint_velocity()
    , actual_joint_velocity_abs()
    , actual_tcp_position()
    , actual_tcp_velocity()
    , actual_flange_position()
    , actual_flange_velocity()
    , actual_motor_torque()
    , actual_joint_torque()
    , raw_joint_torque()
    , raw_force_torque()
    , external_joint_torque()
    , external_tcp_force()
    , target_joint_position()
    , target_joint_velocity()
    , target_joint_acceleration()
    , target_motor_torque()
    , target_tcp_position()
    , target_tcp_velocity()
    , jacobian_matrix()
    , gravity_torque()
    , coriolis_matrix()
    , mass_matrix()
    , solution_space(0)
    , singularity(0.0)
    , operation_speed_rate(0.0)
    , joint_temperature()
    , controller_digital_input(0)
    , controller_digital_output(0)
    , controller_analog_input_type()
    , controller_analog_input()
    , controller_analog_output_type()
    , controller_analog_output()
    , flange_digital_input(0)
    , flange_digital_output(0)
    , flange_analog_input()
    , external_encoder_strobe_count()
    , external_encoder_count()
    , goal_joint_position()
    , goal_tcp_position()
    , robot_mode(0)
    , robot_state(0)
    , control_mode(0)
    , reserved()  {
      actual_joint_position.assign(0.0);

      actual_joint_position_abs.assign(0.0);

      actual_joint_velocity.assign(0.0);

      actual_joint_velocity_abs.assign(0.0);

      actual_tcp_position.assign(0.0);

      actual_tcp_velocity.assign(0.0);

      actual_flange_position.assign(0.0);

      actual_flange_velocity.assign(0.0);

      actual_motor_torque.assign(0.0);

      actual_joint_torque.assign(0.0);

      raw_joint_torque.assign(0.0);

      raw_force_torque.assign(0.0);

      external_joint_torque.assign(0.0);

      external_tcp_force.assign(0.0);

      target_joint_position.assign(0.0);

      target_joint_velocity.assign(0.0);

      target_joint_acceleration.assign(0.0);

      target_motor_torque.assign(0.0);

      target_tcp_position.assign(0.0);

      target_tcp_velocity.assign(0.0);

      gravity_torque.assign(0.0);

      joint_temperature.assign(0.0);

      controller_analog_input_type.assign(0);

      controller_analog_input.assign(0.0);

      controller_analog_output_type.assign(0);

      controller_analog_output.assign(0.0);

      flange_analog_input.assign(0.0);

      external_encoder_strobe_count.assign(0);

      external_encoder_count.assign(0);

      goal_joint_position.assign(0.0);

      goal_tcp_position.assign(0.0);

      reserved.assign(0);
  }
  RobotStateRT_(const ContainerAllocator& _alloc)
    : time_stamp(0.0)
    , actual_joint_position()
    , actual_joint_position_abs()
    , actual_joint_velocity()
    , actual_joint_velocity_abs()
    , actual_tcp_position()
    , actual_tcp_velocity()
    , actual_flange_position()
    , actual_flange_velocity()
    , actual_motor_torque()
    , actual_joint_torque()
    , raw_joint_torque()
    , raw_force_torque()
    , external_joint_torque()
    , external_tcp_force()
    , target_joint_position()
    , target_joint_velocity()
    , target_joint_acceleration()
    , target_motor_torque()
    , target_tcp_position()
    , target_tcp_velocity()
    , jacobian_matrix(_alloc)
    , gravity_torque()
    , coriolis_matrix(_alloc)
    , mass_matrix(_alloc)
    , solution_space(0)
    , singularity(0.0)
    , operation_speed_rate(0.0)
    , joint_temperature()
    , controller_digital_input(0)
    , controller_digital_output(0)
    , controller_analog_input_type()
    , controller_analog_input()
    , controller_analog_output_type()
    , controller_analog_output()
    , flange_digital_input(0)
    , flange_digital_output(0)
    , flange_analog_input()
    , external_encoder_strobe_count()
    , external_encoder_count()
    , goal_joint_position()
    , goal_tcp_position()
    , robot_mode(0)
    , robot_state(0)
    , control_mode(0)
    , reserved()  {
  (void)_alloc;
      actual_joint_position.assign(0.0);

      actual_joint_position_abs.assign(0.0);

      actual_joint_velocity.assign(0.0);

      actual_joint_velocity_abs.assign(0.0);

      actual_tcp_position.assign(0.0);

      actual_tcp_velocity.assign(0.0);

      actual_flange_position.assign(0.0);

      actual_flange_velocity.assign(0.0);

      actual_motor_torque.assign(0.0);

      actual_joint_torque.assign(0.0);

      raw_joint_torque.assign(0.0);

      raw_force_torque.assign(0.0);

      external_joint_torque.assign(0.0);

      external_tcp_force.assign(0.0);

      target_joint_position.assign(0.0);

      target_joint_velocity.assign(0.0);

      target_joint_acceleration.assign(0.0);

      target_motor_torque.assign(0.0);

      target_tcp_position.assign(0.0);

      target_tcp_velocity.assign(0.0);

      gravity_torque.assign(0.0);

      joint_temperature.assign(0.0);

      controller_analog_input_type.assign(0);

      controller_analog_input.assign(0.0);

      controller_analog_output_type.assign(0);

      controller_analog_output.assign(0.0);

      flange_analog_input.assign(0.0);

      external_encoder_strobe_count.assign(0);

      external_encoder_count.assign(0);

      goal_joint_position.assign(0.0);

      goal_tcp_position.assign(0.0);

      reserved.assign(0);
  }



   typedef double _time_stamp_type;
  _time_stamp_type time_stamp;

   typedef boost::array<double, 6>  _actual_joint_position_type;
  _actual_joint_position_type actual_joint_position;

   typedef boost::array<double, 6>  _actual_joint_position_abs_type;
  _actual_joint_position_abs_type actual_joint_position_abs;

   typedef boost::array<double, 6>  _actual_joint_velocity_type;
  _actual_joint_velocity_type actual_joint_velocity;

   typedef boost::array<double, 6>  _actual_joint_velocity_abs_type;
  _actual_joint_velocity_abs_type actual_joint_velocity_abs;

   typedef boost::array<double, 6>  _actual_tcp_position_type;
  _actual_tcp_position_type actual_tcp_position;

   typedef boost::array<double, 6>  _actual_tcp_velocity_type;
  _actual_tcp_velocity_type actual_tcp_velocity;

   typedef boost::array<double, 6>  _actual_flange_position_type;
  _actual_flange_position_type actual_flange_position;

   typedef boost::array<double, 6>  _actual_flange_velocity_type;
  _actual_flange_velocity_type actual_flange_velocity;

   typedef boost::array<double, 6>  _actual_motor_torque_type;
  _actual_motor_torque_type actual_motor_torque;

   typedef boost::array<double, 6>  _actual_joint_torque_type;
  _actual_joint_torque_type actual_joint_torque;

   typedef boost::array<double, 6>  _raw_joint_torque_type;
  _raw_joint_torque_type raw_joint_torque;

   typedef boost::array<double, 6>  _raw_force_torque_type;
  _raw_force_torque_type raw_force_torque;

   typedef boost::array<double, 6>  _external_joint_torque_type;
  _external_joint_torque_type external_joint_torque;

   typedef boost::array<double, 6>  _external_tcp_force_type;
  _external_tcp_force_type external_tcp_force;

   typedef boost::array<double, 6>  _target_joint_position_type;
  _target_joint_position_type target_joint_position;

   typedef boost::array<double, 6>  _target_joint_velocity_type;
  _target_joint_velocity_type target_joint_velocity;

   typedef boost::array<double, 6>  _target_joint_acceleration_type;
  _target_joint_acceleration_type target_joint_acceleration;

   typedef boost::array<double, 6>  _target_motor_torque_type;
  _target_motor_torque_type target_motor_torque;

   typedef boost::array<double, 6>  _target_tcp_position_type;
  _target_tcp_position_type target_tcp_position;

   typedef boost::array<double, 6>  _target_tcp_velocity_type;
  _target_tcp_velocity_type target_tcp_velocity;

   typedef std::vector< ::std_msgs::Float64MultiArray_<ContainerAllocator> , typename std::allocator_traits<ContainerAllocator>::template rebind_alloc< ::std_msgs::Float64MultiArray_<ContainerAllocator> >> _jacobian_matrix_type;
  _jacobian_matrix_type jacobian_matrix;

   typedef boost::array<double, 6>  _gravity_torque_type;
  _gravity_torque_type gravity_torque;

   typedef std::vector< ::std_msgs::Float64MultiArray_<ContainerAllocator> , typename std::allocator_traits<ContainerAllocator>::template rebind_alloc< ::std_msgs::Float64MultiArray_<ContainerAllocator> >> _coriolis_matrix_type;
  _coriolis_matrix_type coriolis_matrix;

   typedef std::vector< ::std_msgs::Float64MultiArray_<ContainerAllocator> , typename std::allocator_traits<ContainerAllocator>::template rebind_alloc< ::std_msgs::Float64MultiArray_<ContainerAllocator> >> _mass_matrix_type;
  _mass_matrix_type mass_matrix;

   typedef uint16_t _solution_space_type;
  _solution_space_type solution_space;

   typedef double _singularity_type;
  _singularity_type singularity;

   typedef double _operation_speed_rate_type;
  _operation_speed_rate_type operation_speed_rate;

   typedef boost::array<double, 6>  _joint_temperature_type;
  _joint_temperature_type joint_temperature;

   typedef uint16_t _controller_digital_input_type;
  _controller_digital_input_type controller_digital_input;

   typedef uint16_t _controller_digital_output_type;
  _controller_digital_output_type controller_digital_output;

   typedef boost::array<uint8_t, 2>  _controller_analog_input_type_type;
  _controller_analog_input_type_type controller_analog_input_type;

   typedef boost::array<double, 2>  _controller_analog_input_type;
  _controller_analog_input_type controller_analog_input;

   typedef boost::array<uint8_t, 2>  _controller_analog_output_type_type;
  _controller_analog_output_type_type controller_analog_output_type;

   typedef boost::array<double, 2>  _controller_analog_output_type;
  _controller_analog_output_type controller_analog_output;

   typedef uint8_t _flange_digital_input_type;
  _flange_digital_input_type flange_digital_input;

   typedef uint8_t _flange_digital_output_type;
  _flange_digital_output_type flange_digital_output;

   typedef boost::array<double, 4>  _flange_analog_input_type;
  _flange_analog_input_type flange_analog_input;

   typedef boost::array<uint8_t, 2>  _external_encoder_strobe_count_type;
  _external_encoder_strobe_count_type external_encoder_strobe_count;

   typedef boost::array<uint16_t, 2>  _external_encoder_count_type;
  _external_encoder_count_type external_encoder_count;

   typedef boost::array<double, 6>  _goal_joint_position_type;
  _goal_joint_position_type goal_joint_position;

   typedef boost::array<double, 6>  _goal_tcp_position_type;
  _goal_tcp_position_type goal_tcp_position;

   typedef uint8_t _robot_mode_type;
  _robot_mode_type robot_mode;

   typedef uint8_t _robot_state_type;
  _robot_state_type robot_state;

   typedef uint16_t _control_mode_type;
  _control_mode_type control_mode;

   typedef boost::array<uint8_t, 256>  _reserved_type;
  _reserved_type reserved;





  typedef boost::shared_ptr< ::dsr_msgs::RobotStateRT_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dsr_msgs::RobotStateRT_<ContainerAllocator> const> ConstPtr;

}; // struct RobotStateRT_

typedef ::dsr_msgs::RobotStateRT_<std::allocator<void> > RobotStateRT;

typedef boost::shared_ptr< ::dsr_msgs::RobotStateRT > RobotStateRTPtr;
typedef boost::shared_ptr< ::dsr_msgs::RobotStateRT const> RobotStateRTConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dsr_msgs::RobotStateRT_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dsr_msgs::RobotStateRT_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::dsr_msgs::RobotStateRT_<ContainerAllocator1> & lhs, const ::dsr_msgs::RobotStateRT_<ContainerAllocator2> & rhs)
{
  return lhs.time_stamp == rhs.time_stamp &&
    lhs.actual_joint_position == rhs.actual_joint_position &&
    lhs.actual_joint_position_abs == rhs.actual_joint_position_abs &&
    lhs.actual_joint_velocity == rhs.actual_joint_velocity &&
    lhs.actual_joint_velocity_abs == rhs.actual_joint_velocity_abs &&
    lhs.actual_tcp_position == rhs.actual_tcp_position &&
    lhs.actual_tcp_velocity == rhs.actual_tcp_velocity &&
    lhs.actual_flange_position == rhs.actual_flange_position &&
    lhs.actual_flange_velocity == rhs.actual_flange_velocity &&
    lhs.actual_motor_torque == rhs.actual_motor_torque &&
    lhs.actual_joint_torque == rhs.actual_joint_torque &&
    lhs.raw_joint_torque == rhs.raw_joint_torque &&
    lhs.raw_force_torque == rhs.raw_force_torque &&
    lhs.external_joint_torque == rhs.external_joint_torque &&
    lhs.external_tcp_force == rhs.external_tcp_force &&
    lhs.target_joint_position == rhs.target_joint_position &&
    lhs.target_joint_velocity == rhs.target_joint_velocity &&
    lhs.target_joint_acceleration == rhs.target_joint_acceleration &&
    lhs.target_motor_torque == rhs.target_motor_torque &&
    lhs.target_tcp_position == rhs.target_tcp_position &&
    lhs.target_tcp_velocity == rhs.target_tcp_velocity &&
    lhs.jacobian_matrix == rhs.jacobian_matrix &&
    lhs.gravity_torque == rhs.gravity_torque &&
    lhs.coriolis_matrix == rhs.coriolis_matrix &&
    lhs.mass_matrix == rhs.mass_matrix &&
    lhs.solution_space == rhs.solution_space &&
    lhs.singularity == rhs.singularity &&
    lhs.operation_speed_rate == rhs.operation_speed_rate &&
    lhs.joint_temperature == rhs.joint_temperature &&
    lhs.controller_digital_input == rhs.controller_digital_input &&
    lhs.controller_digital_output == rhs.controller_digital_output &&
    lhs.controller_analog_input_type == rhs.controller_analog_input_type &&
    lhs.controller_analog_input == rhs.controller_analog_input &&
    lhs.controller_analog_output_type == rhs.controller_analog_output_type &&
    lhs.controller_analog_output == rhs.controller_analog_output &&
    lhs.flange_digital_input == rhs.flange_digital_input &&
    lhs.flange_digital_output == rhs.flange_digital_output &&
    lhs.flange_analog_input == rhs.flange_analog_input &&
    lhs.external_encoder_strobe_count == rhs.external_encoder_strobe_count &&
    lhs.external_encoder_count == rhs.external_encoder_count &&
    lhs.goal_joint_position == rhs.goal_joint_position &&
    lhs.goal_tcp_position == rhs.goal_tcp_position &&
    lhs.robot_mode == rhs.robot_mode &&
    lhs.robot_state == rhs.robot_state &&
    lhs.control_mode == rhs.control_mode &&
    lhs.reserved == rhs.reserved;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::dsr_msgs::RobotStateRT_<ContainerAllocator1> & lhs, const ::dsr_msgs::RobotStateRT_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace dsr_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::RobotStateRT_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::RobotStateRT_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::RobotStateRT_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::RobotStateRT_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::RobotStateRT_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::RobotStateRT_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dsr_msgs::RobotStateRT_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3fc4bdbba50c12ddf9126a58ad825fc4";
  }

  static const char* value(const ::dsr_msgs::RobotStateRT_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3fc4bdbba50c12ddULL;
  static const uint64_t static_value2 = 0xf9126a58ad825fc4ULL;
};

template<class ContainerAllocator>
struct DataType< ::dsr_msgs::RobotStateRT_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dsr_msgs/RobotStateRT";
  }

  static const char* value(const ::dsr_msgs::RobotStateRT_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dsr_msgs::RobotStateRT_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# timestamp at the data of data acquisition\n"
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

  static const char* value(const ::dsr_msgs::RobotStateRT_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dsr_msgs::RobotStateRT_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.time_stamp);
      stream.next(m.actual_joint_position);
      stream.next(m.actual_joint_position_abs);
      stream.next(m.actual_joint_velocity);
      stream.next(m.actual_joint_velocity_abs);
      stream.next(m.actual_tcp_position);
      stream.next(m.actual_tcp_velocity);
      stream.next(m.actual_flange_position);
      stream.next(m.actual_flange_velocity);
      stream.next(m.actual_motor_torque);
      stream.next(m.actual_joint_torque);
      stream.next(m.raw_joint_torque);
      stream.next(m.raw_force_torque);
      stream.next(m.external_joint_torque);
      stream.next(m.external_tcp_force);
      stream.next(m.target_joint_position);
      stream.next(m.target_joint_velocity);
      stream.next(m.target_joint_acceleration);
      stream.next(m.target_motor_torque);
      stream.next(m.target_tcp_position);
      stream.next(m.target_tcp_velocity);
      stream.next(m.jacobian_matrix);
      stream.next(m.gravity_torque);
      stream.next(m.coriolis_matrix);
      stream.next(m.mass_matrix);
      stream.next(m.solution_space);
      stream.next(m.singularity);
      stream.next(m.operation_speed_rate);
      stream.next(m.joint_temperature);
      stream.next(m.controller_digital_input);
      stream.next(m.controller_digital_output);
      stream.next(m.controller_analog_input_type);
      stream.next(m.controller_analog_input);
      stream.next(m.controller_analog_output_type);
      stream.next(m.controller_analog_output);
      stream.next(m.flange_digital_input);
      stream.next(m.flange_digital_output);
      stream.next(m.flange_analog_input);
      stream.next(m.external_encoder_strobe_count);
      stream.next(m.external_encoder_count);
      stream.next(m.goal_joint_position);
      stream.next(m.goal_tcp_position);
      stream.next(m.robot_mode);
      stream.next(m.robot_state);
      stream.next(m.control_mode);
      stream.next(m.reserved);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct RobotStateRT_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dsr_msgs::RobotStateRT_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dsr_msgs::RobotStateRT_<ContainerAllocator>& v)
  {
    s << indent << "time_stamp: ";
    Printer<double>::stream(s, indent + "  ", v.time_stamp);
    s << indent << "actual_joint_position[]" << std::endl;
    for (size_t i = 0; i < v.actual_joint_position.size(); ++i)
    {
      s << indent << "  actual_joint_position[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.actual_joint_position[i]);
    }
    s << indent << "actual_joint_position_abs[]" << std::endl;
    for (size_t i = 0; i < v.actual_joint_position_abs.size(); ++i)
    {
      s << indent << "  actual_joint_position_abs[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.actual_joint_position_abs[i]);
    }
    s << indent << "actual_joint_velocity[]" << std::endl;
    for (size_t i = 0; i < v.actual_joint_velocity.size(); ++i)
    {
      s << indent << "  actual_joint_velocity[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.actual_joint_velocity[i]);
    }
    s << indent << "actual_joint_velocity_abs[]" << std::endl;
    for (size_t i = 0; i < v.actual_joint_velocity_abs.size(); ++i)
    {
      s << indent << "  actual_joint_velocity_abs[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.actual_joint_velocity_abs[i]);
    }
    s << indent << "actual_tcp_position[]" << std::endl;
    for (size_t i = 0; i < v.actual_tcp_position.size(); ++i)
    {
      s << indent << "  actual_tcp_position[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.actual_tcp_position[i]);
    }
    s << indent << "actual_tcp_velocity[]" << std::endl;
    for (size_t i = 0; i < v.actual_tcp_velocity.size(); ++i)
    {
      s << indent << "  actual_tcp_velocity[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.actual_tcp_velocity[i]);
    }
    s << indent << "actual_flange_position[]" << std::endl;
    for (size_t i = 0; i < v.actual_flange_position.size(); ++i)
    {
      s << indent << "  actual_flange_position[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.actual_flange_position[i]);
    }
    s << indent << "actual_flange_velocity[]" << std::endl;
    for (size_t i = 0; i < v.actual_flange_velocity.size(); ++i)
    {
      s << indent << "  actual_flange_velocity[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.actual_flange_velocity[i]);
    }
    s << indent << "actual_motor_torque[]" << std::endl;
    for (size_t i = 0; i < v.actual_motor_torque.size(); ++i)
    {
      s << indent << "  actual_motor_torque[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.actual_motor_torque[i]);
    }
    s << indent << "actual_joint_torque[]" << std::endl;
    for (size_t i = 0; i < v.actual_joint_torque.size(); ++i)
    {
      s << indent << "  actual_joint_torque[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.actual_joint_torque[i]);
    }
    s << indent << "raw_joint_torque[]" << std::endl;
    for (size_t i = 0; i < v.raw_joint_torque.size(); ++i)
    {
      s << indent << "  raw_joint_torque[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.raw_joint_torque[i]);
    }
    s << indent << "raw_force_torque[]" << std::endl;
    for (size_t i = 0; i < v.raw_force_torque.size(); ++i)
    {
      s << indent << "  raw_force_torque[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.raw_force_torque[i]);
    }
    s << indent << "external_joint_torque[]" << std::endl;
    for (size_t i = 0; i < v.external_joint_torque.size(); ++i)
    {
      s << indent << "  external_joint_torque[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.external_joint_torque[i]);
    }
    s << indent << "external_tcp_force[]" << std::endl;
    for (size_t i = 0; i < v.external_tcp_force.size(); ++i)
    {
      s << indent << "  external_tcp_force[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.external_tcp_force[i]);
    }
    s << indent << "target_joint_position[]" << std::endl;
    for (size_t i = 0; i < v.target_joint_position.size(); ++i)
    {
      s << indent << "  target_joint_position[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.target_joint_position[i]);
    }
    s << indent << "target_joint_velocity[]" << std::endl;
    for (size_t i = 0; i < v.target_joint_velocity.size(); ++i)
    {
      s << indent << "  target_joint_velocity[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.target_joint_velocity[i]);
    }
    s << indent << "target_joint_acceleration[]" << std::endl;
    for (size_t i = 0; i < v.target_joint_acceleration.size(); ++i)
    {
      s << indent << "  target_joint_acceleration[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.target_joint_acceleration[i]);
    }
    s << indent << "target_motor_torque[]" << std::endl;
    for (size_t i = 0; i < v.target_motor_torque.size(); ++i)
    {
      s << indent << "  target_motor_torque[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.target_motor_torque[i]);
    }
    s << indent << "target_tcp_position[]" << std::endl;
    for (size_t i = 0; i < v.target_tcp_position.size(); ++i)
    {
      s << indent << "  target_tcp_position[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.target_tcp_position[i]);
    }
    s << indent << "target_tcp_velocity[]" << std::endl;
    for (size_t i = 0; i < v.target_tcp_velocity.size(); ++i)
    {
      s << indent << "  target_tcp_velocity[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.target_tcp_velocity[i]);
    }
    s << indent << "jacobian_matrix[]" << std::endl;
    for (size_t i = 0; i < v.jacobian_matrix.size(); ++i)
    {
      s << indent << "  jacobian_matrix[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::std_msgs::Float64MultiArray_<ContainerAllocator> >::stream(s, indent + "    ", v.jacobian_matrix[i]);
    }
    s << indent << "gravity_torque[]" << std::endl;
    for (size_t i = 0; i < v.gravity_torque.size(); ++i)
    {
      s << indent << "  gravity_torque[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.gravity_torque[i]);
    }
    s << indent << "coriolis_matrix[]" << std::endl;
    for (size_t i = 0; i < v.coriolis_matrix.size(); ++i)
    {
      s << indent << "  coriolis_matrix[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::std_msgs::Float64MultiArray_<ContainerAllocator> >::stream(s, indent + "    ", v.coriolis_matrix[i]);
    }
    s << indent << "mass_matrix[]" << std::endl;
    for (size_t i = 0; i < v.mass_matrix.size(); ++i)
    {
      s << indent << "  mass_matrix[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::std_msgs::Float64MultiArray_<ContainerAllocator> >::stream(s, indent + "    ", v.mass_matrix[i]);
    }
    s << indent << "solution_space: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.solution_space);
    s << indent << "singularity: ";
    Printer<double>::stream(s, indent + "  ", v.singularity);
    s << indent << "operation_speed_rate: ";
    Printer<double>::stream(s, indent + "  ", v.operation_speed_rate);
    s << indent << "joint_temperature[]" << std::endl;
    for (size_t i = 0; i < v.joint_temperature.size(); ++i)
    {
      s << indent << "  joint_temperature[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.joint_temperature[i]);
    }
    s << indent << "controller_digital_input: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.controller_digital_input);
    s << indent << "controller_digital_output: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.controller_digital_output);
    s << indent << "controller_analog_input_type[]" << std::endl;
    for (size_t i = 0; i < v.controller_analog_input_type.size(); ++i)
    {
      s << indent << "  controller_analog_input_type[" << i << "]: ";
      Printer<uint8_t>::stream(s, indent + "  ", v.controller_analog_input_type[i]);
    }
    s << indent << "controller_analog_input[]" << std::endl;
    for (size_t i = 0; i < v.controller_analog_input.size(); ++i)
    {
      s << indent << "  controller_analog_input[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.controller_analog_input[i]);
    }
    s << indent << "controller_analog_output_type[]" << std::endl;
    for (size_t i = 0; i < v.controller_analog_output_type.size(); ++i)
    {
      s << indent << "  controller_analog_output_type[" << i << "]: ";
      Printer<uint8_t>::stream(s, indent + "  ", v.controller_analog_output_type[i]);
    }
    s << indent << "controller_analog_output[]" << std::endl;
    for (size_t i = 0; i < v.controller_analog_output.size(); ++i)
    {
      s << indent << "  controller_analog_output[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.controller_analog_output[i]);
    }
    s << indent << "flange_digital_input: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.flange_digital_input);
    s << indent << "flange_digital_output: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.flange_digital_output);
    s << indent << "flange_analog_input[]" << std::endl;
    for (size_t i = 0; i < v.flange_analog_input.size(); ++i)
    {
      s << indent << "  flange_analog_input[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.flange_analog_input[i]);
    }
    s << indent << "external_encoder_strobe_count[]" << std::endl;
    for (size_t i = 0; i < v.external_encoder_strobe_count.size(); ++i)
    {
      s << indent << "  external_encoder_strobe_count[" << i << "]: ";
      Printer<uint8_t>::stream(s, indent + "  ", v.external_encoder_strobe_count[i]);
    }
    s << indent << "external_encoder_count[]" << std::endl;
    for (size_t i = 0; i < v.external_encoder_count.size(); ++i)
    {
      s << indent << "  external_encoder_count[" << i << "]: ";
      Printer<uint16_t>::stream(s, indent + "  ", v.external_encoder_count[i]);
    }
    s << indent << "goal_joint_position[]" << std::endl;
    for (size_t i = 0; i < v.goal_joint_position.size(); ++i)
    {
      s << indent << "  goal_joint_position[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.goal_joint_position[i]);
    }
    s << indent << "goal_tcp_position[]" << std::endl;
    for (size_t i = 0; i < v.goal_tcp_position.size(); ++i)
    {
      s << indent << "  goal_tcp_position[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.goal_tcp_position[i]);
    }
    s << indent << "robot_mode: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.robot_mode);
    s << indent << "robot_state: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.robot_state);
    s << indent << "control_mode: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.control_mode);
    s << indent << "reserved[]" << std::endl;
    for (size_t i = 0; i < v.reserved.size(); ++i)
    {
      s << indent << "  reserved[" << i << "]: ";
      Printer<uint8_t>::stream(s, indent + "  ", v.reserved[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // DSR_MSGS_MESSAGE_ROBOTSTATERT_H
