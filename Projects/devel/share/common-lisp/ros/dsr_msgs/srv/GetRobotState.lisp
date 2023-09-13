; Auto-generated. Do not edit!


(cl:in-package dsr_msgs-srv)


;//! \htmlinclude GetRobotState-request.msg.html

(cl:defclass <GetRobotState-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass GetRobotState-request (<GetRobotState-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GetRobotState-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GetRobotState-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name dsr_msgs-srv:<GetRobotState-request> is deprecated: use dsr_msgs-srv:GetRobotState-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GetRobotState-request>) ostream)
  "Serializes a message object of type '<GetRobotState-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GetRobotState-request>) istream)
  "Deserializes a message object of type '<GetRobotState-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GetRobotState-request>)))
  "Returns string type for a service object of type '<GetRobotState-request>"
  "dsr_msgs/GetRobotStateRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetRobotState-request)))
  "Returns string type for a service object of type 'GetRobotState-request"
  "dsr_msgs/GetRobotStateRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GetRobotState-request>)))
  "Returns md5sum for a message object of type '<GetRobotState-request>"
  "55f09762597f0e81f6f46902de1fad06")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GetRobotState-request)))
  "Returns md5sum for a message object of type 'GetRobotState-request"
  "55f09762597f0e81f6f46902de1fad06")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GetRobotState-request>)))
  "Returns full string definition for message of type '<GetRobotState-request>"
  (cl:format cl:nil "#____________________________________________________________________________________________
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GetRobotState-request)))
  "Returns full string definition for message of type 'GetRobotState-request"
  (cl:format cl:nil "#____________________________________________________________________________________________
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GetRobotState-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GetRobotState-request>))
  "Converts a ROS message object to a list"
  (cl:list 'GetRobotState-request
))
;//! \htmlinclude GetRobotState-response.msg.html

(cl:defclass <GetRobotState-response> (roslisp-msg-protocol:ros-message)
  ((robot_state
    :reader robot_state
    :initarg :robot_state
    :type cl:fixnum
    :initform 0)
   (success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass GetRobotState-response (<GetRobotState-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GetRobotState-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GetRobotState-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name dsr_msgs-srv:<GetRobotState-response> is deprecated: use dsr_msgs-srv:GetRobotState-response instead.")))

(cl:ensure-generic-function 'robot_state-val :lambda-list '(m))
(cl:defmethod robot_state-val ((m <GetRobotState-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-srv:robot_state-val is deprecated.  Use dsr_msgs-srv:robot_state instead.")
  (robot_state m))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <GetRobotState-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-srv:success-val is deprecated.  Use dsr_msgs-srv:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GetRobotState-response>) ostream)
  "Serializes a message object of type '<GetRobotState-response>"
  (cl:let* ((signed (cl:slot-value msg 'robot_state)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GetRobotState-response>) istream)
  "Deserializes a message object of type '<GetRobotState-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'robot_state) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GetRobotState-response>)))
  "Returns string type for a service object of type '<GetRobotState-response>"
  "dsr_msgs/GetRobotStateResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetRobotState-response)))
  "Returns string type for a service object of type 'GetRobotState-response"
  "dsr_msgs/GetRobotStateResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GetRobotState-response>)))
  "Returns md5sum for a message object of type '<GetRobotState-response>"
  "55f09762597f0e81f6f46902de1fad06")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GetRobotState-response)))
  "Returns md5sum for a message object of type 'GetRobotState-response"
  "55f09762597f0e81f6f46902de1fad06")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GetRobotState-response>)))
  "Returns full string definition for message of type '<GetRobotState-response>"
  (cl:format cl:nil "int8 robot_state    # 0 : STATE_INITIALIZING
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GetRobotState-response)))
  "Returns full string definition for message of type 'GetRobotState-response"
  (cl:format cl:nil "int8 robot_state    # 0 : STATE_INITIALIZING
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GetRobotState-response>))
  (cl:+ 0
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GetRobotState-response>))
  "Converts a ROS message object to a list"
  (cl:list 'GetRobotState-response
    (cl:cons ':robot_state (robot_state msg))
    (cl:cons ':success (success msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'GetRobotState)))
  'GetRobotState-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'GetRobotState)))
  'GetRobotState-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetRobotState)))
  "Returns string type for a service object of type '<GetRobotState>"
  "dsr_msgs/GetRobotState")