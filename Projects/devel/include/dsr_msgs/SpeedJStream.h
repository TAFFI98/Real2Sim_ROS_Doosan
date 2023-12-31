// Generated by gencpp from file dsr_msgs/SpeedJStream.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_SPEEDJSTREAM_H
#define DSR_MSGS_MESSAGE_SPEEDJSTREAM_H


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
struct SpeedJStream_
{
  typedef SpeedJStream_<ContainerAllocator> Type;

  SpeedJStream_()
    : vel()
    , acc()
    , time(0.0)  {
      vel.assign(0.0);

      acc.assign(0.0);
  }
  SpeedJStream_(const ContainerAllocator& _alloc)
    : vel()
    , acc()
    , time(0.0)  {
  (void)_alloc;
      vel.assign(0.0);

      acc.assign(0.0);
  }



   typedef boost::array<double, 6>  _vel_type;
  _vel_type vel;

   typedef boost::array<double, 6>  _acc_type;
  _acc_type acc;

   typedef double _time_type;
  _time_type time;





  typedef boost::shared_ptr< ::dsr_msgs::SpeedJStream_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dsr_msgs::SpeedJStream_<ContainerAllocator> const> ConstPtr;

}; // struct SpeedJStream_

typedef ::dsr_msgs::SpeedJStream_<std::allocator<void> > SpeedJStream;

typedef boost::shared_ptr< ::dsr_msgs::SpeedJStream > SpeedJStreamPtr;
typedef boost::shared_ptr< ::dsr_msgs::SpeedJStream const> SpeedJStreamConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dsr_msgs::SpeedJStream_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dsr_msgs::SpeedJStream_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::dsr_msgs::SpeedJStream_<ContainerAllocator1> & lhs, const ::dsr_msgs::SpeedJStream_<ContainerAllocator2> & rhs)
{
  return lhs.vel == rhs.vel &&
    lhs.acc == rhs.acc &&
    lhs.time == rhs.time;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::dsr_msgs::SpeedJStream_<ContainerAllocator1> & lhs, const ::dsr_msgs::SpeedJStream_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace dsr_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::SpeedJStream_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::SpeedJStream_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::SpeedJStream_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::SpeedJStream_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::SpeedJStream_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::SpeedJStream_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dsr_msgs::SpeedJStream_<ContainerAllocator> >
{
  static const char* value()
  {
    return "e4ccbedcf19c8719d28eda24c562383b";
  }

  static const char* value(const ::dsr_msgs::SpeedJStream_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xe4ccbedcf19c8719ULL;
  static const uint64_t static_value2 = 0xd28eda24c562383bULL;
};

template<class ContainerAllocator>
struct DataType< ::dsr_msgs::SpeedJStream_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dsr_msgs/SpeedJStream";
  }

  static const char* value(const ::dsr_msgs::SpeedJStream_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dsr_msgs::SpeedJStream_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#____________________________________________________________________________________________\n"
"# speedj\n"
"# \n"
"#____________________________________________________________________________________________\n"
"\n"
"float64[6] vel               # velocity\n"
"float64[6] acc               # acceleration\n"
"float64    time              # time\n"
;
  }

  static const char* value(const ::dsr_msgs::SpeedJStream_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dsr_msgs::SpeedJStream_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.vel);
      stream.next(m.acc);
      stream.next(m.time);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SpeedJStream_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dsr_msgs::SpeedJStream_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dsr_msgs::SpeedJStream_<ContainerAllocator>& v)
  {
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
  }
};

} // namespace message_operations
} // namespace ros

#endif // DSR_MSGS_MESSAGE_SPEEDJSTREAM_H
