; Auto-generated. Do not edit!


(cl:in-package dsr_msgs-srv)


;//! \htmlinclude AlterMotion-request.msg.html

(cl:defclass <AlterMotion-request> (roslisp-msg-protocol:ros-message)
  ((pos
    :reader pos
    :initarg :pos
    :type (cl:vector cl:float)
   :initform (cl:make-array 6 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass AlterMotion-request (<AlterMotion-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <AlterMotion-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'AlterMotion-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name dsr_msgs-srv:<AlterMotion-request> is deprecated: use dsr_msgs-srv:AlterMotion-request instead.")))

(cl:ensure-generic-function 'pos-val :lambda-list '(m))
(cl:defmethod pos-val ((m <AlterMotion-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-srv:pos-val is deprecated.  Use dsr_msgs-srv:pos instead.")
  (pos m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <AlterMotion-request>) ostream)
  "Serializes a message object of type '<AlterMotion-request>"
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'pos))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <AlterMotion-request>) istream)
  "Deserializes a message object of type '<AlterMotion-request>"
  (cl:setf (cl:slot-value msg 'pos) (cl:make-array 6))
  (cl:let ((vals (cl:slot-value msg 'pos)))
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
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<AlterMotion-request>)))
  "Returns string type for a service object of type '<AlterMotion-request>"
  "dsr_msgs/AlterMotionRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'AlterMotion-request)))
  "Returns string type for a service object of type 'AlterMotion-request"
  "dsr_msgs/AlterMotionRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<AlterMotion-request>)))
  "Returns md5sum for a message object of type '<AlterMotion-request>"
  "d61037f3a31077a87fa540cd63743057")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'AlterMotion-request)))
  "Returns md5sum for a message object of type 'AlterMotion-request"
  "d61037f3a31077a87fa540cd63743057")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<AlterMotion-request>)))
  "Returns full string definition for message of type '<AlterMotion-request>"
  (cl:format cl:nil "#____________________________________________________________________________________________~%# alter_motion  ~%# ~%#____________________________________________________________________________________________~%~%float64[6] pos               # position  ~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'AlterMotion-request)))
  "Returns full string definition for message of type 'AlterMotion-request"
  (cl:format cl:nil "#____________________________________________________________________________________________~%# alter_motion  ~%# ~%#____________________________________________________________________________________________~%~%float64[6] pos               # position  ~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <AlterMotion-request>))
  (cl:+ 0
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'pos) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <AlterMotion-request>))
  "Converts a ROS message object to a list"
  (cl:list 'AlterMotion-request
    (cl:cons ':pos (pos msg))
))
;//! \htmlinclude AlterMotion-response.msg.html

(cl:defclass <AlterMotion-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass AlterMotion-response (<AlterMotion-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <AlterMotion-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'AlterMotion-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name dsr_msgs-srv:<AlterMotion-response> is deprecated: use dsr_msgs-srv:AlterMotion-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <AlterMotion-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-srv:success-val is deprecated.  Use dsr_msgs-srv:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <AlterMotion-response>) ostream)
  "Serializes a message object of type '<AlterMotion-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <AlterMotion-response>) istream)
  "Deserializes a message object of type '<AlterMotion-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<AlterMotion-response>)))
  "Returns string type for a service object of type '<AlterMotion-response>"
  "dsr_msgs/AlterMotionResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'AlterMotion-response)))
  "Returns string type for a service object of type 'AlterMotion-response"
  "dsr_msgs/AlterMotionResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<AlterMotion-response>)))
  "Returns md5sum for a message object of type '<AlterMotion-response>"
  "d61037f3a31077a87fa540cd63743057")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'AlterMotion-response)))
  "Returns md5sum for a message object of type 'AlterMotion-response"
  "d61037f3a31077a87fa540cd63743057")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<AlterMotion-response>)))
  "Returns full string definition for message of type '<AlterMotion-response>"
  (cl:format cl:nil "bool success~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'AlterMotion-response)))
  "Returns full string definition for message of type 'AlterMotion-response"
  (cl:format cl:nil "bool success~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <AlterMotion-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <AlterMotion-response>))
  "Converts a ROS message object to a list"
  (cl:list 'AlterMotion-response
    (cl:cons ':success (success msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'AlterMotion)))
  'AlterMotion-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'AlterMotion)))
  'AlterMotion-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'AlterMotion)))
  "Returns string type for a service object of type '<AlterMotion>"
  "dsr_msgs/AlterMotion")