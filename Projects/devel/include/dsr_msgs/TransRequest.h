// Generated by gencpp from file dsr_msgs/TransRequest.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_TRANSREQUEST_H
#define DSR_MSGS_MESSAGE_TRANSREQUEST_H


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
struct TransRequest_
{
  typedef TransRequest_<ContainerAllocator> Type;

  TransRequest_()
    : pos()
    , delta()
    , ref(0)
    , ref_out(0)  {
      pos.assign(0.0);

      delta.assign(0.0);
  }
  TransRequest_(const ContainerAllocator& _alloc)
    : pos()
    , delta()
    , ref(0)
    , ref_out(0)  {
  (void)_alloc;
      pos.assign(0.0);

      delta.assign(0.0);
  }



   typedef boost::array<double, 6>  _pos_type;
  _pos_type pos;

   typedef boost::array<double, 6>  _delta_type;
  _delta_type delta;

   typedef int8_t _ref_type;
  _ref_type ref;

   typedef int8_t _ref_out_type;
  _ref_out_type ref_out;





  typedef boost::shared_ptr< ::dsr_msgs::TransRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dsr_msgs::TransRequest_<ContainerAllocator> const> ConstPtr;

}; // struct TransRequest_

typedef ::dsr_msgs::TransRequest_<std::allocator<void> > TransRequest;

typedef boost::shared_ptr< ::dsr_msgs::TransRequest > TransRequestPtr;
typedef boost::shared_ptr< ::dsr_msgs::TransRequest const> TransRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dsr_msgs::TransRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dsr_msgs::TransRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::dsr_msgs::TransRequest_<ContainerAllocator1> & lhs, const ::dsr_msgs::TransRequest_<ContainerAllocator2> & rhs)
{
  return lhs.pos == rhs.pos &&
    lhs.delta == rhs.delta &&
    lhs.ref == rhs.ref &&
    lhs.ref_out == rhs.ref_out;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::dsr_msgs::TransRequest_<ContainerAllocator1> & lhs, const ::dsr_msgs::TransRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace dsr_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::TransRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::TransRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::TransRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::TransRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::TransRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::TransRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dsr_msgs::TransRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "7ea759998e0dd768f4e6a42af908529b";
  }

  static const char* value(const ::dsr_msgs::TransRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x7ea759998e0dd768ULL;
  static const uint64_t static_value2 = 0xf4e6a42af908529bULL;
};

template<class ContainerAllocator>
struct DataType< ::dsr_msgs::TransRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dsr_msgs/TransRequest";
  }

  static const char* value(const ::dsr_msgs::TransRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dsr_msgs::TransRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#____________________________________________________________________________________________\n"
"# trans  \n"
"#____________________________________________________________________________________________\n"
"\n"
"float64[6] pos               # task pos(posx)  \n"
"float64[6] delta             # delta (posx)  \n"
"int8       ref     #= 0      # DR_BASE(0), DR_TOOL(1), DR_WORLD(2)\n"
"                             # <DR_WORLD is only available in M2.40 or later> \n"
"int8       ref_out #= 0      # DR_BASE(0), DR_WORLD(2)\n"
"                             # <ref_out is only available in M2.40 or later>\n"
;
  }

  static const char* value(const ::dsr_msgs::TransRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dsr_msgs::TransRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.pos);
      stream.next(m.delta);
      stream.next(m.ref);
      stream.next(m.ref_out);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct TransRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dsr_msgs::TransRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dsr_msgs::TransRequest_<ContainerAllocator>& v)
  {
    s << indent << "pos[]" << std::endl;
    for (size_t i = 0; i < v.pos.size(); ++i)
    {
      s << indent << "  pos[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.pos[i]);
    }
    s << indent << "delta[]" << std::endl;
    for (size_t i = 0; i < v.delta.size(); ++i)
    {
      s << indent << "  delta[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.delta[i]);
    }
    s << indent << "ref: ";
    Printer<int8_t>::stream(s, indent + "  ", v.ref);
    s << indent << "ref_out: ";
    Printer<int8_t>::stream(s, indent + "  ", v.ref_out);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DSR_MSGS_MESSAGE_TRANSREQUEST_H
