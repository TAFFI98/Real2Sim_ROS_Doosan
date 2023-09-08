// Generated by gencpp from file dsr_msgs/GetSolutionSpaceRequest.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_GETSOLUTIONSPACEREQUEST_H
#define DSR_MSGS_MESSAGE_GETSOLUTIONSPACEREQUEST_H


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
struct GetSolutionSpaceRequest_
{
  typedef GetSolutionSpaceRequest_<ContainerAllocator> Type;

  GetSolutionSpaceRequest_()
    : pos()  {
      pos.assign(0.0);
  }
  GetSolutionSpaceRequest_(const ContainerAllocator& _alloc)
    : pos()  {
  (void)_alloc;
      pos.assign(0.0);
  }



   typedef boost::array<double, 6>  _pos_type;
  _pos_type pos;





  typedef boost::shared_ptr< ::dsr_msgs::GetSolutionSpaceRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dsr_msgs::GetSolutionSpaceRequest_<ContainerAllocator> const> ConstPtr;

}; // struct GetSolutionSpaceRequest_

typedef ::dsr_msgs::GetSolutionSpaceRequest_<std::allocator<void> > GetSolutionSpaceRequest;

typedef boost::shared_ptr< ::dsr_msgs::GetSolutionSpaceRequest > GetSolutionSpaceRequestPtr;
typedef boost::shared_ptr< ::dsr_msgs::GetSolutionSpaceRequest const> GetSolutionSpaceRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dsr_msgs::GetSolutionSpaceRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dsr_msgs::GetSolutionSpaceRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::dsr_msgs::GetSolutionSpaceRequest_<ContainerAllocator1> & lhs, const ::dsr_msgs::GetSolutionSpaceRequest_<ContainerAllocator2> & rhs)
{
  return lhs.pos == rhs.pos;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::dsr_msgs::GetSolutionSpaceRequest_<ContainerAllocator1> & lhs, const ::dsr_msgs::GetSolutionSpaceRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace dsr_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::GetSolutionSpaceRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dsr_msgs::GetSolutionSpaceRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::GetSolutionSpaceRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dsr_msgs::GetSolutionSpaceRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::GetSolutionSpaceRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dsr_msgs::GetSolutionSpaceRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dsr_msgs::GetSolutionSpaceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "537431324117c3d1847d70e057990155";
  }

  static const char* value(const ::dsr_msgs::GetSolutionSpaceRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x537431324117c3d1ULL;
  static const uint64_t static_value2 = 0x847d70e057990155ULL;
};

template<class ContainerAllocator>
struct DataType< ::dsr_msgs::GetSolutionSpaceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dsr_msgs/GetSolutionSpaceRequest";
  }

  static const char* value(const ::dsr_msgs::GetSolutionSpaceRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dsr_msgs::GetSolutionSpaceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#____________________________________________________________________________________________\n"
"# get_solution_space(pos)  \n"
"#____________________________________________________________________________________________\n"
"# This service obtains the solution space value.\n"
"\n"
"float64[6] pos               # joint angle list [degree] \n"
;
  }

  static const char* value(const ::dsr_msgs::GetSolutionSpaceRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dsr_msgs::GetSolutionSpaceRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.pos);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GetSolutionSpaceRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dsr_msgs::GetSolutionSpaceRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dsr_msgs::GetSolutionSpaceRequest_<ContainerAllocator>& v)
  {
    s << indent << "pos[]" << std::endl;
    for (size_t i = 0; i < v.pos.size(); ++i)
    {
      s << indent << "  pos[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.pos[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // DSR_MSGS_MESSAGE_GETSOLUTIONSPACEREQUEST_H
