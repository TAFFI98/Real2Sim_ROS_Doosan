// Generated by gencpp from file dsr_msgs/FkinRequest.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_FKINREQUEST_H
#define DSR_MSGS_MESSAGE_FKINREQUEST_H


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
struct FkinRequest_
{
  typedef FkinRequest_<ContainerAllocator> Type;

  FkinRequest_()
    : pos()
    , ref(0)  {
      pos.assign(0.0);
  }
  FkinRequest_(const ContainerAllocator& _alloc)
    : pos()
    , ref(0)  {
  (void)_alloc;
      pos.assign(0.0);
  }



   typedef boost::array<double, 6>  _pos_type;
  _pos_type pos;

   typedef int8_t _ref_type;
  _ref_type ref;





  typedef boost::shared_ptr< ::dsr_msgs::FkinRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dsr_msgs::FkinRequest_<ContainerAllocator> const> ConstPtr;

}; // struct FkinRequest_

typedef ::dsr_msgs::FkinRequest_<std::allocator<void> > FkinRequest;

typedef boost::shared_ptr< ::dsr_msgs::FkinRequest > FkinRequestPtr;
typedef boost::shared_ptr< ::dsr_msgs::FkinRequest const> FkinRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dsr_msgs::FkinRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dsr_msgs::FkinRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::dsr_msgs::FkinRequest_<ContainerAllocator1> & lhs, const ::dsr_msgs::FkinRequest_<ContainerAllocator2> & rhs)
{
  return lhs.pos == rhs.pos &&
    lhs.ref == rhs.ref;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::dsr_msgs::FkinRequest_<ContainerAllocator1> & lhs, const ::dsr_msgs::FkinRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace dsr_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::FkinRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::FkinRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::FkinRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::FkinRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::FkinRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::FkinRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dsr_msgs::FkinRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "01a7d76771e91045d7b0913667745cf9";
  }

  static const char* value(const ::dsr_msgs::FkinRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x01a7d76771e91045ULL;
  static const uint64_t static_value2 = 0xd7b0913667745cf9ULL;
};

template<class ContainerAllocator>
struct DataType< ::dsr_msgs::FkinRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dsr_msgs/FkinRequest";
  }

  static const char* value(const ::dsr_msgs::FkinRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dsr_msgs::FkinRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#____________________________________________________________________________________________\n"
"# fkin  \n"
"#____________________________________________________________________________________________\n"
"\n"
"float64[6] pos               # joint pos(posj)  \n"
"int8       ref     #= 0      # DR_BASE(0), DR_WORLD(2)\n"
"                             # <ref is only available in M2.40 or later> \n"
;
  }

  static const char* value(const ::dsr_msgs::FkinRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dsr_msgs::FkinRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.pos);
      stream.next(m.ref);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct FkinRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dsr_msgs::FkinRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dsr_msgs::FkinRequest_<ContainerAllocator>& v)
  {
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

#endif // DSR_MSGS_MESSAGE_FKINREQUEST_H
