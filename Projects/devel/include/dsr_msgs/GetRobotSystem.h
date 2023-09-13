// Generated by gencpp from file dsr_msgs/GetRobotSystem.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_GETROBOTSYSTEM_H
#define DSR_MSGS_MESSAGE_GETROBOTSYSTEM_H

#include <ros/service_traits.h>


#include <dsr_msgs/GetRobotSystemRequest.h>
#include <dsr_msgs/GetRobotSystemResponse.h>


namespace dsr_msgs
{

struct GetRobotSystem
{

typedef GetRobotSystemRequest Request;
typedef GetRobotSystemResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct GetRobotSystem
} // namespace dsr_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::dsr_msgs::GetRobotSystem > {
  static const char* value()
  {
    return "20308dcb70c4e3f1df099ac95a676cf2";
  }

  static const char* value(const ::dsr_msgs::GetRobotSystem&) { return value(); }
};

template<>
struct DataType< ::dsr_msgs::GetRobotSystem > {
  static const char* value()
  {
    return "dsr_msgs/GetRobotSystem";
  }

  static const char* value(const ::dsr_msgs::GetRobotSystem&) { return value(); }
};


// service_traits::MD5Sum< ::dsr_msgs::GetRobotSystemRequest> should match
// service_traits::MD5Sum< ::dsr_msgs::GetRobotSystem >
template<>
struct MD5Sum< ::dsr_msgs::GetRobotSystemRequest>
{
  static const char* value()
  {
    return MD5Sum< ::dsr_msgs::GetRobotSystem >::value();
  }
  static const char* value(const ::dsr_msgs::GetRobotSystemRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::dsr_msgs::GetRobotSystemRequest> should match
// service_traits::DataType< ::dsr_msgs::GetRobotSystem >
template<>
struct DataType< ::dsr_msgs::GetRobotSystemRequest>
{
  static const char* value()
  {
    return DataType< ::dsr_msgs::GetRobotSystem >::value();
  }
  static const char* value(const ::dsr_msgs::GetRobotSystemRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::dsr_msgs::GetRobotSystemResponse> should match
// service_traits::MD5Sum< ::dsr_msgs::GetRobotSystem >
template<>
struct MD5Sum< ::dsr_msgs::GetRobotSystemResponse>
{
  static const char* value()
  {
    return MD5Sum< ::dsr_msgs::GetRobotSystem >::value();
  }
  static const char* value(const ::dsr_msgs::GetRobotSystemResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::dsr_msgs::GetRobotSystemResponse> should match
// service_traits::DataType< ::dsr_msgs::GetRobotSystem >
template<>
struct DataType< ::dsr_msgs::GetRobotSystemResponse>
{
  static const char* value()
  {
    return DataType< ::dsr_msgs::GetRobotSystem >::value();
  }
  static const char* value(const ::dsr_msgs::GetRobotSystemResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // DSR_MSGS_MESSAGE_GETROBOTSYSTEM_H