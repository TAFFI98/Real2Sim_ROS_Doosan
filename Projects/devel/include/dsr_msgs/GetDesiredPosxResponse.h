// Generated by gencpp from file dsr_msgs/GetDesiredPosxResponse.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_GETDESIREDPOSXRESPONSE_H
#define DSR_MSGS_MESSAGE_GETDESIREDPOSXRESPONSE_H


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
struct GetDesiredPosxResponse_
{
  typedef GetDesiredPosxResponse_<ContainerAllocator> Type;

  GetDesiredPosxResponse_()
    : pos()
    , success(false)  {
      pos.assign(0.0);
  }
  GetDesiredPosxResponse_(const ContainerAllocator& _alloc)
    : pos()
    , success(false)  {
  (void)_alloc;
      pos.assign(0.0);
  }



   typedef boost::array<double, 6>  _pos_type;
  _pos_type pos;

   typedef uint8_t _success_type;
  _success_type success;





  typedef boost::shared_ptr< ::dsr_msgs::GetDesiredPosxResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dsr_msgs::GetDesiredPosxResponse_<ContainerAllocator> const> ConstPtr;

}; // struct GetDesiredPosxResponse_

typedef ::dsr_msgs::GetDesiredPosxResponse_<std::allocator<void> > GetDesiredPosxResponse;

typedef boost::shared_ptr< ::dsr_msgs::GetDesiredPosxResponse > GetDesiredPosxResponsePtr;
typedef boost::shared_ptr< ::dsr_msgs::GetDesiredPosxResponse const> GetDesiredPosxResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dsr_msgs::GetDesiredPosxResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dsr_msgs::GetDesiredPosxResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::dsr_msgs::GetDesiredPosxResponse_<ContainerAllocator1> & lhs, const ::dsr_msgs::GetDesiredPosxResponse_<ContainerAllocator2> & rhs)
{
  return lhs.pos == rhs.pos &&
    lhs.success == rhs.success;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::dsr_msgs::GetDesiredPosxResponse_<ContainerAllocator1> & lhs, const ::dsr_msgs::GetDesiredPosxResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace dsr_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::GetDesiredPosxResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::GetDesiredPosxResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::GetDesiredPosxResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::GetDesiredPosxResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::GetDesiredPosxResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::GetDesiredPosxResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dsr_msgs::GetDesiredPosxResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3d228bb409a5fe0306e199313e3ed277";
  }

  static const char* value(const ::dsr_msgs::GetDesiredPosxResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3d228bb409a5fe03ULL;
  static const uint64_t static_value2 = 0x06e199313e3ed277ULL;
};

template<class ContainerAllocator>
struct DataType< ::dsr_msgs::GetDesiredPosxResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dsr_msgs/GetDesiredPosxResponse";
  }

  static const char* value(const ::dsr_msgs::GetDesiredPosxResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dsr_msgs::GetDesiredPosxResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64[6] pos               # task pos(posx)\n"
"bool       success\n"
;
  }

  static const char* value(const ::dsr_msgs::GetDesiredPosxResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dsr_msgs::GetDesiredPosxResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.pos);
      stream.next(m.success);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GetDesiredPosxResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dsr_msgs::GetDesiredPosxResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dsr_msgs::GetDesiredPosxResponse_<ContainerAllocator>& v)
  {
    s << indent << "pos[]" << std::endl;
    for (size_t i = 0; i < v.pos.size(); ++i)
    {
      s << indent << "  pos[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.pos[i]);
    }
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DSR_MSGS_MESSAGE_GETDESIREDPOSXRESPONSE_H