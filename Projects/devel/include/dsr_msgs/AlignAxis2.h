// Generated by gencpp from file dsr_msgs/AlignAxis2.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_ALIGNAXIS2_H
#define DSR_MSGS_MESSAGE_ALIGNAXIS2_H

#include <ros/service_traits.h>


#include <dsr_msgs/AlignAxis2Request.h>
#include <dsr_msgs/AlignAxis2Response.h>


namespace dsr_msgs
{

struct AlignAxis2
{

typedef AlignAxis2Request Request;
typedef AlignAxis2Response Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct AlignAxis2
} // namespace dsr_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::dsr_msgs::AlignAxis2 > {
  static const char* value()
  {
    return "789e8de44f005548a96c6375678d766c";
  }

  static const char* value(const ::dsr_msgs::AlignAxis2&) { return value(); }
};

template<>
struct DataType< ::dsr_msgs::AlignAxis2 > {
  static const char* value()
  {
    return "dsr_msgs/AlignAxis2";
  }

  static const char* value(const ::dsr_msgs::AlignAxis2&) { return value(); }
};


// service_traits::MD5Sum< ::dsr_msgs::AlignAxis2Request> should match
// service_traits::MD5Sum< ::dsr_msgs::AlignAxis2 >
template<>
struct MD5Sum< ::dsr_msgs::AlignAxis2Request>
{
  static const char* value()
  {
    return MD5Sum< ::dsr_msgs::AlignAxis2 >::value();
  }
  static const char* value(const ::dsr_msgs::AlignAxis2Request&)
  {
    return value();
  }
};

// service_traits::DataType< ::dsr_msgs::AlignAxis2Request> should match
// service_traits::DataType< ::dsr_msgs::AlignAxis2 >
template<>
struct DataType< ::dsr_msgs::AlignAxis2Request>
{
  static const char* value()
  {
    return DataType< ::dsr_msgs::AlignAxis2 >::value();
  }
  static const char* value(const ::dsr_msgs::AlignAxis2Request&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::dsr_msgs::AlignAxis2Response> should match
// service_traits::MD5Sum< ::dsr_msgs::AlignAxis2 >
template<>
struct MD5Sum< ::dsr_msgs::AlignAxis2Response>
{
  static const char* value()
  {
    return MD5Sum< ::dsr_msgs::AlignAxis2 >::value();
  }
  static const char* value(const ::dsr_msgs::AlignAxis2Response&)
  {
    return value();
  }
};

// service_traits::DataType< ::dsr_msgs::AlignAxis2Response> should match
// service_traits::DataType< ::dsr_msgs::AlignAxis2 >
template<>
struct DataType< ::dsr_msgs::AlignAxis2Response>
{
  static const char* value()
  {
    return DataType< ::dsr_msgs::AlignAxis2 >::value();
  }
  static const char* value(const ::dsr_msgs::AlignAxis2Response&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // DSR_MSGS_MESSAGE_ALIGNAXIS2_H
