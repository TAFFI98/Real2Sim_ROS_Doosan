// Generated by gencpp from file dsr_msgs/CheckForceConditionRequest.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_CHECKFORCECONDITIONREQUEST_H
#define DSR_MSGS_MESSAGE_CHECKFORCECONDITIONREQUEST_H


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
struct CheckForceConditionRequest_
{
  typedef CheckForceConditionRequest_<ContainerAllocator> Type;

  CheckForceConditionRequest_()
    : axis(0)
    , min(0.0)
    , max(0.0)
    , ref(0)  {
    }
  CheckForceConditionRequest_(const ContainerAllocator& _alloc)
    : axis(0)
    , min(0.0)
    , max(0.0)
    , ref(0)  {
  (void)_alloc;
    }



   typedef int8_t _axis_type;
  _axis_type axis;

   typedef double _min_type;
  _min_type min;

   typedef double _max_type;
  _max_type max;

   typedef int8_t _ref_type;
  _ref_type ref;





  typedef boost::shared_ptr< ::dsr_msgs::CheckForceConditionRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dsr_msgs::CheckForceConditionRequest_<ContainerAllocator> const> ConstPtr;

}; // struct CheckForceConditionRequest_

typedef ::dsr_msgs::CheckForceConditionRequest_<std::allocator<void> > CheckForceConditionRequest;

typedef boost::shared_ptr< ::dsr_msgs::CheckForceConditionRequest > CheckForceConditionRequestPtr;
typedef boost::shared_ptr< ::dsr_msgs::CheckForceConditionRequest const> CheckForceConditionRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dsr_msgs::CheckForceConditionRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dsr_msgs::CheckForceConditionRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::dsr_msgs::CheckForceConditionRequest_<ContainerAllocator1> & lhs, const ::dsr_msgs::CheckForceConditionRequest_<ContainerAllocator2> & rhs)
{
  return lhs.axis == rhs.axis &&
    lhs.min == rhs.min &&
    lhs.max == rhs.max &&
    lhs.ref == rhs.ref;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::dsr_msgs::CheckForceConditionRequest_<ContainerAllocator1> & lhs, const ::dsr_msgs::CheckForceConditionRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace dsr_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::CheckForceConditionRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::CheckForceConditionRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::CheckForceConditionRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::CheckForceConditionRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::CheckForceConditionRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::CheckForceConditionRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dsr_msgs::CheckForceConditionRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "b7ae2454f960303e8d6a133fdd9cd0f9";
  }

  static const char* value(const ::dsr_msgs::CheckForceConditionRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xb7ae2454f960303eULL;
  static const uint64_t static_value2 = 0x8d6a133fdd9cd0f9ULL;
};

template<class ContainerAllocator>
struct DataType< ::dsr_msgs::CheckForceConditionRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dsr_msgs/CheckForceConditionRequest";
  }

  static const char* value(const ::dsr_msgs::CheckForceConditionRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dsr_msgs::CheckForceConditionRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#____________________________________________________________________________________________\n"
"# check_force_condition \n"
"#This service checks the status of the given force. It disregards the force direction and only compares the sizes. \n"
"#This condition can be repeated with the while or if statement. Measuring the force, axis is based on the ref coordinate and measuring the moment,\n"
"#axis is based on the tool coordinate.\n"
"#____________________________________________________________________________________________\n"
"\n"
"int8       axis              # DR_AXIS_X(0), DR_AXIS_Y(1), DR_AXIS_Z(2), DR_AXIS_A(10), DR_AXIS_B(11), DR_AXIS_C(12) \n"
"float64    min               # min >=0.0   \n"
"float64    max               # max >=0.0 \n"
"int8       ref     #= 0      # DR_BASE(0), DR_TOOL(1), DR_WORLD(2), user coord(101~200)\n"
"                             # <DR_WORLD is only available in M2.40 or later> \n"
;
  }

  static const char* value(const ::dsr_msgs::CheckForceConditionRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dsr_msgs::CheckForceConditionRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.axis);
      stream.next(m.min);
      stream.next(m.max);
      stream.next(m.ref);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct CheckForceConditionRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dsr_msgs::CheckForceConditionRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dsr_msgs::CheckForceConditionRequest_<ContainerAllocator>& v)
  {
    s << indent << "axis: ";
    Printer<int8_t>::stream(s, indent + "  ", v.axis);
    s << indent << "min: ";
    Printer<double>::stream(s, indent + "  ", v.min);
    s << indent << "max: ";
    Printer<double>::stream(s, indent + "  ", v.max);
    s << indent << "ref: ";
    Printer<int8_t>::stream(s, indent + "  ", v.ref);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DSR_MSGS_MESSAGE_CHECKFORCECONDITIONREQUEST_H
