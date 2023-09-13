// Generated by gencpp from file dsr_msgs/ChangeOperationSpeed.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_CHANGEOPERATIONSPEED_H
#define DSR_MSGS_MESSAGE_CHANGEOPERATIONSPEED_H

#include <ros/service_traits.h>


#include <dsr_msgs/ChangeOperationSpeedRequest.h>
#include <dsr_msgs/ChangeOperationSpeedResponse.h>


namespace dsr_msgs
{

struct ChangeOperationSpeed
{

typedef ChangeOperationSpeedRequest Request;
typedef ChangeOperationSpeedResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct ChangeOperationSpeed
} // namespace dsr_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::dsr_msgs::ChangeOperationSpeed > {
  static const char* value()
  {
    return "a79c96510dc9b2ea7b678458340a61bf";
  }

  static const char* value(const ::dsr_msgs::ChangeOperationSpeed&) { return value(); }
};

template<>
struct DataType< ::dsr_msgs::ChangeOperationSpeed > {
  static const char* value()
  {
    return "dsr_msgs/ChangeOperationSpeed";
  }

  static const char* value(const ::dsr_msgs::ChangeOperationSpeed&) { return value(); }
};


// service_traits::MD5Sum< ::dsr_msgs::ChangeOperationSpeedRequest> should match
// service_traits::MD5Sum< ::dsr_msgs::ChangeOperationSpeed >
template<>
struct MD5Sum< ::dsr_msgs::ChangeOperationSpeedRequest>
{
  static const char* value()
  {
    return MD5Sum< ::dsr_msgs::ChangeOperationSpeed >::value();
  }
  static const char* value(const ::dsr_msgs::ChangeOperationSpeedRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::dsr_msgs::ChangeOperationSpeedRequest> should match
// service_traits::DataType< ::dsr_msgs::ChangeOperationSpeed >
template<>
struct DataType< ::dsr_msgs::ChangeOperationSpeedRequest>
{
  static const char* value()
  {
    return DataType< ::dsr_msgs::ChangeOperationSpeed >::value();
  }
  static const char* value(const ::dsr_msgs::ChangeOperationSpeedRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::dsr_msgs::ChangeOperationSpeedResponse> should match
// service_traits::MD5Sum< ::dsr_msgs::ChangeOperationSpeed >
template<>
struct MD5Sum< ::dsr_msgs::ChangeOperationSpeedResponse>
{
  static const char* value()
  {
    return MD5Sum< ::dsr_msgs::ChangeOperationSpeed >::value();
  }
  static const char* value(const ::dsr_msgs::ChangeOperationSpeedResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::dsr_msgs::ChangeOperationSpeedResponse> should match
// service_traits::DataType< ::dsr_msgs::ChangeOperationSpeed >
template<>
struct DataType< ::dsr_msgs::ChangeOperationSpeedResponse>
{
  static const char* value()
  {
    return DataType< ::dsr_msgs::ChangeOperationSpeed >::value();
  }
  static const char* value(const ::dsr_msgs::ChangeOperationSpeedResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // DSR_MSGS_MESSAGE_CHANGEOPERATIONSPEED_H