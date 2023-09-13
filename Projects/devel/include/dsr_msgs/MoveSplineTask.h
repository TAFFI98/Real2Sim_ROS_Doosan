// Generated by gencpp from file dsr_msgs/MoveSplineTask.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_MOVESPLINETASK_H
#define DSR_MSGS_MESSAGE_MOVESPLINETASK_H

#include <ros/service_traits.h>


#include <dsr_msgs/MoveSplineTaskRequest.h>
#include <dsr_msgs/MoveSplineTaskResponse.h>


namespace dsr_msgs
{

struct MoveSplineTask
{

typedef MoveSplineTaskRequest Request;
typedef MoveSplineTaskResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct MoveSplineTask
} // namespace dsr_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::dsr_msgs::MoveSplineTask > {
  static const char* value()
  {
    return "2d3a3ddb20aee3a3824c2674bb8b535d";
  }

  static const char* value(const ::dsr_msgs::MoveSplineTask&) { return value(); }
};

template<>
struct DataType< ::dsr_msgs::MoveSplineTask > {
  static const char* value()
  {
    return "dsr_msgs/MoveSplineTask";
  }

  static const char* value(const ::dsr_msgs::MoveSplineTask&) { return value(); }
};


// service_traits::MD5Sum< ::dsr_msgs::MoveSplineTaskRequest> should match
// service_traits::MD5Sum< ::dsr_msgs::MoveSplineTask >
template<>
struct MD5Sum< ::dsr_msgs::MoveSplineTaskRequest>
{
  static const char* value()
  {
    return MD5Sum< ::dsr_msgs::MoveSplineTask >::value();
  }
  static const char* value(const ::dsr_msgs::MoveSplineTaskRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::dsr_msgs::MoveSplineTaskRequest> should match
// service_traits::DataType< ::dsr_msgs::MoveSplineTask >
template<>
struct DataType< ::dsr_msgs::MoveSplineTaskRequest>
{
  static const char* value()
  {
    return DataType< ::dsr_msgs::MoveSplineTask >::value();
  }
  static const char* value(const ::dsr_msgs::MoveSplineTaskRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::dsr_msgs::MoveSplineTaskResponse> should match
// service_traits::MD5Sum< ::dsr_msgs::MoveSplineTask >
template<>
struct MD5Sum< ::dsr_msgs::MoveSplineTaskResponse>
{
  static const char* value()
  {
    return MD5Sum< ::dsr_msgs::MoveSplineTask >::value();
  }
  static const char* value(const ::dsr_msgs::MoveSplineTaskResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::dsr_msgs::MoveSplineTaskResponse> should match
// service_traits::DataType< ::dsr_msgs::MoveSplineTask >
template<>
struct DataType< ::dsr_msgs::MoveSplineTaskResponse>
{
  static const char* value()
  {
    return DataType< ::dsr_msgs::MoveSplineTask >::value();
  }
  static const char* value(const ::dsr_msgs::MoveSplineTaskResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // DSR_MSGS_MESSAGE_MOVESPLINETASK_H