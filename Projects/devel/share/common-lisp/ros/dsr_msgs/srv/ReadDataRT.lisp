; Auto-generated. Do not edit!


(cl:in-package dsr_msgs-srv)


;//! \htmlinclude ReadDataRT-request.msg.html

(cl:defclass <ReadDataRT-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass ReadDataRT-request (<ReadDataRT-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ReadDataRT-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ReadDataRT-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name dsr_msgs-srv:<ReadDataRT-request> is deprecated: use dsr_msgs-srv:ReadDataRT-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ReadDataRT-request>) ostream)
  "Serializes a message object of type '<ReadDataRT-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ReadDataRT-request>) istream)
  "Deserializes a message object of type '<ReadDataRT-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ReadDataRT-request>)))
  "Returns string type for a service object of type '<ReadDataRT-request>"
  "dsr_msgs/ReadDataRTRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ReadDataRT-request)))
  "Returns string type for a service object of type 'ReadDataRT-request"
  "dsr_msgs/ReadDataRTRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ReadDataRT-request>)))
  "Returns md5sum for a message object of type '<ReadDataRT-request>"
  "1e1cb5234a76f1e708ea68842792bed5")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ReadDataRT-request)))
  "Returns md5sum for a message object of type 'ReadDataRT-request"
  "1e1cb5234a76f1e708ea68842792bed5")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ReadDataRT-request>)))
  "Returns full string definition for message of type '<ReadDataRT-request>"
  (cl:format cl:nil "#____________________________________________________________________________________________
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ReadDataRT-request)))
  "Returns full string definition for message of type 'ReadDataRT-request"
  (cl:format cl:nil "#____________________________________________________________________________________________
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ReadDataRT-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ReadDataRT-request>))
  "Converts a ROS message object to a list"
  (cl:list 'ReadDataRT-request
))
;//! \htmlinclude ReadDataRT-response.msg.html

(cl:defclass <ReadDataRT-response> (roslisp-msg-protocol:ros-message)
  ((data
    :reader data
    :initarg :data
    :type dsr_msgs-msg:RobotStateRT
    :initform (cl:make-instance 'dsr_msgs-msg:RobotStateRT)))
)

(cl:defclass ReadDataRT-response (<ReadDataRT-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ReadDataRT-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ReadDataRT-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name dsr_msgs-srv:<ReadDataRT-response> is deprecated: use dsr_msgs-srv:ReadDataRT-response instead.")))

(cl:ensure-generic-function 'data-val :lambda-list '(m))
(cl:defmethod data-val ((m <ReadDataRT-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-srv:data-val is deprecated.  Use dsr_msgs-srv:data instead.")
  (data m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ReadDataRT-response>) ostream)
  "Serializes a message object of type '<ReadDataRT-response>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'data) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ReadDataRT-response>) istream)
  "Deserializes a message object of type '<ReadDataRT-response>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'data) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ReadDataRT-response>)))
  "Returns string type for a service object of type '<ReadDataRT-response>"
  "dsr_msgs/ReadDataRTResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ReadDataRT-response)))
  "Returns string type for a service object of type 'ReadDataRT-response"
  "dsr_msgs/ReadDataRTResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ReadDataRT-response>)))
  "Returns md5sum for a message object of type '<ReadDataRT-response>"
  "1e1cb5234a76f1e708ea68842792bed5")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ReadDataRT-response)))
  "Returns md5sum for a message object of type 'ReadDataRT-response"
  "1e1cb5234a76f1e708ea68842792bed5")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ReadDataRT-response>)))
  "Returns full string definition for message of type '<ReadDataRT-response>"
  (cl:format cl:nil "RobotStateRT       data~%~%================================================================================~%MSG: dsr_msgs/RobotStateRT~%# timestamp at the data of data acquisition
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ReadDataRT-response)))
  "Returns full string definition for message of type 'ReadDataRT-response"
  (cl:format cl:nil "RobotStateRT       data~%~%================================================================================~%MSG: dsr_msgs/RobotStateRT~%# timestamp at the data of data acquisition
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ReadDataRT-response>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'data))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ReadDataRT-response>))
  "Converts a ROS message object to a list"
  (cl:list 'ReadDataRT-response
    (cl:cons ':data (data msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'ReadDataRT)))
  'ReadDataRT-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'ReadDataRT)))
  'ReadDataRT-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ReadDataRT)))
  "Returns string type for a service object of type '<ReadDataRT>"
  "dsr_msgs/ReadDataRT")