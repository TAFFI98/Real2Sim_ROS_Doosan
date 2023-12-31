// Generated by gencpp from file dsr_msgs/MoveSplineJointRequest.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_MOVESPLINEJOINTREQUEST_H
#define DSR_MSGS_MESSAGE_MOVESPLINEJOINTREQUEST_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Float64MultiArray.h>

namespace dsr_msgs
{
template <class ContainerAllocator>
struct MoveSplineJointRequest_
{
  typedef MoveSplineJointRequest_<ContainerAllocator> Type;

  MoveSplineJointRequest_()
    : pos()
    , posCnt(0)
    , vel()
    , acc()
    , time(0.0)
    , mode(0)
    , syncType(0)  {
      vel.assign(0.0);

      acc.assign(0.0);
  }
  MoveSplineJointRequest_(const ContainerAllocator& _alloc)
    : pos(_alloc)
    , posCnt(0)
    , vel()
    , acc()
    , time(0.0)
    , mode(0)
    , syncType(0)  {
  (void)_alloc;
      vel.assign(0.0);

      acc.assign(0.0);
  }



   typedef std::vector< ::std_msgs::Float64MultiArray_<ContainerAllocator> , typename std::allocator_traits<ContainerAllocator>::template rebind_alloc< ::std_msgs::Float64MultiArray_<ContainerAllocator> >> _pos_type;
  _pos_type pos;

   typedef int8_t _posCnt_type;
  _posCnt_type posCnt;

   typedef boost::array<double, 6>  _vel_type;
  _vel_type vel;

   typedef boost::array<double, 6>  _acc_type;
  _acc_type acc;

   typedef double _time_type;
  _time_type time;

   typedef int8_t _mode_type;
  _mode_type mode;

   typedef int8_t _syncType_type;
  _syncType_type syncType;





  typedef boost::shared_ptr< ::dsr_msgs::MoveSplineJointRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dsr_msgs::MoveSplineJointRequest_<ContainerAllocator> const> ConstPtr;

}; // struct MoveSplineJointRequest_

typedef ::dsr_msgs::MoveSplineJointRequest_<std::allocator<void> > MoveSplineJointRequest;

typedef boost::shared_ptr< ::dsr_msgs::MoveSplineJointRequest > MoveSplineJointRequestPtr;
typedef boost::shared_ptr< ::dsr_msgs::MoveSplineJointRequest const> MoveSplineJointRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dsr_msgs::MoveSplineJointRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dsr_msgs::MoveSplineJointRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::dsr_msgs::MoveSplineJointRequest_<ContainerAllocator1> & lhs, const ::dsr_msgs::MoveSplineJointRequest_<ContainerAllocator2> & rhs)
{
  return lhs.pos == rhs.pos &&
    lhs.posCnt == rhs.posCnt &&
    lhs.vel == rhs.vel &&
    lhs.acc == rhs.acc &&
    lhs.time == rhs.time &&
    lhs.mode == rhs.mode &&
    lhs.syncType == rhs.syncType;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::dsr_msgs::MoveSplineJointRequest_<ContainerAllocator1> & lhs, const ::dsr_msgs::MoveSplineJointRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace dsr_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::MoveSplineJointRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::MoveSplineJointRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::MoveSplineJointRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::MoveSplineJointRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::MoveSplineJointRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::MoveSplineJointRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dsr_msgs::MoveSplineJointRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "e1900c7787fce969908abb61dfa5501e";
  }

  static const char* value(const ::dsr_msgs::MoveSplineJointRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xe1900c7787fce969ULL;
  static const uint64_t static_value2 = 0x908abb61dfa5501eULL;
};

template<class ContainerAllocator>
struct DataType< ::dsr_msgs::MoveSplineJointRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dsr_msgs/MoveSplineJointRequest";
  }

  static const char* value(const ::dsr_msgs::MoveSplineJointRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dsr_msgs::MoveSplineJointRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#____________________________________________________________________________________________\n"
"# move_spline_joint  \n"
"###float64[100][6] pos         # target\n"
"#____________________________________________________________________________________________\n"
"\n"
"std_msgs/Float64MultiArray[] pos         # target [100][6] pos\n"
"int8       posCnt                        # target cnt \n"
"float64[6] vel                           # set joint velocity: [deg/sec]\n"
"float64[6] acc                           # set joint acceleration: [deg/sec2] \n"
"float64    time #= 0.0                   # Time [sec] \n"
"int8       mode #= 0                     # MOVE_MODE_ABSOLUTE=0, MOVE_MODE_RELATIVE=1 \n"
"int8       syncType #=0                  # SYNC = 0, ASYNC = 1\n"
"\n"
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

  static const char* value(const ::dsr_msgs::MoveSplineJointRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dsr_msgs::MoveSplineJointRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.pos);
      stream.next(m.posCnt);
      stream.next(m.vel);
      stream.next(m.acc);
      stream.next(m.time);
      stream.next(m.mode);
      stream.next(m.syncType);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct MoveSplineJointRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dsr_msgs::MoveSplineJointRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dsr_msgs::MoveSplineJointRequest_<ContainerAllocator>& v)
  {
    s << indent << "pos[]" << std::endl;
    for (size_t i = 0; i < v.pos.size(); ++i)
    {
      s << indent << "  pos[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::std_msgs::Float64MultiArray_<ContainerAllocator> >::stream(s, indent + "    ", v.pos[i]);
    }
    s << indent << "posCnt: ";
    Printer<int8_t>::stream(s, indent + "  ", v.posCnt);
    s << indent << "vel[]" << std::endl;
    for (size_t i = 0; i < v.vel.size(); ++i)
    {
      s << indent << "  vel[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.vel[i]);
    }
    s << indent << "acc[]" << std::endl;
    for (size_t i = 0; i < v.acc.size(); ++i)
    {
      s << indent << "  acc[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.acc[i]);
    }
    s << indent << "time: ";
    Printer<double>::stream(s, indent + "  ", v.time);
    s << indent << "mode: ";
    Printer<int8_t>::stream(s, indent + "  ", v.mode);
    s << indent << "syncType: ";
    Printer<int8_t>::stream(s, indent + "  ", v.syncType);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DSR_MSGS_MESSAGE_MOVESPLINEJOINTREQUEST_H
