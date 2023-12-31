// Generated by gencpp from file dsr_msgs/SetUserCartCoord3Request.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_SETUSERCARTCOORD3REQUEST_H
#define DSR_MSGS_MESSAGE_SETUSERCARTCOORD3REQUEST_H


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
struct SetUserCartCoord3Request_
{
  typedef SetUserCartCoord3Request_<ContainerAllocator> Type;

  SetUserCartCoord3Request_()
    : u1()
    , v1()
    , pos()
    , ref(0)  {
      u1.assign(0.0);

      v1.assign(0.0);

      pos.assign(0.0);
  }
  SetUserCartCoord3Request_(const ContainerAllocator& _alloc)
    : u1()
    , v1()
    , pos()
    , ref(0)  {
  (void)_alloc;
      u1.assign(0.0);

      v1.assign(0.0);

      pos.assign(0.0);
  }



   typedef boost::array<double, 3>  _u1_type;
  _u1_type u1;

   typedef boost::array<double, 3>  _v1_type;
  _v1_type v1;

   typedef boost::array<double, 6>  _pos_type;
  _pos_type pos;

   typedef int8_t _ref_type;
  _ref_type ref;





  typedef boost::shared_ptr< ::dsr_msgs::SetUserCartCoord3Request_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dsr_msgs::SetUserCartCoord3Request_<ContainerAllocator> const> ConstPtr;

}; // struct SetUserCartCoord3Request_

typedef ::dsr_msgs::SetUserCartCoord3Request_<std::allocator<void> > SetUserCartCoord3Request;

typedef boost::shared_ptr< ::dsr_msgs::SetUserCartCoord3Request > SetUserCartCoord3RequestPtr;
typedef boost::shared_ptr< ::dsr_msgs::SetUserCartCoord3Request const> SetUserCartCoord3RequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dsr_msgs::SetUserCartCoord3Request_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dsr_msgs::SetUserCartCoord3Request_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::dsr_msgs::SetUserCartCoord3Request_<ContainerAllocator1> & lhs, const ::dsr_msgs::SetUserCartCoord3Request_<ContainerAllocator2> & rhs)
{
  return lhs.u1 == rhs.u1 &&
    lhs.v1 == rhs.v1 &&
    lhs.pos == rhs.pos &&
    lhs.ref == rhs.ref;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::dsr_msgs::SetUserCartCoord3Request_<ContainerAllocator1> & lhs, const ::dsr_msgs::SetUserCartCoord3Request_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace dsr_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::SetUserCartCoord3Request_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::SetUserCartCoord3Request_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::SetUserCartCoord3Request_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::SetUserCartCoord3Request_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::SetUserCartCoord3Request_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::SetUserCartCoord3Request_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dsr_msgs::SetUserCartCoord3Request_<ContainerAllocator> >
{
  static const char* value()
  {
    return "5c5f03fe1f944ac766f5096fdf844e8a";
  }

  static const char* value(const ::dsr_msgs::SetUserCartCoord3Request_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x5c5f03fe1f944ac7ULL;
  static const uint64_t static_value2 = 0x66f5096fdf844e8aULL;
};

template<class ContainerAllocator>
struct DataType< ::dsr_msgs::SetUserCartCoord3Request_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dsr_msgs/SetUserCartCoord3Request";
  }

  static const char* value(const ::dsr_msgs::SetUserCartCoord3Request_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dsr_msgs::SetUserCartCoord3Request_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#____________________________________________________________________________________________\n"
"# set_user_cart_coord(u1, v1, pos, ref) \n"
"#____________________________________________________________________________________________\n"
"\n"
"float64[3] u1                # X-axis unit vector  \n"
"float64[3] v1                # Y-axis unit vector \n"
"float64[6] pos               # task pos(posx) \n"
"int8       ref               # DR_BASE(0), DR_WORLD(2)\n"
"                             # <ref is only available in M2.40 or later> \n"
;
  }

  static const char* value(const ::dsr_msgs::SetUserCartCoord3Request_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dsr_msgs::SetUserCartCoord3Request_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.u1);
      stream.next(m.v1);
      stream.next(m.pos);
      stream.next(m.ref);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SetUserCartCoord3Request_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dsr_msgs::SetUserCartCoord3Request_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dsr_msgs::SetUserCartCoord3Request_<ContainerAllocator>& v)
  {
    s << indent << "u1[]" << std::endl;
    for (size_t i = 0; i < v.u1.size(); ++i)
    {
      s << indent << "  u1[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.u1[i]);
    }
    s << indent << "v1[]" << std::endl;
    for (size_t i = 0; i < v.v1.size(); ++i)
    {
      s << indent << "  v1[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.v1[i]);
    }
    s << indent << "pos[]" << std::endl;
    for (size_t i = 0; i < v.pos.size(); ++i)
    {
      s << indent << "  pos[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.pos[i]);
    }
    s << indent << "ref: ";
    Printer<int8_t>::stream(s, indent + "  ", v.ref);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DSR_MSGS_MESSAGE_SETUSERCARTCOORD3REQUEST_H
