// Generated by gencpp from file dsr_msgs/GetCurrentVeljResponse.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_GETCURRENTVELJRESPONSE_H
#define DSR_MSGS_MESSAGE_GETCURRENTVELJRESPONSE_H


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
struct GetCurrentVeljResponse_
{
  typedef GetCurrentVeljResponse_<ContainerAllocator> Type;

  GetCurrentVeljResponse_()
    : joint_speed()
    , success(false)  {
      joint_speed.assign(0.0);
  }
  GetCurrentVeljResponse_(const ContainerAllocator& _alloc)
    : joint_speed()
    , success(false)  {
  (void)_alloc;
      joint_speed.assign(0.0);
  }



   typedef boost::array<double, 6>  _joint_speed_type;
  _joint_speed_type joint_speed;

   typedef uint8_t _success_type;
  _success_type success;





  typedef boost::shared_ptr< ::dsr_msgs::GetCurrentVeljResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dsr_msgs::GetCurrentVeljResponse_<ContainerAllocator> const> ConstPtr;

}; // struct GetCurrentVeljResponse_

typedef ::dsr_msgs::GetCurrentVeljResponse_<std::allocator<void> > GetCurrentVeljResponse;

typedef boost::shared_ptr< ::dsr_msgs::GetCurrentVeljResponse > GetCurrentVeljResponsePtr;
typedef boost::shared_ptr< ::dsr_msgs::GetCurrentVeljResponse const> GetCurrentVeljResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dsr_msgs::GetCurrentVeljResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dsr_msgs::GetCurrentVeljResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::dsr_msgs::GetCurrentVeljResponse_<ContainerAllocator1> & lhs, const ::dsr_msgs::GetCurrentVeljResponse_<ContainerAllocator2> & rhs)
{
  return lhs.joint_speed == rhs.joint_speed &&
    lhs.success == rhs.success;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::dsr_msgs::GetCurrentVeljResponse_<ContainerAllocator1> & lhs, const ::dsr_msgs::GetCurrentVeljResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace dsr_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::GetCurrentVeljResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::GetCurrentVeljResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::GetCurrentVeljResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::GetCurrentVeljResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::GetCurrentVeljResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::GetCurrentVeljResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dsr_msgs::GetCurrentVeljResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "9162ee4b17260f95d8a41690c4c86ea1";
  }

  static const char* value(const ::dsr_msgs::GetCurrentVeljResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x9162ee4b17260f95ULL;
  static const uint64_t static_value2 = 0xd8a41690c4c86ea1ULL;
};

template<class ContainerAllocator>
struct DataType< ::dsr_msgs::GetCurrentVeljResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dsr_msgs/GetCurrentVeljResponse";
  }

  static const char* value(const ::dsr_msgs::GetCurrentVeljResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dsr_msgs::GetCurrentVeljResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64[6]  joint_speed               # joint speed \n"
"bool        success\n"
;
  }

  static const char* value(const ::dsr_msgs::GetCurrentVeljResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dsr_msgs::GetCurrentVeljResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.joint_speed);
      stream.next(m.success);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GetCurrentVeljResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dsr_msgs::GetCurrentVeljResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dsr_msgs::GetCurrentVeljResponse_<ContainerAllocator>& v)
  {
    s << indent << "joint_speed[]" << std::endl;
    for (size_t i = 0; i < v.joint_speed.size(); ++i)
    {
      s << indent << "  joint_speed[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.joint_speed[i]);
    }
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DSR_MSGS_MESSAGE_GETCURRENTVELJRESPONSE_H
