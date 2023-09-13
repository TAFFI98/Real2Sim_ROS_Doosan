// Generated by gencpp from file dsr_msgs/ReleaseComplianceCtrl.msg
// DO NOT EDIT!


#ifndef DSR_MSGS_MESSAGE_RELEASECOMPLIANCECTRL_H
#define DSR_MSGS_MESSAGE_RELEASECOMPLIANCECTRL_H

#include <ros/service_traits.h>


#include <dsr_msgs/ReleaseComplianceCtrlRequest.h>
#include <dsr_msgs/ReleaseComplianceCtrlResponse.h>


namespace dsr_msgs
{

struct ReleaseComplianceCtrl
{

typedef ReleaseComplianceCtrlRequest Request;
typedef ReleaseComplianceCtrlResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct ReleaseComplianceCtrl
} // namespace dsr_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::dsr_msgs::ReleaseComplianceCtrl > {
  static const char* value()
  {
    return "358e233cde0c8a8bcfea4ce193f8fc15";
  }

  static const char* value(const ::dsr_msgs::ReleaseComplianceCtrl&) { return value(); }
};

template<>
struct DataType< ::dsr_msgs::ReleaseComplianceCtrl > {
  static const char* value()
  {
    return "dsr_msgs/ReleaseComplianceCtrl";
  }

  static const char* value(const ::dsr_msgs::ReleaseComplianceCtrl&) { return value(); }
};


// service_traits::MD5Sum< ::dsr_msgs::ReleaseComplianceCtrlRequest> should match
// service_traits::MD5Sum< ::dsr_msgs::ReleaseComplianceCtrl >
template<>
struct MD5Sum< ::dsr_msgs::ReleaseComplianceCtrlRequest>
{
  static const char* value()
  {
    return MD5Sum< ::dsr_msgs::ReleaseComplianceCtrl >::value();
  }
  static const char* value(const ::dsr_msgs::ReleaseComplianceCtrlRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::dsr_msgs::ReleaseComplianceCtrlRequest> should match
// service_traits::DataType< ::dsr_msgs::ReleaseComplianceCtrl >
template<>
struct DataType< ::dsr_msgs::ReleaseComplianceCtrlRequest>
{
  static const char* value()
  {
    return DataType< ::dsr_msgs::ReleaseComplianceCtrl >::value();
  }
  static const char* value(const ::dsr_msgs::ReleaseComplianceCtrlRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::dsr_msgs::ReleaseComplianceCtrlResponse> should match
// service_traits::MD5Sum< ::dsr_msgs::ReleaseComplianceCtrl >
template<>
struct MD5Sum< ::dsr_msgs::ReleaseComplianceCtrlResponse>
{
  static const char* value()
  {
    return MD5Sum< ::dsr_msgs::ReleaseComplianceCtrl >::value();
  }
  static const char* value(const ::dsr_msgs::ReleaseComplianceCtrlResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::dsr_msgs::ReleaseComplianceCtrlResponse> should match
// service_traits::DataType< ::dsr_msgs::ReleaseComplianceCtrl >
template<>
struct DataType< ::dsr_msgs::ReleaseComplianceCtrlResponse>
{
  static const char* value()
  {
    return DataType< ::dsr_msgs::ReleaseComplianceCtrl >::value();
  }
  static const char* value(const ::dsr_msgs::ReleaseComplianceCtrlResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // DSR_MSGS_MESSAGE_RELEASECOMPLIANCECTRL_H