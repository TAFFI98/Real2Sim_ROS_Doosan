// Generated by gencpp from file dsr_msgs/SetRTControlInput.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_SETRTCONTROLINPUT_H
#define DSR_MSGS_MESSAGE_SETRTCONTROLINPUT_H

#include <ros/service_traits.h>


#include <dsr_msgs/SetRTControlInputRequest.h>
#include <dsr_msgs/SetRTControlInputResponse.h>


namespace dsr_msgs
{

struct SetRTControlInput
{

typedef SetRTControlInputRequest Request;
typedef SetRTControlInputResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct SetRTControlInput
} // namespace dsr_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::dsr_msgs::SetRTControlInput > {
  static const char* value()
  {
    return "adc3c45016368698475e43bea709f99f";
  }

  static const char* value(const ::dsr_msgs::SetRTControlInput&) { return value(); }
};

template<>
struct DataType< ::dsr_msgs::SetRTControlInput > {
  static const char* value()
  {
    return "dsr_msgs/SetRTControlInput";
  }

  static const char* value(const ::dsr_msgs::SetRTControlInput&) { return value(); }
};


// service_traits::MD5Sum< ::dsr_msgs::SetRTControlInputRequest> should match
// service_traits::MD5Sum< ::dsr_msgs::SetRTControlInput >
template<>
struct MD5Sum< ::dsr_msgs::SetRTControlInputRequest>
{
  static const char* value()
  {
    return MD5Sum< ::dsr_msgs::SetRTControlInput >::value();
  }
  static const char* value(const ::dsr_msgs::SetRTControlInputRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::dsr_msgs::SetRTControlInputRequest> should match
// service_traits::DataType< ::dsr_msgs::SetRTControlInput >
template<>
struct DataType< ::dsr_msgs::SetRTControlInputRequest>
{
  static const char* value()
  {
    return DataType< ::dsr_msgs::SetRTControlInput >::value();
  }
  static const char* value(const ::dsr_msgs::SetRTControlInputRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::dsr_msgs::SetRTControlInputResponse> should match
// service_traits::MD5Sum< ::dsr_msgs::SetRTControlInput >
template<>
struct MD5Sum< ::dsr_msgs::SetRTControlInputResponse>
{
  static const char* value()
  {
    return MD5Sum< ::dsr_msgs::SetRTControlInput >::value();
  }
  static const char* value(const ::dsr_msgs::SetRTControlInputResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::dsr_msgs::SetRTControlInputResponse> should match
// service_traits::DataType< ::dsr_msgs::SetRTControlInput >
template<>
struct DataType< ::dsr_msgs::SetRTControlInputResponse>
{
  static const char* value()
  {
    return DataType< ::dsr_msgs::SetRTControlInput >::value();
  }
  static const char* value(const ::dsr_msgs::SetRTControlInputResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // DSR_MSGS_MESSAGE_SETRTCONTROLINPUT_H