// Generated by gencpp from file dsr_msgs/Robotiq2FOpen.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_ROBOTIQ2FOPEN_H
#define DSR_MSGS_MESSAGE_ROBOTIQ2FOPEN_H

#include <ros/service_traits.h>


#include <dsr_msgs/Robotiq2FOpenRequest.h>
#include <dsr_msgs/Robotiq2FOpenResponse.h>


namespace dsr_msgs
{

struct Robotiq2FOpen
{

typedef Robotiq2FOpenRequest Request;
typedef Robotiq2FOpenResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct Robotiq2FOpen
} // namespace dsr_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::dsr_msgs::Robotiq2FOpen > {
  static const char* value()
  {
    return "358e233cde0c8a8bcfea4ce193f8fc15";
  }

  static const char* value(const ::dsr_msgs::Robotiq2FOpen&) { return value(); }
};

template<>
struct DataType< ::dsr_msgs::Robotiq2FOpen > {
  static const char* value()
  {
    return "dsr_msgs/Robotiq2FOpen";
  }

  static const char* value(const ::dsr_msgs::Robotiq2FOpen&) { return value(); }
};


// service_traits::MD5Sum< ::dsr_msgs::Robotiq2FOpenRequest> should match
// service_traits::MD5Sum< ::dsr_msgs::Robotiq2FOpen >
template<>
struct MD5Sum< ::dsr_msgs::Robotiq2FOpenRequest>
{
  static const char* value()
  {
    return MD5Sum< ::dsr_msgs::Robotiq2FOpen >::value();
  }
  static const char* value(const ::dsr_msgs::Robotiq2FOpenRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::dsr_msgs::Robotiq2FOpenRequest> should match
// service_traits::DataType< ::dsr_msgs::Robotiq2FOpen >
template<>
struct DataType< ::dsr_msgs::Robotiq2FOpenRequest>
{
  static const char* value()
  {
    return DataType< ::dsr_msgs::Robotiq2FOpen >::value();
  }
  static const char* value(const ::dsr_msgs::Robotiq2FOpenRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::dsr_msgs::Robotiq2FOpenResponse> should match
// service_traits::MD5Sum< ::dsr_msgs::Robotiq2FOpen >
template<>
struct MD5Sum< ::dsr_msgs::Robotiq2FOpenResponse>
{
  static const char* value()
  {
    return MD5Sum< ::dsr_msgs::Robotiq2FOpen >::value();
  }
  static const char* value(const ::dsr_msgs::Robotiq2FOpenResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::dsr_msgs::Robotiq2FOpenResponse> should match
// service_traits::DataType< ::dsr_msgs::Robotiq2FOpen >
template<>
struct DataType< ::dsr_msgs::Robotiq2FOpenResponse>
{
  static const char* value()
  {
    return DataType< ::dsr_msgs::Robotiq2FOpen >::value();
  }
  static const char* value(const ::dsr_msgs::Robotiq2FOpenResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // DSR_MSGS_MESSAGE_ROBOTIQ2FOPEN_H