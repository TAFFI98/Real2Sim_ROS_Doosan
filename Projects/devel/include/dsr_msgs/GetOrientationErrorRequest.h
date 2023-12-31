// Generated by gencpp from file dsr_msgs/GetOrientationErrorRequest.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_GETORIENTATIONERRORREQUEST_H
#define DSR_MSGS_MESSAGE_GETORIENTATIONERRORREQUEST_H


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
struct GetOrientationErrorRequest_
{
  typedef GetOrientationErrorRequest_<ContainerAllocator> Type;

  GetOrientationErrorRequest_()
    : xd()
    , xc()
    , axis(0)  {
      xd.assign(0.0);

      xc.assign(0.0);
  }
  GetOrientationErrorRequest_(const ContainerAllocator& _alloc)
    : xd()
    , xc()
    , axis(0)  {
  (void)_alloc;
      xd.assign(0.0);

      xc.assign(0.0);
  }



   typedef boost::array<double, 6>  _xd_type;
  _xd_type xd;

   typedef boost::array<double, 6>  _xc_type;
  _xc_type xc;

   typedef int8_t _axis_type;
  _axis_type axis;





  typedef boost::shared_ptr< ::dsr_msgs::GetOrientationErrorRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dsr_msgs::GetOrientationErrorRequest_<ContainerAllocator> const> ConstPtr;

}; // struct GetOrientationErrorRequest_

typedef ::dsr_msgs::GetOrientationErrorRequest_<std::allocator<void> > GetOrientationErrorRequest;

typedef boost::shared_ptr< ::dsr_msgs::GetOrientationErrorRequest > GetOrientationErrorRequestPtr;
typedef boost::shared_ptr< ::dsr_msgs::GetOrientationErrorRequest const> GetOrientationErrorRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dsr_msgs::GetOrientationErrorRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dsr_msgs::GetOrientationErrorRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::dsr_msgs::GetOrientationErrorRequest_<ContainerAllocator1> & lhs, const ::dsr_msgs::GetOrientationErrorRequest_<ContainerAllocator2> & rhs)
{
  return lhs.xd == rhs.xd &&
    lhs.xc == rhs.xc &&
    lhs.axis == rhs.axis;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::dsr_msgs::GetOrientationErrorRequest_<ContainerAllocator1> & lhs, const ::dsr_msgs::GetOrientationErrorRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace dsr_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::GetOrientationErrorRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::GetOrientationErrorRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::GetOrientationErrorRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::GetOrientationErrorRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::GetOrientationErrorRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::GetOrientationErrorRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dsr_msgs::GetOrientationErrorRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "9f5697202e6cec6fea98c82889255f7e";
  }

  static const char* value(const ::dsr_msgs::GetOrientationErrorRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x9f5697202e6cec6fULL;
  static const uint64_t static_value2 = 0xea98c82889255f7eULL;
};

template<class ContainerAllocator>
struct DataType< ::dsr_msgs::GetOrientationErrorRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dsr_msgs/GetOrientationErrorRequest";
  }

  static const char* value(const ::dsr_msgs::GetOrientationErrorRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dsr_msgs::GetOrientationErrorRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#____________________________________________________________________________________________\n"
"# get_orientation_error  \n"
"#____________________________________________________________________________________________\n"
"# This service returns the orientation error value between the arbitrary poses xd and xc of the axis.\n"
"\n"
"float64[6] xd                # task pos(posx)  \n"
"float64[6] xc                # task pos(posx)  \n"
"int8       axis              # DR_AXIS_X(0), DR_AXIS_Y(1), DR_AXIS_Z(2) \n"
;
  }

  static const char* value(const ::dsr_msgs::GetOrientationErrorRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dsr_msgs::GetOrientationErrorRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.xd);
      stream.next(m.xc);
      stream.next(m.axis);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GetOrientationErrorRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dsr_msgs::GetOrientationErrorRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dsr_msgs::GetOrientationErrorRequest_<ContainerAllocator>& v)
  {
    s << indent << "xd[]" << std::endl;
    for (size_t i = 0; i < v.xd.size(); ++i)
    {
      s << indent << "  xd[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.xd[i]);
    }
    s << indent << "xc[]" << std::endl;
    for (size_t i = 0; i < v.xc.size(); ++i)
    {
      s << indent << "  xc[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.xc[i]);
    }
    s << indent << "axis: ";
    Printer<int8_t>::stream(s, indent + "  ", v.axis);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DSR_MSGS_MESSAGE_GETORIENTATIONERRORREQUEST_H
