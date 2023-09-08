// Generated by gencpp from file dsr_msgs/SetModbusOutputRequest.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_SETMODBUSOUTPUTREQUEST_H
#define DSR_MSGS_MESSAGE_SETMODBUSOUTPUTREQUEST_H


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
struct SetModbusOutputRequest_
{
  typedef SetModbusOutputRequest_<ContainerAllocator> Type;

  SetModbusOutputRequest_()
    : name()
    , value(0)  {
    }
  SetModbusOutputRequest_(const ContainerAllocator& _alloc)
    : name(_alloc)
    , value(0)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _name_type;
  _name_type name;

   typedef int32_t _value_type;
  _value_type value;





  typedef boost::shared_ptr< ::dsr_msgs::SetModbusOutputRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dsr_msgs::SetModbusOutputRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SetModbusOutputRequest_

typedef ::dsr_msgs::SetModbusOutputRequest_<std::allocator<void> > SetModbusOutputRequest;

typedef boost::shared_ptr< ::dsr_msgs::SetModbusOutputRequest > SetModbusOutputRequestPtr;
typedef boost::shared_ptr< ::dsr_msgs::SetModbusOutputRequest const> SetModbusOutputRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dsr_msgs::SetModbusOutputRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dsr_msgs::SetModbusOutputRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::dsr_msgs::SetModbusOutputRequest_<ContainerAllocator1> & lhs, const ::dsr_msgs::SetModbusOutputRequest_<ContainerAllocator2> & rhs)
{
  return lhs.name == rhs.name &&
    lhs.value == rhs.value;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::dsr_msgs::SetModbusOutputRequest_<ContainerAllocator1> & lhs, const ::dsr_msgs::SetModbusOutputRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace dsr_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::SetModbusOutputRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::SetModbusOutputRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::SetModbusOutputRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::SetModbusOutputRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::SetModbusOutputRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::SetModbusOutputRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dsr_msgs::SetModbusOutputRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "65fedc7a0cbfb8db035e46194a350bf1";
  }

  static const char* value(const ::dsr_msgs::SetModbusOutputRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x65fedc7a0cbfb8dbULL;
  static const uint64_t static_value2 = 0x035e46194a350bf1ULL;
};

template<class ContainerAllocator>
struct DataType< ::dsr_msgs::SetModbusOutputRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dsr_msgs/SetModbusOutputRequest";
  }

  static const char* value(const ::dsr_msgs::SetModbusOutputRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dsr_msgs::SetModbusOutputRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#____________________________________________________________________________________________\n"
"# set_modbus_output  \n"
"# This service sends the signal to an external Modbus system. \n"
"#____________________________________________________________________________________________\n"
"\n"
"string      name     # modbus signal symbol\n"
"int32       value    # modbus register value\n"
;
  }

  static const char* value(const ::dsr_msgs::SetModbusOutputRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dsr_msgs::SetModbusOutputRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.name);
      stream.next(m.value);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SetModbusOutputRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dsr_msgs::SetModbusOutputRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dsr_msgs::SetModbusOutputRequest_<ContainerAllocator>& v)
  {
    s << indent << "name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.name);
    s << indent << "value: ";
    Printer<int32_t>::stream(s, indent + "  ", v.value);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DSR_MSGS_MESSAGE_SETMODBUSOUTPUTREQUEST_H
