// Generated by gencpp from file dsr_msgs/GetUserCartCoordResponse.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_GETUSERCARTCOORDRESPONSE_H
#define DSR_MSGS_MESSAGE_GETUSERCARTCOORDRESPONSE_H


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
struct GetUserCartCoordResponse_
{
  typedef GetUserCartCoordResponse_<ContainerAllocator> Type;

  GetUserCartCoordResponse_()
    : conv_posx()
    , ref(0)
    , success(false)  {
      conv_posx.assign(0.0);
  }
  GetUserCartCoordResponse_(const ContainerAllocator& _alloc)
    : conv_posx()
    , ref(0)
    , success(false)  {
  (void)_alloc;
      conv_posx.assign(0.0);
  }



   typedef boost::array<double, 6>  _conv_posx_type;
  _conv_posx_type conv_posx;

   typedef int8_t _ref_type;
  _ref_type ref;

   typedef uint8_t _success_type;
  _success_type success;





  typedef boost::shared_ptr< ::dsr_msgs::GetUserCartCoordResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dsr_msgs::GetUserCartCoordResponse_<ContainerAllocator> const> ConstPtr;

}; // struct GetUserCartCoordResponse_

typedef ::dsr_msgs::GetUserCartCoordResponse_<std::allocator<void> > GetUserCartCoordResponse;

typedef boost::shared_ptr< ::dsr_msgs::GetUserCartCoordResponse > GetUserCartCoordResponsePtr;
typedef boost::shared_ptr< ::dsr_msgs::GetUserCartCoordResponse const> GetUserCartCoordResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dsr_msgs::GetUserCartCoordResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dsr_msgs::GetUserCartCoordResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::dsr_msgs::GetUserCartCoordResponse_<ContainerAllocator1> & lhs, const ::dsr_msgs::GetUserCartCoordResponse_<ContainerAllocator2> & rhs)
{
  return lhs.conv_posx == rhs.conv_posx &&
    lhs.ref == rhs.ref &&
    lhs.success == rhs.success;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::dsr_msgs::GetUserCartCoordResponse_<ContainerAllocator1> & lhs, const ::dsr_msgs::GetUserCartCoordResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace dsr_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::GetUserCartCoordResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::GetUserCartCoordResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::GetUserCartCoordResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::GetUserCartCoordResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::GetUserCartCoordResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::GetUserCartCoordResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dsr_msgs::GetUserCartCoordResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "abfa434bf46c1e9ef44fb450528140a2";
  }

  static const char* value(const ::dsr_msgs::GetUserCartCoordResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xabfa434bf46c1e9eULL;
  static const uint64_t static_value2 = 0xf44fb450528140a2ULL;
};

template<class ContainerAllocator>
struct DataType< ::dsr_msgs::GetUserCartCoordResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dsr_msgs/GetUserCartCoordResponse";
  }

  static const char* value(const ::dsr_msgs::GetUserCartCoordResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dsr_msgs::GetUserCartCoordResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64[6] conv_posx         # task pos(posx)  \n"
"int8       ref               # Reference coordinate of the coordinate to get\n"
"bool       success\n"
"\n"
;
  }

  static const char* value(const ::dsr_msgs::GetUserCartCoordResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dsr_msgs::GetUserCartCoordResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.conv_posx);
      stream.next(m.ref);
      stream.next(m.success);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GetUserCartCoordResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dsr_msgs::GetUserCartCoordResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dsr_msgs::GetUserCartCoordResponse_<ContainerAllocator>& v)
  {
    s << indent << "conv_posx[]" << std::endl;
    for (size_t i = 0; i < v.conv_posx.size(); ++i)
    {
      s << indent << "  conv_posx[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.conv_posx[i]);
    }
    s << indent << "ref: ";
    Printer<int8_t>::stream(s, indent + "  ", v.ref);
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DSR_MSGS_MESSAGE_GETUSERCARTCOORDRESPONSE_H
