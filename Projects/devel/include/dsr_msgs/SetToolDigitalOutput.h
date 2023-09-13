// Generated by gencpp from file dsr_msgs/SetToolDigitalOutput.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_SETTOOLDIGITALOUTPUT_H
#define DSR_MSGS_MESSAGE_SETTOOLDIGITALOUTPUT_H

#include <ros/service_traits.h>


#include <dsr_msgs/SetToolDigitalOutputRequest.h>
#include <dsr_msgs/SetToolDigitalOutputResponse.h>


namespace dsr_msgs
{

struct SetToolDigitalOutput
{

typedef SetToolDigitalOutputRequest Request;
typedef SetToolDigitalOutputResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct SetToolDigitalOutput
} // namespace dsr_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::dsr_msgs::SetToolDigitalOutput > {
  static const char* value()
  {
    return "fb5dce2e6988e39a422dd00d9d97c412";
  }

  static const char* value(const ::dsr_msgs::SetToolDigitalOutput&) { return value(); }
};

template<>
struct DataType< ::dsr_msgs::SetToolDigitalOutput > {
  static const char* value()
  {
    return "dsr_msgs/SetToolDigitalOutput";
  }

  static const char* value(const ::dsr_msgs::SetToolDigitalOutput&) { return value(); }
};


// service_traits::MD5Sum< ::dsr_msgs::SetToolDigitalOutputRequest> should match
// service_traits::MD5Sum< ::dsr_msgs::SetToolDigitalOutput >
template<>
struct MD5Sum< ::dsr_msgs::SetToolDigitalOutputRequest>
{
  static const char* value()
  {
    return MD5Sum< ::dsr_msgs::SetToolDigitalOutput >::value();
  }
  static const char* value(const ::dsr_msgs::SetToolDigitalOutputRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::dsr_msgs::SetToolDigitalOutputRequest> should match
// service_traits::DataType< ::dsr_msgs::SetToolDigitalOutput >
template<>
struct DataType< ::dsr_msgs::SetToolDigitalOutputRequest>
{
  static const char* value()
  {
    return DataType< ::dsr_msgs::SetToolDigitalOutput >::value();
  }
  static const char* value(const ::dsr_msgs::SetToolDigitalOutputRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::dsr_msgs::SetToolDigitalOutputResponse> should match
// service_traits::MD5Sum< ::dsr_msgs::SetToolDigitalOutput >
template<>
struct MD5Sum< ::dsr_msgs::SetToolDigitalOutputResponse>
{
  static const char* value()
  {
    return MD5Sum< ::dsr_msgs::SetToolDigitalOutput >::value();
  }
  static const char* value(const ::dsr_msgs::SetToolDigitalOutputResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::dsr_msgs::SetToolDigitalOutputResponse> should match
// service_traits::DataType< ::dsr_msgs::SetToolDigitalOutput >
template<>
struct DataType< ::dsr_msgs::SetToolDigitalOutputResponse>
{
  static const char* value()
  {
    return DataType< ::dsr_msgs::SetToolDigitalOutput >::value();
  }
  static const char* value(const ::dsr_msgs::SetToolDigitalOutputResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // DSR_MSGS_MESSAGE_SETTOOLDIGITALOUTPUT_H