// Generated by gencpp from file dsr_msgs/IsDoneBoltTighteningRequest.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_ISDONEBOLTTIGHTENINGREQUEST_H
#define DSR_MSGS_MESSAGE_ISDONEBOLTTIGHTENINGREQUEST_H


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
struct IsDoneBoltTighteningRequest_
{
  typedef IsDoneBoltTighteningRequest_<ContainerAllocator> Type;

  IsDoneBoltTighteningRequest_()
    : m(0.0)
    , timeout(0.0)
    , axis(0)  {
    }
  IsDoneBoltTighteningRequest_(const ContainerAllocator& _alloc)
    : m(0.0)
    , timeout(0.0)
    , axis(0)  {
  (void)_alloc;
    }



   typedef double _m_type;
  _m_type m;

   typedef double _timeout_type;
  _timeout_type timeout;

   typedef int8_t _axis_type;
  _axis_type axis;





  typedef boost::shared_ptr< ::dsr_msgs::IsDoneBoltTighteningRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dsr_msgs::IsDoneBoltTighteningRequest_<ContainerAllocator> const> ConstPtr;

}; // struct IsDoneBoltTighteningRequest_

typedef ::dsr_msgs::IsDoneBoltTighteningRequest_<std::allocator<void> > IsDoneBoltTighteningRequest;

typedef boost::shared_ptr< ::dsr_msgs::IsDoneBoltTighteningRequest > IsDoneBoltTighteningRequestPtr;
typedef boost::shared_ptr< ::dsr_msgs::IsDoneBoltTighteningRequest const> IsDoneBoltTighteningRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dsr_msgs::IsDoneBoltTighteningRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dsr_msgs::IsDoneBoltTighteningRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::dsr_msgs::IsDoneBoltTighteningRequest_<ContainerAllocator1> & lhs, const ::dsr_msgs::IsDoneBoltTighteningRequest_<ContainerAllocator2> & rhs)
{
  return lhs.m == rhs.m &&
    lhs.timeout == rhs.timeout &&
    lhs.axis == rhs.axis;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::dsr_msgs::IsDoneBoltTighteningRequest_<ContainerAllocator1> & lhs, const ::dsr_msgs::IsDoneBoltTighteningRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace dsr_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::IsDoneBoltTighteningRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::IsDoneBoltTighteningRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::IsDoneBoltTighteningRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::IsDoneBoltTighteningRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::IsDoneBoltTighteningRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::IsDoneBoltTighteningRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dsr_msgs::IsDoneBoltTighteningRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "0764049b1e7416d143f065a65482f344";
  }

  static const char* value(const ::dsr_msgs::IsDoneBoltTighteningRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x0764049b1e7416d1ULL;
  static const uint64_t static_value2 = 0x43f065a65482f344ULL;
};

template<class ContainerAllocator>
struct DataType< ::dsr_msgs::IsDoneBoltTighteningRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dsr_msgs/IsDoneBoltTighteningRequest";
  }

  static const char* value(const ::dsr_msgs::IsDoneBoltTighteningRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dsr_msgs::IsDoneBoltTighteningRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#____________________________________________________________________________________________\n"
"# is_done_bolt_tightening  \n"
"#____________________________________________________________________________________________\n"
"\n"
"float64    m                 # Target torque  \n"
"float64    timeout           # Monitoring duration [sec]  \n"
"int8       axis              # DR_AXIS_X(0), DR_AXIS_Y(1), DR_AXIS_Z(2) \n"
;
  }

  static const char* value(const ::dsr_msgs::IsDoneBoltTighteningRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dsr_msgs::IsDoneBoltTighteningRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.m);
      stream.next(m.timeout);
      stream.next(m.axis);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct IsDoneBoltTighteningRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dsr_msgs::IsDoneBoltTighteningRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dsr_msgs::IsDoneBoltTighteningRequest_<ContainerAllocator>& v)
  {
    s << indent << "m: ";
    Printer<double>::stream(s, indent + "  ", v.m);
    s << indent << "timeout: ";
    Printer<double>::stream(s, indent + "  ", v.timeout);
    s << indent << "axis: ";
    Printer<int8_t>::stream(s, indent + "  ", v.axis);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DSR_MSGS_MESSAGE_ISDONEBOLTTIGHTENINGREQUEST_H