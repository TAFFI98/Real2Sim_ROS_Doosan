// Generated by gencpp from file dsr_msgs/ConfigCreateToolRequest.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_CONFIGCREATETOOLREQUEST_H
#define DSR_MSGS_MESSAGE_CONFIGCREATETOOLREQUEST_H


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
struct ConfigCreateToolRequest_
{
  typedef ConfigCreateToolRequest_<ContainerAllocator> Type;

  ConfigCreateToolRequest_()
    : name()
    , weight(0.0)
    , cog()
    , inertia()  {
      cog.assign(0.0);

      inertia.assign(0.0);
  }
  ConfigCreateToolRequest_(const ContainerAllocator& _alloc)
    : name(_alloc)
    , weight(0.0)
    , cog()
    , inertia()  {
  (void)_alloc;
      cog.assign(0.0);

      inertia.assign(0.0);
  }



   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _name_type;
  _name_type name;

   typedef double _weight_type;
  _weight_type weight;

   typedef boost::array<double, 3>  _cog_type;
  _cog_type cog;

   typedef boost::array<double, 6>  _inertia_type;
  _inertia_type inertia;





  typedef boost::shared_ptr< ::dsr_msgs::ConfigCreateToolRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dsr_msgs::ConfigCreateToolRequest_<ContainerAllocator> const> ConstPtr;

}; // struct ConfigCreateToolRequest_

typedef ::dsr_msgs::ConfigCreateToolRequest_<std::allocator<void> > ConfigCreateToolRequest;

typedef boost::shared_ptr< ::dsr_msgs::ConfigCreateToolRequest > ConfigCreateToolRequestPtr;
typedef boost::shared_ptr< ::dsr_msgs::ConfigCreateToolRequest const> ConfigCreateToolRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dsr_msgs::ConfigCreateToolRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dsr_msgs::ConfigCreateToolRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::dsr_msgs::ConfigCreateToolRequest_<ContainerAllocator1> & lhs, const ::dsr_msgs::ConfigCreateToolRequest_<ContainerAllocator2> & rhs)
{
  return lhs.name == rhs.name &&
    lhs.weight == rhs.weight &&
    lhs.cog == rhs.cog &&
    lhs.inertia == rhs.inertia;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::dsr_msgs::ConfigCreateToolRequest_<ContainerAllocator1> & lhs, const ::dsr_msgs::ConfigCreateToolRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace dsr_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::ConfigCreateToolRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::ConfigCreateToolRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::ConfigCreateToolRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::ConfigCreateToolRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::ConfigCreateToolRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::ConfigCreateToolRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dsr_msgs::ConfigCreateToolRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "84aa36be3ab38a7a2e68e39b9044198f";
  }

  static const char* value(const ::dsr_msgs::ConfigCreateToolRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x84aa36be3ab38a7aULL;
  static const uint64_t static_value2 = 0x2e68e39b9044198fULL;
};

template<class ContainerAllocator>
struct DataType< ::dsr_msgs::ConfigCreateToolRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dsr_msgs/ConfigCreateToolRequest";
  }

  static const char* value(const ::dsr_msgs::ConfigCreateToolRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dsr_msgs::ConfigCreateToolRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#____________________________________________________________________________________________\n"
"# config_create_tool \n"
"# It is a service for registering and using robot Tool information in advance for safety \n"
"#____________________________________________________________________________________________\n"
"\n"
"string          name        # tool name \n"
"float64         weight      # tool weight \n"
"float64[3]      cog         # Center of gravity\n"
"float64[6]      inertia     # tool inertia \n"
;
  }

  static const char* value(const ::dsr_msgs::ConfigCreateToolRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dsr_msgs::ConfigCreateToolRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.name);
      stream.next(m.weight);
      stream.next(m.cog);
      stream.next(m.inertia);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ConfigCreateToolRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dsr_msgs::ConfigCreateToolRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dsr_msgs::ConfigCreateToolRequest_<ContainerAllocator>& v)
  {
    s << indent << "name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.name);
    s << indent << "weight: ";
    Printer<double>::stream(s, indent + "  ", v.weight);
    s << indent << "cog[]" << std::endl;
    for (size_t i = 0; i < v.cog.size(); ++i)
    {
      s << indent << "  cog[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.cog[i]);
    }
    s << indent << "inertia[]" << std::endl;
    for (size_t i = 0; i < v.inertia.size(); ++i)
    {
      s << indent << "  inertia[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.inertia[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // DSR_MSGS_MESSAGE_CONFIGCREATETOOLREQUEST_H
