// Generated by gencpp from file dsr_msgs/MoveStop.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_MOVESTOP_H
#define DSR_MSGS_MESSAGE_MOVESTOP_H

#include <ros/service_traits.h>


#include <dsr_msgs/MoveStopRequest.h>
#include <dsr_msgs/MoveStopResponse.h>


namespace dsr_msgs
{

struct MoveStop
{

typedef MoveStopRequest Request;
typedef MoveStopResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct MoveStop
} // namespace dsr_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::dsr_msgs::MoveStop > {
  static const char* value()
  {
    return "a0a25e9e76d4431108e6e2682aa29331";
  }

  static const char* value(const ::dsr_msgs::MoveStop&) { return value(); }
};

template<>
struct DataType< ::dsr_msgs::MoveStop > {
  static const char* value()
  {
    return "dsr_msgs/MoveStop";
  }

  static const char* value(const ::dsr_msgs::MoveStop&) { return value(); }
};


// service_traits::MD5Sum< ::dsr_msgs::MoveStopRequest> should match
// service_traits::MD5Sum< ::dsr_msgs::MoveStop >
template<>
struct MD5Sum< ::dsr_msgs::MoveStopRequest>
{
  static const char* value()
  {
    return MD5Sum< ::dsr_msgs::MoveStop >::value();
  }
  static const char* value(const ::dsr_msgs::MoveStopRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::dsr_msgs::MoveStopRequest> should match
// service_traits::DataType< ::dsr_msgs::MoveStop >
template<>
struct DataType< ::dsr_msgs::MoveStopRequest>
{
  static const char* value()
  {
    return DataType< ::dsr_msgs::MoveStop >::value();
  }
  static const char* value(const ::dsr_msgs::MoveStopRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::dsr_msgs::MoveStopResponse> should match
// service_traits::MD5Sum< ::dsr_msgs::MoveStop >
template<>
struct MD5Sum< ::dsr_msgs::MoveStopResponse>
{
  static const char* value()
  {
    return MD5Sum< ::dsr_msgs::MoveStop >::value();
  }
  static const char* value(const ::dsr_msgs::MoveStopResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::dsr_msgs::MoveStopResponse> should match
// service_traits::DataType< ::dsr_msgs::MoveStop >
template<>
struct DataType< ::dsr_msgs::MoveStopResponse>
{
  static const char* value()
  {
    return DataType< ::dsr_msgs::MoveStop >::value();
  }
  static const char* value(const ::dsr_msgs::MoveStopResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // DSR_MSGS_MESSAGE_MOVESTOP_H