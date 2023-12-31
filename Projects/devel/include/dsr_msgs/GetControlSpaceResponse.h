// Generated by gencpp from file dsr_msgs/GetControlSpaceResponse.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_GETCONTROLSPACERESPONSE_H
#define DSR_MSGS_MESSAGE_GETCONTROLSPACERESPONSE_H


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
struct GetControlSpaceResponse_
{
  typedef GetControlSpaceResponse_<ContainerAllocator> Type;

  GetControlSpaceResponse_()
    : space(0)
    , success(false)  {
    }
  GetControlSpaceResponse_(const ContainerAllocator& _alloc)
    : space(0)
    , success(false)  {
  (void)_alloc;
    }



   typedef int8_t _space_type;
  _space_type space;

   typedef uint8_t _success_type;
  _success_type success;





  typedef boost::shared_ptr< ::dsr_msgs::GetControlSpaceResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dsr_msgs::GetControlSpaceResponse_<ContainerAllocator> const> ConstPtr;

}; // struct GetControlSpaceResponse_

typedef ::dsr_msgs::GetControlSpaceResponse_<std::allocator<void> > GetControlSpaceResponse;

typedef boost::shared_ptr< ::dsr_msgs::GetControlSpaceResponse > GetControlSpaceResponsePtr;
typedef boost::shared_ptr< ::dsr_msgs::GetControlSpaceResponse const> GetControlSpaceResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dsr_msgs::GetControlSpaceResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dsr_msgs::GetControlSpaceResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::dsr_msgs::GetControlSpaceResponse_<ContainerAllocator1> & lhs, const ::dsr_msgs::GetControlSpaceResponse_<ContainerAllocator2> & rhs)
{
  return lhs.space == rhs.space &&
    lhs.success == rhs.success;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::dsr_msgs::GetControlSpaceResponse_<ContainerAllocator1> & lhs, const ::dsr_msgs::GetControlSpaceResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace dsr_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::GetControlSpaceResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::GetControlSpaceResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::GetControlSpaceResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::GetControlSpaceResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::GetControlSpaceResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::GetControlSpaceResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dsr_msgs::GetControlSpaceResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "1a5780af2202e44900c27ba310bfe10c";
  }

  static const char* value(const ::dsr_msgs::GetControlSpaceResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x1a5780af2202e449ULL;
  static const uint64_t static_value2 = 0x00c27ba310bfe10cULL;
};

template<class ContainerAllocator>
struct DataType< ::dsr_msgs::GetControlSpaceResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dsr_msgs/GetControlSpaceResponse";
  }

  static const char* value(const ::dsr_msgs::GetControlSpaceResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dsr_msgs::GetControlSpaceResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int8    space        # Control mode : Joint space control(1), Task space control(2)\n"
"bool    success\n"
"\n"
;
  }

  static const char* value(const ::dsr_msgs::GetControlSpaceResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dsr_msgs::GetControlSpaceResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.space);
      stream.next(m.success);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GetControlSpaceResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dsr_msgs::GetControlSpaceResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dsr_msgs::GetControlSpaceResponse_<ContainerAllocator>& v)
  {
    s << indent << "space: ";
    Printer<int8_t>::stream(s, indent + "  ", v.space);
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DSR_MSGS_MESSAGE_GETCONTROLSPACERESPONSE_H
