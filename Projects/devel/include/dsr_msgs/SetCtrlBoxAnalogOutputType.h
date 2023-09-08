// Generated by gencpp from file dsr_msgs/SetCtrlBoxAnalogOutputType.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_SETCTRLBOXANALOGOUTPUTTYPE_H
#define DSR_MSGS_MESSAGE_SETCTRLBOXANALOGOUTPUTTYPE_H

#include <ros/service_traits.h>


#include <dsr_msgs/SetCtrlBoxAnalogOutputTypeRequest.h>
#include <dsr_msgs/SetCtrlBoxAnalogOutputTypeResponse.h>


namespace dsr_msgs
{

struct SetCtrlBoxAnalogOutputType
{

typedef SetCtrlBoxAnalogOutputTypeRequest Request;
typedef SetCtrlBoxAnalogOutputTypeResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct SetCtrlBoxAnalogOutputType
} // namespace dsr_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::dsr_msgs::SetCtrlBoxAnalogOutputType > {
  static const char* value()
  {
    return "edb11f75523beab953b2183675ee124d";
  }

  static const char* value(const ::dsr_msgs::SetCtrlBoxAnalogOutputType&) { return value(); }
};

template<>
struct DataType< ::dsr_msgs::SetCtrlBoxAnalogOutputType > {
  static const char* value()
  {
    return "dsr_msgs/SetCtrlBoxAnalogOutputType";
  }

  static const char* value(const ::dsr_msgs::SetCtrlBoxAnalogOutputType&) { return value(); }
};


// service_traits::MD5Sum< ::dsr_msgs::SetCtrlBoxAnalogOutputTypeRequest> should match
// service_traits::MD5Sum< ::dsr_msgs::SetCtrlBoxAnalogOutputType >
template<>
struct MD5Sum< ::dsr_msgs::SetCtrlBoxAnalogOutputTypeRequest>
{
  static const char* value()
  {
    return MD5Sum< ::dsr_msgs::SetCtrlBoxAnalogOutputType >::value();
  }
  static const char* value(const ::dsr_msgs::SetCtrlBoxAnalogOutputTypeRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::dsr_msgs::SetCtrlBoxAnalogOutputTypeRequest> should match
// service_traits::DataType< ::dsr_msgs::SetCtrlBoxAnalogOutputType >
template<>
struct DataType< ::dsr_msgs::SetCtrlBoxAnalogOutputTypeRequest>
{
  static const char* value()
  {
    return DataType< ::dsr_msgs::SetCtrlBoxAnalogOutputType >::value();
  }
  static const char* value(const ::dsr_msgs::SetCtrlBoxAnalogOutputTypeRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::dsr_msgs::SetCtrlBoxAnalogOutputTypeResponse> should match
// service_traits::MD5Sum< ::dsr_msgs::SetCtrlBoxAnalogOutputType >
template<>
struct MD5Sum< ::dsr_msgs::SetCtrlBoxAnalogOutputTypeResponse>
{
  static const char* value()
  {
    return MD5Sum< ::dsr_msgs::SetCtrlBoxAnalogOutputType >::value();
  }
  static const char* value(const ::dsr_msgs::SetCtrlBoxAnalogOutputTypeResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::dsr_msgs::SetCtrlBoxAnalogOutputTypeResponse> should match
// service_traits::DataType< ::dsr_msgs::SetCtrlBoxAnalogOutputType >
template<>
struct DataType< ::dsr_msgs::SetCtrlBoxAnalogOutputTypeResponse>
{
  static const char* value()
  {
    return DataType< ::dsr_msgs::SetCtrlBoxAnalogOutputType >::value();
  }
  static const char* value(const ::dsr_msgs::SetCtrlBoxAnalogOutputTypeResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // DSR_MSGS_MESSAGE_SETCTRLBOXANALOGOUTPUTTYPE_H
