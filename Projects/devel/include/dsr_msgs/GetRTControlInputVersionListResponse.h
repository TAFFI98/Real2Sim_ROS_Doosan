// Generated by gencpp from file dsr_msgs/GetRTControlInputVersionListResponse.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_GETRTCONTROLINPUTVERSIONLISTRESPONSE_H
#define DSR_MSGS_MESSAGE_GETRTCONTROLINPUTVERSIONLISTRESPONSE_H


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
struct GetRTControlInputVersionListResponse_
{
  typedef GetRTControlInputVersionListResponse_<ContainerAllocator> Type;

  GetRTControlInputVersionListResponse_()
    : success(false)
    , version()  {
    }
  GetRTControlInputVersionListResponse_(const ContainerAllocator& _alloc)
    : success(false)
    , version(_alloc)  {
  (void)_alloc;
    }



   typedef uint8_t _success_type;
  _success_type success;

   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _version_type;
  _version_type version;





  typedef boost::shared_ptr< ::dsr_msgs::GetRTControlInputVersionListResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dsr_msgs::GetRTControlInputVersionListResponse_<ContainerAllocator> const> ConstPtr;

}; // struct GetRTControlInputVersionListResponse_

typedef ::dsr_msgs::GetRTControlInputVersionListResponse_<std::allocator<void> > GetRTControlInputVersionListResponse;

typedef boost::shared_ptr< ::dsr_msgs::GetRTControlInputVersionListResponse > GetRTControlInputVersionListResponsePtr;
typedef boost::shared_ptr< ::dsr_msgs::GetRTControlInputVersionListResponse const> GetRTControlInputVersionListResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dsr_msgs::GetRTControlInputVersionListResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dsr_msgs::GetRTControlInputVersionListResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::dsr_msgs::GetRTControlInputVersionListResponse_<ContainerAllocator1> & lhs, const ::dsr_msgs::GetRTControlInputVersionListResponse_<ContainerAllocator2> & rhs)
{
  return lhs.success == rhs.success &&
    lhs.version == rhs.version;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::dsr_msgs::GetRTControlInputVersionListResponse_<ContainerAllocator1> & lhs, const ::dsr_msgs::GetRTControlInputVersionListResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace dsr_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::GetRTControlInputVersionListResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::GetRTControlInputVersionListResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::GetRTControlInputVersionListResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::GetRTControlInputVersionListResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::GetRTControlInputVersionListResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::GetRTControlInputVersionListResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dsr_msgs::GetRTControlInputVersionListResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "621ab4fad3b2f7679edb9817178ccd57";
  }

  static const char* value(const ::dsr_msgs::GetRTControlInputVersionListResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x621ab4fad3b2f767ULL;
  static const uint64_t static_value2 = 0x9edb9817178ccd57ULL;
};

template<class ContainerAllocator>
struct DataType< ::dsr_msgs::GetRTControlInputVersionListResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dsr_msgs/GetRTControlInputVersionListResponse";
  }

  static const char* value(const ::dsr_msgs::GetRTControlInputVersionListResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dsr_msgs::GetRTControlInputVersionListResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool       success\n"
"string     version\n"
;
  }

  static const char* value(const ::dsr_msgs::GetRTControlInputVersionListResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dsr_msgs::GetRTControlInputVersionListResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.success);
      stream.next(m.version);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GetRTControlInputVersionListResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dsr_msgs::GetRTControlInputVersionListResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dsr_msgs::GetRTControlInputVersionListResponse_<ContainerAllocator>& v)
  {
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
    s << indent << "version: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.version);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DSR_MSGS_MESSAGE_GETRTCONTROLINPUTVERSIONLISTRESPONSE_H
