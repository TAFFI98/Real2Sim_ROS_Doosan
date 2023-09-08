// Generated by gencpp from file dsr_msgs/CoordTransformRequest.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_COORDTRANSFORMREQUEST_H
#define DSR_MSGS_MESSAGE_COORDTRANSFORMREQUEST_H


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
struct CoordTransformRequest_
{
  typedef CoordTransformRequest_<ContainerAllocator> Type;

  CoordTransformRequest_()
    : pos_in()
    , ref_in(0)
    , ref_out(0)  {
      pos_in.assign(0.0);
  }
  CoordTransformRequest_(const ContainerAllocator& _alloc)
    : pos_in()
    , ref_in(0)
    , ref_out(0)  {
  (void)_alloc;
      pos_in.assign(0.0);
  }



   typedef boost::array<double, 6>  _pos_in_type;
  _pos_in_type pos_in;

   typedef int8_t _ref_in_type;
  _ref_in_type ref_in;

   typedef int8_t _ref_out_type;
  _ref_out_type ref_out;





  typedef boost::shared_ptr< ::dsr_msgs::CoordTransformRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dsr_msgs::CoordTransformRequest_<ContainerAllocator> const> ConstPtr;

}; // struct CoordTransformRequest_

typedef ::dsr_msgs::CoordTransformRequest_<std::allocator<void> > CoordTransformRequest;

typedef boost::shared_ptr< ::dsr_msgs::CoordTransformRequest > CoordTransformRequestPtr;
typedef boost::shared_ptr< ::dsr_msgs::CoordTransformRequest const> CoordTransformRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dsr_msgs::CoordTransformRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dsr_msgs::CoordTransformRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::dsr_msgs::CoordTransformRequest_<ContainerAllocator1> & lhs, const ::dsr_msgs::CoordTransformRequest_<ContainerAllocator2> & rhs)
{
  return lhs.pos_in == rhs.pos_in &&
    lhs.ref_in == rhs.ref_in &&
    lhs.ref_out == rhs.ref_out;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::dsr_msgs::CoordTransformRequest_<ContainerAllocator1> & lhs, const ::dsr_msgs::CoordTransformRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace dsr_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::CoordTransformRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::CoordTransformRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::CoordTransformRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::CoordTransformRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::CoordTransformRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::CoordTransformRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dsr_msgs::CoordTransformRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "c009b69dce33d5ca178fda3328c53716";
  }

  static const char* value(const ::dsr_msgs::CoordTransformRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xc009b69dce33d5caULL;
  static const uint64_t static_value2 = 0x178fda3328c53716ULL;
};

template<class ContainerAllocator>
struct DataType< ::dsr_msgs::CoordTransformRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dsr_msgs/CoordTransformRequest";
  }

  static const char* value(const ::dsr_msgs::CoordTransformRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dsr_msgs::CoordTransformRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#____________________________________________________________________________________________\n"
"# coord_transform   \n"
"#____________________________________________________________________________________________\n"
"\n"
"float64[6] pos_in            # task pos(posx)  \n"
"int8       ref_in            # DR_BASE(0), DR_TOOL(1), DR_WORLD(2), user coord(101~200)\n"
"                             # <ref is only available in M2.40 or later> \n"
"int8       ref_out           # DR_BASE(0), DR_TOOL(1), DR_WORLD(2), user coord(101~200) \n"
"                             # <ref is only available in M2.40 or later> \n"
;
  }

  static const char* value(const ::dsr_msgs::CoordTransformRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dsr_msgs::CoordTransformRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.pos_in);
      stream.next(m.ref_in);
      stream.next(m.ref_out);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct CoordTransformRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dsr_msgs::CoordTransformRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dsr_msgs::CoordTransformRequest_<ContainerAllocator>& v)
  {
    s << indent << "pos_in[]" << std::endl;
    for (size_t i = 0; i < v.pos_in.size(); ++i)
    {
      s << indent << "  pos_in[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.pos_in[i]);
    }
    s << indent << "ref_in: ";
    Printer<int8_t>::stream(s, indent + "  ", v.ref_in);
    s << indent << "ref_out: ";
    Printer<int8_t>::stream(s, indent + "  ", v.ref_out);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DSR_MSGS_MESSAGE_COORDTRANSFORMREQUEST_H
