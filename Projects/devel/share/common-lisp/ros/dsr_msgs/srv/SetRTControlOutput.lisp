; Auto-generated. Do not edit!


(cl:in-package dsr_msgs-srv)


;//! \htmlinclude SetRTControlOutput-request.msg.html

(cl:defclass <SetRTControlOutput-request> (roslisp-msg-protocol:ros-message)
  ((version
    :reader version
    :initarg :version
    :type cl:string
    :initform "")
   (period
    :reader period
    :initarg :period
    :type cl:float
    :initform 0.0)
   (loss
    :reader loss
    :initarg :loss
    :type cl:integer
    :initform 0))
)

(cl:defclass SetRTControlOutput-request (<SetRTControlOutput-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetRTControlOutput-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetRTControlOutput-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name dsr_msgs-srv:<SetRTControlOutput-request> is deprecated: use dsr_msgs-srv:SetRTControlOutput-request instead.")))

(cl:ensure-generic-function 'version-val :lambda-list '(m))
(cl:defmethod version-val ((m <SetRTControlOutput-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-srv:version-val is deprecated.  Use dsr_msgs-srv:version instead.")
  (version m))

(cl:ensure-generic-function 'period-val :lambda-list '(m))
(cl:defmethod period-val ((m <SetRTControlOutput-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-srv:period-val is deprecated.  Use dsr_msgs-srv:period instead.")
  (period m))

(cl:ensure-generic-function 'loss-val :lambda-list '(m))
(cl:defmethod loss-val ((m <SetRTControlOutput-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-srv:loss-val is deprecated.  Use dsr_msgs-srv:loss instead.")
  (loss m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetRTControlOutput-request>) ostream)
  "Serializes a message object of type '<SetRTControlOutput-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'version))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'version))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'period))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let* ((signed (cl:slot-value msg 'loss)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetRTControlOutput-request>) istream)
  "Deserializes a message object of type '<SetRTControlOutput-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'version) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'version) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'period) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'loss) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetRTControlOutput-request>)))
  "Returns string type for a service object of type '<SetRTControlOutput-request>"
  "dsr_msgs/SetRTControlOutputRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetRTControlOutput-request)))
  "Returns string type for a service object of type 'SetRTControlOutput-request"
  "dsr_msgs/SetRTControlOutputRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetRTControlOutput-request>)))
  "Returns md5sum for a message object of type '<SetRTControlOutput-request>"
  "adc3c45016368698475e43bea709f99f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetRTControlOutput-request)))
  "Returns md5sum for a message object of type 'SetRTControlOutput-request"
  "adc3c45016368698475e43bea709f99f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetRTControlOutput-request>)))
  "Returns full string definition for message of type '<SetRTControlOutput-request>"
  (cl:format cl:nil "#____________________________________________________________________________________________~%# set_rt_control_output~%#____________________________________________________________________________________________~%string     version~%float64    period~%int32      loss~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetRTControlOutput-request)))
  "Returns full string definition for message of type 'SetRTControlOutput-request"
  (cl:format cl:nil "#____________________________________________________________________________________________~%# set_rt_control_output~%#____________________________________________________________________________________________~%string     version~%float64    period~%int32      loss~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetRTControlOutput-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'version))
     8
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetRTControlOutput-request>))
  "Converts a ROS message object to a list"
  (cl:list 'SetRTControlOutput-request
    (cl:cons ':version (version msg))
    (cl:cons ':period (period msg))
    (cl:cons ':loss (loss msg))
))
;//! \htmlinclude SetRTControlOutput-response.msg.html

(cl:defclass <SetRTControlOutput-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass SetRTControlOutput-response (<SetRTControlOutput-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetRTControlOutput-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetRTControlOutput-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name dsr_msgs-srv:<SetRTControlOutput-response> is deprecated: use dsr_msgs-srv:SetRTControlOutput-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <SetRTControlOutput-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-srv:success-val is deprecated.  Use dsr_msgs-srv:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetRTControlOutput-response>) ostream)
  "Serializes a message object of type '<SetRTControlOutput-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetRTControlOutput-response>) istream)
  "Deserializes a message object of type '<SetRTControlOutput-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetRTControlOutput-response>)))
  "Returns string type for a service object of type '<SetRTControlOutput-response>"
  "dsr_msgs/SetRTControlOutputResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetRTControlOutput-response)))
  "Returns string type for a service object of type 'SetRTControlOutput-response"
  "dsr_msgs/SetRTControlOutputResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetRTControlOutput-response>)))
  "Returns md5sum for a message object of type '<SetRTControlOutput-response>"
  "adc3c45016368698475e43bea709f99f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetRTControlOutput-response)))
  "Returns md5sum for a message object of type 'SetRTControlOutput-response"
  "adc3c45016368698475e43bea709f99f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetRTControlOutput-response>)))
  "Returns full string definition for message of type '<SetRTControlOutput-response>"
  (cl:format cl:nil "bool       success~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetRTControlOutput-response)))
  "Returns full string definition for message of type 'SetRTControlOutput-response"
  (cl:format cl:nil "bool       success~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetRTControlOutput-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetRTControlOutput-response>))
  "Converts a ROS message object to a list"
  (cl:list 'SetRTControlOutput-response
    (cl:cons ':success (success msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'SetRTControlOutput)))
  'SetRTControlOutput-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'SetRTControlOutput)))
  'SetRTControlOutput-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetRTControlOutput)))
  "Returns string type for a service object of type '<SetRTControlOutput>"
  "dsr_msgs/SetRTControlOutput")