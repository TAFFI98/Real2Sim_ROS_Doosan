; Auto-generated. Do not edit!


(cl:in-package dsr_msgs-msg)


;//! \htmlinclude SpeedLRTStream.msg.html

(cl:defclass <SpeedLRTStream> (roslisp-msg-protocol:ros-message)
  ((vel
    :reader vel
    :initarg :vel
    :type (cl:vector cl:float)
   :initform (cl:make-array 6 :element-type 'cl:float :initial-element 0.0))
   (acc
    :reader acc
    :initarg :acc
    :type (cl:vector cl:float)
   :initform (cl:make-array 6 :element-type 'cl:float :initial-element 0.0))
   (time
    :reader time
    :initarg :time
    :type cl:float
    :initform 0.0))
)

(cl:defclass SpeedLRTStream (<SpeedLRTStream>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SpeedLRTStream>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SpeedLRTStream)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name dsr_msgs-msg:<SpeedLRTStream> is deprecated: use dsr_msgs-msg:SpeedLRTStream instead.")))

(cl:ensure-generic-function 'vel-val :lambda-list '(m))
(cl:defmethod vel-val ((m <SpeedLRTStream>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:vel-val is deprecated.  Use dsr_msgs-msg:vel instead.")
  (vel m))

(cl:ensure-generic-function 'acc-val :lambda-list '(m))
(cl:defmethod acc-val ((m <SpeedLRTStream>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:acc-val is deprecated.  Use dsr_msgs-msg:acc instead.")
  (acc m))

(cl:ensure-generic-function 'time-val :lambda-list '(m))
(cl:defmethod time-val ((m <SpeedLRTStream>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:time-val is deprecated.  Use dsr_msgs-msg:time instead.")
  (time m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SpeedLRTStream>) ostream)
  "Serializes a message object of type '<SpeedLRTStream>"
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'vel))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'acc))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'time))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SpeedLRTStream>) istream)
  "Deserializes a message object of type '<SpeedLRTStream>"
  (cl:setf (cl:slot-value msg 'vel) (cl:make-array 6))
  (cl:let ((vals (cl:slot-value msg 'vel)))
    (cl:dotimes (i 6)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-double-float-bits bits)))))
  (cl:setf (cl:slot-value msg 'acc) (cl:make-array 6))
  (cl:let ((vals (cl:slot-value msg 'acc)))
    (cl:dotimes (i 6)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-double-float-bits bits)))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'time) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SpeedLRTStream>)))
  "Returns string type for a message object of type '<SpeedLRTStream>"
  "dsr_msgs/SpeedLRTStream")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SpeedLRTStream)))
  "Returns string type for a message object of type 'SpeedLRTStream"
  "dsr_msgs/SpeedLRTStream")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SpeedLRTStream>)))
  "Returns md5sum for a message object of type '<SpeedLRTStream>"
  "e4ccbedcf19c8719d28eda24c562383b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SpeedLRTStream)))
  "Returns md5sum for a message object of type 'SpeedLRTStream"
  "e4ccbedcf19c8719d28eda24c562383b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SpeedLRTStream>)))
  "Returns full string definition for message of type '<SpeedLRTStream>"
  (cl:format cl:nil "#____________________________________________________________________________________________~%# speedl_rt~%# ~%#____________________________________________________________________________________________~%~%float64[6] vel               # velocity~%float64[6] acc               # acceleration~%float64    time              # time~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SpeedLRTStream)))
  "Returns full string definition for message of type 'SpeedLRTStream"
  (cl:format cl:nil "#____________________________________________________________________________________________~%# speedl_rt~%# ~%#____________________________________________________________________________________________~%~%float64[6] vel               # velocity~%float64[6] acc               # acceleration~%float64    time              # time~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SpeedLRTStream>))
  (cl:+ 0
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'vel) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'acc) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SpeedLRTStream>))
  "Converts a ROS message object to a list"
  (cl:list 'SpeedLRTStream
    (cl:cons ':vel (vel msg))
    (cl:cons ':acc (acc msg))
    (cl:cons ':time (time msg))
))
