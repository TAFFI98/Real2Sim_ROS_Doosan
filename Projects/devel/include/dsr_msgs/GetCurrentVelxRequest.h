// Generated by gencpp from file dsr_msgs/GetCurrentVelxRequest.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_GETCURRENTVELXREQUEST_H
#define DSR_MSGS_MESSAGE_GETCURRENTVELXREQUEST_H


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
struct GetCurrentVelxRequest_
{
  typedef GetCurrentVelxRequest_<ContainerAllocator> Type;

  GetCurrentVelxRequest_()
    : ref(0)  {
    }
  GetCurrentVelxRequest_(const ContainerAllocator& _alloc)
    : ref(0)  {
  (void)_alloc;
    }



   typedef int8_t _ref_type;
  _ref_type ref;





  typedef boost::shared_ptr< ::dsr_msgs::GetCurrentVelxRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dsr_msgs::GetCurrentVelxRequest_<ContainerAllocator> const> ConstPtr;

}; // struct GetCurrentVelxRequest_

typedef ::dsr_msgs::GetCurrentVelxRequest_<std::allocator<void> > GetCurrentVelxRequest;

typedef boost::shared_ptr< ::dsr_msgs::GetCurrentVelxRequest > GetCurrentVelxRequestPtr;
typedef boost::shared_ptr< ::dsr_msgs::GetCurrentVelxRequest const> GetCurrentVelxRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dsr_msgs::GetCurrentVelxRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dsr_msgs::GetCurrentVelxRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::dsr_msgs::GetCurrentVelxRequest_<ContainerAllocator1> & lhs, const ::dsr_msgs::GetCurrentVelxRequest_<ContainerAllocator2> & rhs)
{
  return lhs.ref == rhs.ref;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::dsr_msgs::GetCurrentVelxRequest_<ContainerAllocator1> & lhs, const ::dsr_msgs::GetCurrentVelxRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace dsr_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::GetCurrentVelxRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::GetCurrentVelxRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::GetCurrentVelxRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::GetCurrentVelxRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::GetCurrentVelxRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::GetCurrentVelxRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dsr_msgs::GetCurrentVelxRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3d7349a71916d8843a1403dfc21af071";
  }

  static const char* value(const ::dsr_msgs::GetCurrentVelxRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3d7349a71916d884ULL;
  static const uint64_t static_value2 = 0x3a1403dfc21af071ULL;
};

template<class ContainerAllocator>
struct DataType< ::dsr_msgs::GetCurrentVelxRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dsr_msgs/GetCurrentVelxRequest";
  }

  static const char* value(const ::dsr_msgs::GetCurrentVelxRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dsr_msgs::GetCurrentVelxRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#____________________________________________________________________________________________\n"
"# get_current_velx(ref)  \n"
"#____________________________________________________________________________________________\n"
"# This service returns the current tool velocity based on the ref coordinate.\n"
"\n"
"int8       ref               # DR_BASE(0), DR_WORLD(2)\n"
;
  }

  static const char* value(const ::dsr_msgs::GetCurrentVelxRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dsr_msgs::GetCurrentVelxRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.ref);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GetCurrentVelxRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dsr_msgs::GetCurrentVelxRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dsr_msgs::GetCurrentVelxRequest_<ContainerAllocator>& v)
  {
    s << indent << "ref: ";
    Printer<int8_t>::stream(s, indent + "  ", v.ref);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DSR_MSGS_MESSAGE_GETCURRENTVELXREQUEST_H
