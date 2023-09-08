; Auto-generated. Do not edit!


(cl:in-package dsr_msgs-srv)


;//! \htmlinclude MoveSplineTask-request.msg.html

(cl:defclass <MoveSplineTask-request> (roslisp-msg-protocol:ros-message)
  ((pos
    :reader pos
    :initarg :pos
    :type (cl:vector std_msgs-msg:Float64MultiArray)
   :initform (cl:make-array 0 :element-type 'std_msgs-msg:Float64MultiArray :initial-element (cl:make-instance 'std_msgs-msg:Float64MultiArray)))
   (posCnt
    :reader posCnt
    :initarg :posCnt
    :type cl:fixnum
    :initform 0)
   (vel
    :reader vel
    :initarg :vel
    :type (cl:vector cl:float)
   :initform (cl:make-array 2 :element-type 'cl:float :initial-element 0.0))
   (acc
    :reader acc
    :initarg :acc
    :type (cl:vector cl:float)
   :initform (cl:make-array 2 :element-type 'cl:float :initial-element 0.0))
   (time
    :reader time
    :initarg :time
    :type cl:float
    :initform 0.0)
   (ref
    :reader ref
    :initarg :ref
    :type cl:fixnum
    :initform 0)
   (mode
    :reader mode
    :initarg :mode
    :type cl:fixnum
    :initform 0)
   (opt
    :reader opt
    :initarg :opt
    :type cl:fixnum
    :initform 0)
   (syncType
    :reader syncType
    :initarg :syncType
    :type cl:fixnum
    :initform 0))
)

(cl:defclass MoveSplineTask-request (<MoveSplineTask-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MoveSplineTask-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MoveSplineTask-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name dsr_msgs-srv:<MoveSplineTask-request> is deprecated: use dsr_msgs-srv:MoveSplineTask-request instead.")))

(cl:ensure-generic-function 'pos-val :lambda-list '(m))
(cl:defmethod pos-val ((m <MoveSplineTask-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-srv:pos-val is deprecated.  Use dsr_msgs-srv:pos instead.")
  (pos m))

(cl:ensure-generic-function 'posCnt-val :lambda-list '(m))
(cl:defmethod posCnt-val ((m <MoveSplineTask-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-srv:posCnt-val is deprecated.  Use dsr_msgs-srv:posCnt instead.")
  (posCnt m))

(cl:ensure-generic-function 'vel-val :lambda-list '(m))
(cl:defmethod vel-val ((m <MoveSplineTask-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-srv:vel-val is deprecated.  Use dsr_msgs-srv:vel instead.")
  (vel m))

(cl:ensure-generic-function 'acc-val :lambda-list '(m))
(cl:defmethod acc-val ((m <MoveSplineTask-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-srv:acc-val is deprecated.  Use dsr_msgs-srv:acc instead.")
  (acc m))

(cl:ensure-generic-function 'time-val :lambda-list '(m))
(cl:defmethod time-val ((m <MoveSplineTask-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-srv:time-val is deprecated.  Use dsr_msgs-srv:time instead.")
  (time m))

(cl:ensure-generic-function 'ref-val :lambda-list '(m))
(cl:defmethod ref-val ((m <MoveSplineTask-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-srv:ref-val is deprecated.  Use dsr_msgs-srv:ref instead.")
  (ref m))

(cl:ensure-generic-function 'mode-val :lambda-list '(m))
(cl:defmethod mode-val ((m <MoveSplineTask-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-srv:mode-val is deprecated.  Use dsr_msgs-srv:mode instead.")
  (mode m))

(cl:ensure-generic-function 'opt-val :lambda-list '(m))
(cl:defmethod opt-val ((m <MoveSplineTask-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-srv:opt-val is deprecated.  Use dsr_msgs-srv:opt instead.")
  (opt m))

(cl:ensure-generic-function 'syncType-val :lambda-list '(m))
(cl:defmethod syncType-val ((m <MoveSplineTask-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-srv:syncType-val is deprecated.  Use dsr_msgs-srv:syncType instead.")
  (syncType m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MoveSplineTask-request>) ostream)
  "Serializes a message object of type '<MoveSplineTask-request>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'pos))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'pos))
  (cl:let* ((signed (cl:slot-value msg 'posCnt)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
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
  (cl:let* ((signed (cl:slot-value msg 'ref)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'mode)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'opt)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'syncType)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MoveSplineTask-request>) istream)
  "Deserializes a message object of type '<MoveSplineTask-request>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'pos) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'pos)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'std_msgs-msg:Float64MultiArray))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'posCnt) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  (cl:setf (cl:slot-value msg 'vel) (cl:make-array 2))
  (cl:let ((vals (cl:slot-value msg 'vel)))
    (cl:dotimes (i 2)
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
  (cl:setf (cl:slot-value msg 'acc) (cl:make-array 2))
  (cl:let ((vals (cl:slot-value msg 'acc)))
    (cl:dotimes (i 2)
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
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'ref) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'mode) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'opt) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'syncType) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MoveSplineTask-request>)))
  "Returns string type for a service object of type '<MoveSplineTask-request>"
  "dsr_msgs/MoveSplineTaskRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MoveSplineTask-request)))
  "Returns string type for a service object of type 'MoveSplineTask-request"
  "dsr_msgs/MoveSplineTaskRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MoveSplineTask-request>)))
  "Returns md5sum for a message object of type '<MoveSplineTask-request>"
  "2d3a3ddb20aee3a3824c2674bb8b535d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MoveSplineTask-request)))
  "Returns md5sum for a message object of type 'MoveSplineTask-request"
  "2d3a3ddb20aee3a3824c2674bb8b535d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MoveSplineTask-request>)))
  "Returns full string definition for message of type '<MoveSplineTask-request>"
  (cl:format cl:nil "#____________________________________________________________________________________________~%# move_spline_task  ~%###float64[100][6] pos            # target~%#____________________________________________________________________________________________~%~%std_msgs/Float64MultiArray[] pos  # target ~%int8            posCnt            # target cnt ~%float64[2]      vel               # set velocity: [mm/sec], [deg/sec]~%float64[2]      acc               # set acceleration: [mm/sec2], [deg/sec2]~%float64         time #= 0.0       # Time [sec] ~%int8            ref               # DR_BASE(0), DR_TOOL(1), DR_WORLD(2)~%                                  # <DR_WORLD is only available in M2.40 or later ~%int8            mode #= 0         # MOVE_MODE_ABSOLUTE=0, MOVE_MODE_RELATIVE=1 ~%int8            opt  #= 0         # SPLINE_VELOCITY_OPTION_DEFAULT=0, SPLINE_VELOCITY_OPTION_CONST=1 ~%int8            syncType #=0      # SYNC = 0, ASYNC = 1~%~%================================================================================~%MSG: std_msgs/Float64MultiArray~%# Please look at the MultiArrayLayout message definition for~%# documentation on all multiarrays.~%~%MultiArrayLayout  layout        # specification of data layout~%float64[]         data          # array of data~%~%~%================================================================================~%MSG: std_msgs/MultiArrayLayout~%# The multiarray declares a generic multi-dimensional array of a~%# particular data type.  Dimensions are ordered from outer most~%# to inner most.~%~%MultiArrayDimension[] dim # Array of dimension properties~%uint32 data_offset        # padding elements at front of data~%~%# Accessors should ALWAYS be written in terms of dimension stride~%# and specified outer-most dimension first.~%# ~%# multiarray(i,j,k) = data[data_offset + dim_stride[1]*i + dim_stride[2]*j + k]~%#~%# A standard, 3-channel 640x480 image with interleaved color channels~%# would be specified as:~%#~%# dim[0].label  = \"height\"~%# dim[0].size   = 480~%# dim[0].stride = 3*640*480 = 921600  (note dim[0] stride is just size of image)~%# dim[1].label  = \"width\"~%# dim[1].size   = 640~%# dim[1].stride = 3*640 = 1920~%# dim[2].label  = \"channel\"~%# dim[2].size   = 3~%# dim[2].stride = 3~%#~%# multiarray(i,j,k) refers to the ith row, jth column, and kth channel.~%~%================================================================================~%MSG: std_msgs/MultiArrayDimension~%string label   # label of given dimension~%uint32 size    # size of given dimension (in type units)~%uint32 stride  # stride of given dimension~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MoveSplineTask-request)))
  "Returns full string definition for message of type 'MoveSplineTask-request"
  (cl:format cl:nil "#____________________________________________________________________________________________~%# move_spline_task  ~%###float64[100][6] pos            # target~%#____________________________________________________________________________________________~%~%std_msgs/Float64MultiArray[] pos  # target ~%int8            posCnt            # target cnt ~%float64[2]      vel               # set velocity: [mm/sec], [deg/sec]~%float64[2]      acc               # set acceleration: [mm/sec2], [deg/sec2]~%float64         time #= 0.0       # Time [sec] ~%int8            ref               # DR_BASE(0), DR_TOOL(1), DR_WORLD(2)~%                                  # <DR_WORLD is only available in M2.40 or later ~%int8            mode #= 0         # MOVE_MODE_ABSOLUTE=0, MOVE_MODE_RELATIVE=1 ~%int8            opt  #= 0         # SPLINE_VELOCITY_OPTION_DEFAULT=0, SPLINE_VELOCITY_OPTION_CONST=1 ~%int8            syncType #=0      # SYNC = 0, ASYNC = 1~%~%================================================================================~%MSG: std_msgs/Float64MultiArray~%# Please look at the MultiArrayLayout message definition for~%# documentation on all multiarrays.~%~%MultiArrayLayout  layout        # specification of data layout~%float64[]         data          # array of data~%~%~%================================================================================~%MSG: std_msgs/MultiArrayLayout~%# The multiarray declares a generic multi-dimensional array of a~%# particular data type.  Dimensions are ordered from outer most~%# to inner most.~%~%MultiArrayDimension[] dim # Array of dimension properties~%uint32 data_offset        # padding elements at front of data~%~%# Accessors should ALWAYS be written in terms of dimension stride~%# and specified outer-most dimension first.~%# ~%# multiarray(i,j,k) = data[data_offset + dim_stride[1]*i + dim_stride[2]*j + k]~%#~%# A standard, 3-channel 640x480 image with interleaved color channels~%# would be specified as:~%#~%# dim[0].label  = \"height\"~%# dim[0].size   = 480~%# dim[0].stride = 3*640*480 = 921600  (note dim[0] stride is just size of image)~%# dim[1].label  = \"width\"~%# dim[1].size   = 640~%# dim[1].stride = 3*640 = 1920~%# dim[2].label  = \"channel\"~%# dim[2].size   = 3~%# dim[2].stride = 3~%#~%# multiarray(i,j,k) refers to the ith row, jth column, and kth channel.~%~%================================================================================~%MSG: std_msgs/MultiArrayDimension~%string label   # label of given dimension~%uint32 size    # size of given dimension (in type units)~%uint32 stride  # stride of given dimension~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MoveSplineTask-request>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'pos) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     1
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'vel) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'acc) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     8
     1
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MoveSplineTask-request>))
  "Converts a ROS message object to a list"
  (cl:list 'MoveSplineTask-request
    (cl:cons ':pos (pos msg))
    (cl:cons ':posCnt (posCnt msg))
    (cl:cons ':vel (vel msg))
    (cl:cons ':acc (acc msg))
    (cl:cons ':time (time msg))
    (cl:cons ':ref (ref msg))
    (cl:cons ':mode (mode msg))
    (cl:cons ':opt (opt msg))
    (cl:cons ':syncType (syncType msg))
))
;//! \htmlinclude MoveSplineTask-response.msg.html

(cl:defclass <MoveSplineTask-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass MoveSplineTask-response (<MoveSplineTask-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MoveSplineTask-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MoveSplineTask-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name dsr_msgs-srv:<MoveSplineTask-response> is deprecated: use dsr_msgs-srv:MoveSplineTask-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <MoveSplineTask-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-srv:success-val is deprecated.  Use dsr_msgs-srv:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MoveSplineTask-response>) ostream)
  "Serializes a message object of type '<MoveSplineTask-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MoveSplineTask-response>) istream)
  "Deserializes a message object of type '<MoveSplineTask-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MoveSplineTask-response>)))
  "Returns string type for a service object of type '<MoveSplineTask-response>"
  "dsr_msgs/MoveSplineTaskResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MoveSplineTask-response)))
  "Returns string type for a service object of type 'MoveSplineTask-response"
  "dsr_msgs/MoveSplineTaskResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MoveSplineTask-response>)))
  "Returns md5sum for a message object of type '<MoveSplineTask-response>"
  "2d3a3ddb20aee3a3824c2674bb8b535d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MoveSplineTask-response)))
  "Returns md5sum for a message object of type 'MoveSplineTask-response"
  "2d3a3ddb20aee3a3824c2674bb8b535d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MoveSplineTask-response>)))
  "Returns full string definition for message of type '<MoveSplineTask-response>"
  (cl:format cl:nil "bool success~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MoveSplineTask-response)))
  "Returns full string definition for message of type 'MoveSplineTask-response"
  (cl:format cl:nil "bool success~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MoveSplineTask-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MoveSplineTask-response>))
  "Converts a ROS message object to a list"
  (cl:list 'MoveSplineTask-response
    (cl:cons ':success (success msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'MoveSplineTask)))
  'MoveSplineTask-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'MoveSplineTask)))
  'MoveSplineTask-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MoveSplineTask)))
  "Returns string type for a service object of type '<MoveSplineTask>"
  "dsr_msgs/MoveSplineTask")