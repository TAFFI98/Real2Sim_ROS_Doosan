// Generated by gencpp from file dsr_msgs/GetCurrentSolutionSpaceResponse.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_GETCURRENTSOLUTIONSPACERESPONSE_H
#define DSR_MSGS_MESSAGE_GETCURRENTSOLUTIONSPACERESPONSE_H


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
struct GetCurrentSolutionSpaceResponse_
{
  typedef GetCurrentSolutionSpaceResponse_<ContainerAllocator> Type;

  GetCurrentSolutionSpaceResponse_()
    : sol_space(0)
    , success(false)  {
    }
  GetCurrentSolutionSpaceResponse_(const ContainerAllocator& _alloc)
    : sol_space(0)
    , success(false)  {
  (void)_alloc;
    }



   typedef int8_t _sol_space_type;
  _sol_space_type sol_space;

   typedef uint8_t _success_type;
  _success_type success;





  typedef boost::shared_ptr< ::dsr_msgs::GetCurrentSolutionSpaceResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dsr_msgs::GetCurrentSolutionSpaceResponse_<ContainerAllocator> const> ConstPtr;

}; // struct GetCurrentSolutionSpaceResponse_

typedef ::dsr_msgs::GetCurrentSolutionSpaceResponse_<std::allocator<void> > GetCurrentSolutionSpaceResponse;

typedef boost::shared_ptr< ::dsr_msgs::GetCurrentSolutionSpaceResponse > GetCurrentSolutionSpaceResponsePtr;
typedef boost::shared_ptr< ::dsr_msgs::GetCurrentSolutionSpaceResponse const> GetCurrentSolutionSpaceResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dsr_msgs::GetCurrentSolutionSpaceResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dsr_msgs::GetCurrentSolutionSpaceResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::dsr_msgs::GetCurrentSolutionSpaceResponse_<ContainerAllocator1> & lhs, const ::dsr_msgs::GetCurrentSolutionSpaceResponse_<ContainerAllocator2> & rhs)
{
  return lhs.sol_space == rhs.sol_space &&
    lhs.success == rhs.success;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::dsr_msgs::GetCurrentSolutionSpaceResponse_<ContainerAllocator1> & lhs, const ::dsr_msgs::GetCurrentSolutionSpaceResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace dsr_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::GetCurrentSolutionSpaceResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::GetCurrentSolutionSpaceResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::GetCurrentSolutionSpaceResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::GetCurrentSolutionSpaceResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::GetCurrentSolutionSpaceResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::GetCurrentSolutionSpaceResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dsr_msgs::GetCurrentSolutionSpaceResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bacee50609041091b8cb888ffb4bd562";
  }

  static const char* value(const ::dsr_msgs::GetCurrentSolutionSpaceResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xbacee50609041091ULL;
  static const uint64_t static_value2 = 0xb8cb888ffb4bd562ULL;
};

template<class ContainerAllocator>
struct DataType< ::dsr_msgs::GetCurrentSolutionSpaceResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dsr_msgs/GetCurrentSolutionSpaceResponse";
  }

  static const char* value(const ::dsr_msgs::GetCurrentSolutionSpaceResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dsr_msgs::GetCurrentSolutionSpaceResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int8        sol_space         # solution space : 0 ~ 7\n"
"bool        success\n"
;
  }

  static const char* value(const ::dsr_msgs::GetCurrentSolutionSpaceResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dsr_msgs::GetCurrentSolutionSpaceResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.sol_space);
      stream.next(m.success);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GetCurrentSolutionSpaceResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dsr_msgs::GetCurrentSolutionSpaceResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dsr_msgs::GetCurrentSolutionSpaceResponse_<ContainerAllocator>& v)
  {
    s << indent << "sol_space: ";
    Printer<int8_t>::stream(s, indent + "  ", v.sol_space);
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DSR_MSGS_MESSAGE_GETCURRENTSOLUTIONSPACERESPONSE_H
