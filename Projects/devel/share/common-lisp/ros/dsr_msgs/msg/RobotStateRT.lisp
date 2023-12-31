; Auto-generated. Do not edit!


(cl:in-package dsr_msgs-msg)


;//! \htmlinclude RobotStateRT.msg.html

(cl:defclass <RobotStateRT> (roslisp-msg-protocol:ros-message)
  ((time_stamp
    :reader time_stamp
    :initarg :time_stamp
    :type cl:float
    :initform 0.0)
   (actual_joint_position
    :reader actual_joint_position
    :initarg :actual_joint_position
    :type (cl:vector cl:float)
   :initform (cl:make-array 6 :element-type 'cl:float :initial-element 0.0))
   (actual_joint_position_abs
    :reader actual_joint_position_abs
    :initarg :actual_joint_position_abs
    :type (cl:vector cl:float)
   :initform (cl:make-array 6 :element-type 'cl:float :initial-element 0.0))
   (actual_joint_velocity
    :reader actual_joint_velocity
    :initarg :actual_joint_velocity
    :type (cl:vector cl:float)
   :initform (cl:make-array 6 :element-type 'cl:float :initial-element 0.0))
   (actual_joint_velocity_abs
    :reader actual_joint_velocity_abs
    :initarg :actual_joint_velocity_abs
    :type (cl:vector cl:float)
   :initform (cl:make-array 6 :element-type 'cl:float :initial-element 0.0))
   (actual_tcp_position
    :reader actual_tcp_position
    :initarg :actual_tcp_position
    :type (cl:vector cl:float)
   :initform (cl:make-array 6 :element-type 'cl:float :initial-element 0.0))
   (actual_tcp_velocity
    :reader actual_tcp_velocity
    :initarg :actual_tcp_velocity
    :type (cl:vector cl:float)
   :initform (cl:make-array 6 :element-type 'cl:float :initial-element 0.0))
   (actual_flange_position
    :reader actual_flange_position
    :initarg :actual_flange_position
    :type (cl:vector cl:float)
   :initform (cl:make-array 6 :element-type 'cl:float :initial-element 0.0))
   (actual_flange_velocity
    :reader actual_flange_velocity
    :initarg :actual_flange_velocity
    :type (cl:vector cl:float)
   :initform (cl:make-array 6 :element-type 'cl:float :initial-element 0.0))
   (actual_motor_torque
    :reader actual_motor_torque
    :initarg :actual_motor_torque
    :type (cl:vector cl:float)
   :initform (cl:make-array 6 :element-type 'cl:float :initial-element 0.0))
   (actual_joint_torque
    :reader actual_joint_torque
    :initarg :actual_joint_torque
    :type (cl:vector cl:float)
   :initform (cl:make-array 6 :element-type 'cl:float :initial-element 0.0))
   (raw_joint_torque
    :reader raw_joint_torque
    :initarg :raw_joint_torque
    :type (cl:vector cl:float)
   :initform (cl:make-array 6 :element-type 'cl:float :initial-element 0.0))
   (raw_force_torque
    :reader raw_force_torque
    :initarg :raw_force_torque
    :type (cl:vector cl:float)
   :initform (cl:make-array 6 :element-type 'cl:float :initial-element 0.0))
   (external_joint_torque
    :reader external_joint_torque
    :initarg :external_joint_torque
    :type (cl:vector cl:float)
   :initform (cl:make-array 6 :element-type 'cl:float :initial-element 0.0))
   (external_tcp_force
    :reader external_tcp_force
    :initarg :external_tcp_force
    :type (cl:vector cl:float)
   :initform (cl:make-array 6 :element-type 'cl:float :initial-element 0.0))
   (target_joint_position
    :reader target_joint_position
    :initarg :target_joint_position
    :type (cl:vector cl:float)
   :initform (cl:make-array 6 :element-type 'cl:float :initial-element 0.0))
   (target_joint_velocity
    :reader target_joint_velocity
    :initarg :target_joint_velocity
    :type (cl:vector cl:float)
   :initform (cl:make-array 6 :element-type 'cl:float :initial-element 0.0))
   (target_joint_acceleration
    :reader target_joint_acceleration
    :initarg :target_joint_acceleration
    :type (cl:vector cl:float)
   :initform (cl:make-array 6 :element-type 'cl:float :initial-element 0.0))
   (target_motor_torque
    :reader target_motor_torque
    :initarg :target_motor_torque
    :type (cl:vector cl:float)
   :initform (cl:make-array 6 :element-type 'cl:float :initial-element 0.0))
   (target_tcp_position
    :reader target_tcp_position
    :initarg :target_tcp_position
    :type (cl:vector cl:float)
   :initform (cl:make-array 6 :element-type 'cl:float :initial-element 0.0))
   (target_tcp_velocity
    :reader target_tcp_velocity
    :initarg :target_tcp_velocity
    :type (cl:vector cl:float)
   :initform (cl:make-array 6 :element-type 'cl:float :initial-element 0.0))
   (jacobian_matrix
    :reader jacobian_matrix
    :initarg :jacobian_matrix
    :type (cl:vector std_msgs-msg:Float64MultiArray)
   :initform (cl:make-array 0 :element-type 'std_msgs-msg:Float64MultiArray :initial-element (cl:make-instance 'std_msgs-msg:Float64MultiArray)))
   (gravity_torque
    :reader gravity_torque
    :initarg :gravity_torque
    :type (cl:vector cl:float)
   :initform (cl:make-array 6 :element-type 'cl:float :initial-element 0.0))
   (coriolis_matrix
    :reader coriolis_matrix
    :initarg :coriolis_matrix
    :type (cl:vector std_msgs-msg:Float64MultiArray)
   :initform (cl:make-array 0 :element-type 'std_msgs-msg:Float64MultiArray :initial-element (cl:make-instance 'std_msgs-msg:Float64MultiArray)))
   (mass_matrix
    :reader mass_matrix
    :initarg :mass_matrix
    :type (cl:vector std_msgs-msg:Float64MultiArray)
   :initform (cl:make-array 0 :element-type 'std_msgs-msg:Float64MultiArray :initial-element (cl:make-instance 'std_msgs-msg:Float64MultiArray)))
   (solution_space
    :reader solution_space
    :initarg :solution_space
    :type cl:fixnum
    :initform 0)
   (singularity
    :reader singularity
    :initarg :singularity
    :type cl:float
    :initform 0.0)
   (operation_speed_rate
    :reader operation_speed_rate
    :initarg :operation_speed_rate
    :type cl:float
    :initform 0.0)
   (joint_temperature
    :reader joint_temperature
    :initarg :joint_temperature
    :type (cl:vector cl:float)
   :initform (cl:make-array 6 :element-type 'cl:float :initial-element 0.0))
   (controller_digital_input
    :reader controller_digital_input
    :initarg :controller_digital_input
    :type cl:fixnum
    :initform 0)
   (controller_digital_output
    :reader controller_digital_output
    :initarg :controller_digital_output
    :type cl:fixnum
    :initform 0)
   (controller_analog_input_type
    :reader controller_analog_input_type
    :initarg :controller_analog_input_type
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 2 :element-type 'cl:fixnum :initial-element 0))
   (controller_analog_input
    :reader controller_analog_input
    :initarg :controller_analog_input
    :type (cl:vector cl:float)
   :initform (cl:make-array 2 :element-type 'cl:float :initial-element 0.0))
   (controller_analog_output_type
    :reader controller_analog_output_type
    :initarg :controller_analog_output_type
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 2 :element-type 'cl:fixnum :initial-element 0))
   (controller_analog_output
    :reader controller_analog_output
    :initarg :controller_analog_output
    :type (cl:vector cl:float)
   :initform (cl:make-array 2 :element-type 'cl:float :initial-element 0.0))
   (flange_digital_input
    :reader flange_digital_input
    :initarg :flange_digital_input
    :type cl:fixnum
    :initform 0)
   (flange_digital_output
    :reader flange_digital_output
    :initarg :flange_digital_output
    :type cl:fixnum
    :initform 0)
   (flange_analog_input
    :reader flange_analog_input
    :initarg :flange_analog_input
    :type (cl:vector cl:float)
   :initform (cl:make-array 4 :element-type 'cl:float :initial-element 0.0))
   (external_encoder_strobe_count
    :reader external_encoder_strobe_count
    :initarg :external_encoder_strobe_count
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 2 :element-type 'cl:fixnum :initial-element 0))
   (external_encoder_count
    :reader external_encoder_count
    :initarg :external_encoder_count
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 2 :element-type 'cl:fixnum :initial-element 0))
   (goal_joint_position
    :reader goal_joint_position
    :initarg :goal_joint_position
    :type (cl:vector cl:float)
   :initform (cl:make-array 6 :element-type 'cl:float :initial-element 0.0))
   (goal_tcp_position
    :reader goal_tcp_position
    :initarg :goal_tcp_position
    :type (cl:vector cl:float)
   :initform (cl:make-array 6 :element-type 'cl:float :initial-element 0.0))
   (robot_mode
    :reader robot_mode
    :initarg :robot_mode
    :type cl:fixnum
    :initform 0)
   (robot_state
    :reader robot_state
    :initarg :robot_state
    :type cl:fixnum
    :initform 0)
   (control_mode
    :reader control_mode
    :initarg :control_mode
    :type cl:fixnum
    :initform 0)
   (reserved
    :reader reserved
    :initarg :reserved
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 256 :element-type 'cl:fixnum :initial-element 0)))
)

(cl:defclass RobotStateRT (<RobotStateRT>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RobotStateRT>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RobotStateRT)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name dsr_msgs-msg:<RobotStateRT> is deprecated: use dsr_msgs-msg:RobotStateRT instead.")))

(cl:ensure-generic-function 'time_stamp-val :lambda-list '(m))
(cl:defmethod time_stamp-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:time_stamp-val is deprecated.  Use dsr_msgs-msg:time_stamp instead.")
  (time_stamp m))

(cl:ensure-generic-function 'actual_joint_position-val :lambda-list '(m))
(cl:defmethod actual_joint_position-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:actual_joint_position-val is deprecated.  Use dsr_msgs-msg:actual_joint_position instead.")
  (actual_joint_position m))

(cl:ensure-generic-function 'actual_joint_position_abs-val :lambda-list '(m))
(cl:defmethod actual_joint_position_abs-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:actual_joint_position_abs-val is deprecated.  Use dsr_msgs-msg:actual_joint_position_abs instead.")
  (actual_joint_position_abs m))

(cl:ensure-generic-function 'actual_joint_velocity-val :lambda-list '(m))
(cl:defmethod actual_joint_velocity-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:actual_joint_velocity-val is deprecated.  Use dsr_msgs-msg:actual_joint_velocity instead.")
  (actual_joint_velocity m))

(cl:ensure-generic-function 'actual_joint_velocity_abs-val :lambda-list '(m))
(cl:defmethod actual_joint_velocity_abs-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:actual_joint_velocity_abs-val is deprecated.  Use dsr_msgs-msg:actual_joint_velocity_abs instead.")
  (actual_joint_velocity_abs m))

(cl:ensure-generic-function 'actual_tcp_position-val :lambda-list '(m))
(cl:defmethod actual_tcp_position-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:actual_tcp_position-val is deprecated.  Use dsr_msgs-msg:actual_tcp_position instead.")
  (actual_tcp_position m))

(cl:ensure-generic-function 'actual_tcp_velocity-val :lambda-list '(m))
(cl:defmethod actual_tcp_velocity-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:actual_tcp_velocity-val is deprecated.  Use dsr_msgs-msg:actual_tcp_velocity instead.")
  (actual_tcp_velocity m))

(cl:ensure-generic-function 'actual_flange_position-val :lambda-list '(m))
(cl:defmethod actual_flange_position-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:actual_flange_position-val is deprecated.  Use dsr_msgs-msg:actual_flange_position instead.")
  (actual_flange_position m))

(cl:ensure-generic-function 'actual_flange_velocity-val :lambda-list '(m))
(cl:defmethod actual_flange_velocity-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:actual_flange_velocity-val is deprecated.  Use dsr_msgs-msg:actual_flange_velocity instead.")
  (actual_flange_velocity m))

(cl:ensure-generic-function 'actual_motor_torque-val :lambda-list '(m))
(cl:defmethod actual_motor_torque-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:actual_motor_torque-val is deprecated.  Use dsr_msgs-msg:actual_motor_torque instead.")
  (actual_motor_torque m))

(cl:ensure-generic-function 'actual_joint_torque-val :lambda-list '(m))
(cl:defmethod actual_joint_torque-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:actual_joint_torque-val is deprecated.  Use dsr_msgs-msg:actual_joint_torque instead.")
  (actual_joint_torque m))

(cl:ensure-generic-function 'raw_joint_torque-val :lambda-list '(m))
(cl:defmethod raw_joint_torque-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:raw_joint_torque-val is deprecated.  Use dsr_msgs-msg:raw_joint_torque instead.")
  (raw_joint_torque m))

(cl:ensure-generic-function 'raw_force_torque-val :lambda-list '(m))
(cl:defmethod raw_force_torque-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:raw_force_torque-val is deprecated.  Use dsr_msgs-msg:raw_force_torque instead.")
  (raw_force_torque m))

(cl:ensure-generic-function 'external_joint_torque-val :lambda-list '(m))
(cl:defmethod external_joint_torque-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:external_joint_torque-val is deprecated.  Use dsr_msgs-msg:external_joint_torque instead.")
  (external_joint_torque m))

(cl:ensure-generic-function 'external_tcp_force-val :lambda-list '(m))
(cl:defmethod external_tcp_force-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:external_tcp_force-val is deprecated.  Use dsr_msgs-msg:external_tcp_force instead.")
  (external_tcp_force m))

(cl:ensure-generic-function 'target_joint_position-val :lambda-list '(m))
(cl:defmethod target_joint_position-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:target_joint_position-val is deprecated.  Use dsr_msgs-msg:target_joint_position instead.")
  (target_joint_position m))

(cl:ensure-generic-function 'target_joint_velocity-val :lambda-list '(m))
(cl:defmethod target_joint_velocity-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:target_joint_velocity-val is deprecated.  Use dsr_msgs-msg:target_joint_velocity instead.")
  (target_joint_velocity m))

(cl:ensure-generic-function 'target_joint_acceleration-val :lambda-list '(m))
(cl:defmethod target_joint_acceleration-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:target_joint_acceleration-val is deprecated.  Use dsr_msgs-msg:target_joint_acceleration instead.")
  (target_joint_acceleration m))

(cl:ensure-generic-function 'target_motor_torque-val :lambda-list '(m))
(cl:defmethod target_motor_torque-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:target_motor_torque-val is deprecated.  Use dsr_msgs-msg:target_motor_torque instead.")
  (target_motor_torque m))

(cl:ensure-generic-function 'target_tcp_position-val :lambda-list '(m))
(cl:defmethod target_tcp_position-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:target_tcp_position-val is deprecated.  Use dsr_msgs-msg:target_tcp_position instead.")
  (target_tcp_position m))

(cl:ensure-generic-function 'target_tcp_velocity-val :lambda-list '(m))
(cl:defmethod target_tcp_velocity-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:target_tcp_velocity-val is deprecated.  Use dsr_msgs-msg:target_tcp_velocity instead.")
  (target_tcp_velocity m))

(cl:ensure-generic-function 'jacobian_matrix-val :lambda-list '(m))
(cl:defmethod jacobian_matrix-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:jacobian_matrix-val is deprecated.  Use dsr_msgs-msg:jacobian_matrix instead.")
  (jacobian_matrix m))

(cl:ensure-generic-function 'gravity_torque-val :lambda-list '(m))
(cl:defmethod gravity_torque-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:gravity_torque-val is deprecated.  Use dsr_msgs-msg:gravity_torque instead.")
  (gravity_torque m))

(cl:ensure-generic-function 'coriolis_matrix-val :lambda-list '(m))
(cl:defmethod coriolis_matrix-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:coriolis_matrix-val is deprecated.  Use dsr_msgs-msg:coriolis_matrix instead.")
  (coriolis_matrix m))

(cl:ensure-generic-function 'mass_matrix-val :lambda-list '(m))
(cl:defmethod mass_matrix-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:mass_matrix-val is deprecated.  Use dsr_msgs-msg:mass_matrix instead.")
  (mass_matrix m))

(cl:ensure-generic-function 'solution_space-val :lambda-list '(m))
(cl:defmethod solution_space-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:solution_space-val is deprecated.  Use dsr_msgs-msg:solution_space instead.")
  (solution_space m))

(cl:ensure-generic-function 'singularity-val :lambda-list '(m))
(cl:defmethod singularity-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:singularity-val is deprecated.  Use dsr_msgs-msg:singularity instead.")
  (singularity m))

(cl:ensure-generic-function 'operation_speed_rate-val :lambda-list '(m))
(cl:defmethod operation_speed_rate-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:operation_speed_rate-val is deprecated.  Use dsr_msgs-msg:operation_speed_rate instead.")
  (operation_speed_rate m))

(cl:ensure-generic-function 'joint_temperature-val :lambda-list '(m))
(cl:defmethod joint_temperature-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:joint_temperature-val is deprecated.  Use dsr_msgs-msg:joint_temperature instead.")
  (joint_temperature m))

(cl:ensure-generic-function 'controller_digital_input-val :lambda-list '(m))
(cl:defmethod controller_digital_input-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:controller_digital_input-val is deprecated.  Use dsr_msgs-msg:controller_digital_input instead.")
  (controller_digital_input m))

(cl:ensure-generic-function 'controller_digital_output-val :lambda-list '(m))
(cl:defmethod controller_digital_output-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:controller_digital_output-val is deprecated.  Use dsr_msgs-msg:controller_digital_output instead.")
  (controller_digital_output m))

(cl:ensure-generic-function 'controller_analog_input_type-val :lambda-list '(m))
(cl:defmethod controller_analog_input_type-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:controller_analog_input_type-val is deprecated.  Use dsr_msgs-msg:controller_analog_input_type instead.")
  (controller_analog_input_type m))

(cl:ensure-generic-function 'controller_analog_input-val :lambda-list '(m))
(cl:defmethod controller_analog_input-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:controller_analog_input-val is deprecated.  Use dsr_msgs-msg:controller_analog_input instead.")
  (controller_analog_input m))

(cl:ensure-generic-function 'controller_analog_output_type-val :lambda-list '(m))
(cl:defmethod controller_analog_output_type-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:controller_analog_output_type-val is deprecated.  Use dsr_msgs-msg:controller_analog_output_type instead.")
  (controller_analog_output_type m))

(cl:ensure-generic-function 'controller_analog_output-val :lambda-list '(m))
(cl:defmethod controller_analog_output-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:controller_analog_output-val is deprecated.  Use dsr_msgs-msg:controller_analog_output instead.")
  (controller_analog_output m))

(cl:ensure-generic-function 'flange_digital_input-val :lambda-list '(m))
(cl:defmethod flange_digital_input-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:flange_digital_input-val is deprecated.  Use dsr_msgs-msg:flange_digital_input instead.")
  (flange_digital_input m))

(cl:ensure-generic-function 'flange_digital_output-val :lambda-list '(m))
(cl:defmethod flange_digital_output-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:flange_digital_output-val is deprecated.  Use dsr_msgs-msg:flange_digital_output instead.")
  (flange_digital_output m))

(cl:ensure-generic-function 'flange_analog_input-val :lambda-list '(m))
(cl:defmethod flange_analog_input-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:flange_analog_input-val is deprecated.  Use dsr_msgs-msg:flange_analog_input instead.")
  (flange_analog_input m))

(cl:ensure-generic-function 'external_encoder_strobe_count-val :lambda-list '(m))
(cl:defmethod external_encoder_strobe_count-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:external_encoder_strobe_count-val is deprecated.  Use dsr_msgs-msg:external_encoder_strobe_count instead.")
  (external_encoder_strobe_count m))

(cl:ensure-generic-function 'external_encoder_count-val :lambda-list '(m))
(cl:defmethod external_encoder_count-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:external_encoder_count-val is deprecated.  Use dsr_msgs-msg:external_encoder_count instead.")
  (external_encoder_count m))

(cl:ensure-generic-function 'goal_joint_position-val :lambda-list '(m))
(cl:defmethod goal_joint_position-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:goal_joint_position-val is deprecated.  Use dsr_msgs-msg:goal_joint_position instead.")
  (goal_joint_position m))

(cl:ensure-generic-function 'goal_tcp_position-val :lambda-list '(m))
(cl:defmethod goal_tcp_position-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:goal_tcp_position-val is deprecated.  Use dsr_msgs-msg:goal_tcp_position instead.")
  (goal_tcp_position m))

(cl:ensure-generic-function 'robot_mode-val :lambda-list '(m))
(cl:defmethod robot_mode-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:robot_mode-val is deprecated.  Use dsr_msgs-msg:robot_mode instead.")
  (robot_mode m))

(cl:ensure-generic-function 'robot_state-val :lambda-list '(m))
(cl:defmethod robot_state-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:robot_state-val is deprecated.  Use dsr_msgs-msg:robot_state instead.")
  (robot_state m))

(cl:ensure-generic-function 'control_mode-val :lambda-list '(m))
(cl:defmethod control_mode-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:control_mode-val is deprecated.  Use dsr_msgs-msg:control_mode instead.")
  (control_mode m))

(cl:ensure-generic-function 'reserved-val :lambda-list '(m))
(cl:defmethod reserved-val ((m <RobotStateRT>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dsr_msgs-msg:reserved-val is deprecated.  Use dsr_msgs-msg:reserved instead.")
  (reserved m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RobotStateRT>) ostream)
  "Serializes a message object of type '<RobotStateRT>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'time_stamp))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'actual_joint_position))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'actual_joint_position_abs))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'actual_joint_velocity))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'actual_joint_velocity_abs))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'actual_tcp_position))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'actual_tcp_velocity))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'actual_flange_position))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'actual_flange_velocity))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'actual_motor_torque))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'actual_joint_torque))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'raw_joint_torque))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'raw_force_torque))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'external_joint_torque))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'external_tcp_force))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'target_joint_position))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'target_joint_velocity))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'target_joint_acceleration))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'target_motor_torque))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'target_tcp_position))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'target_tcp_velocity))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'jacobian_matrix))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'jacobian_matrix))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'gravity_torque))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'coriolis_matrix))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'coriolis_matrix))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'mass_matrix))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'mass_matrix))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'solution_space)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'solution_space)) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'singularity))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'operation_speed_rate))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'joint_temperature))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'controller_digital_input)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'controller_digital_input)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'controller_digital_output)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'controller_digital_output)) ostream)
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'controller_analog_input_type))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'controller_analog_input))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'controller_analog_output_type))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'controller_analog_output))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'flange_digital_input)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'flange_digital_output)) ostream)
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'flange_analog_input))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'external_encoder_strobe_count))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) ele) ostream))
   (cl:slot-value msg 'external_encoder_count))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'goal_joint_position))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'goal_tcp_position))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'robot_mode)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'robot_state)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'control_mode)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'control_mode)) ostream)
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'reserved))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RobotStateRT>) istream)
  "Deserializes a message object of type '<RobotStateRT>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'time_stamp) (roslisp-utils:decode-double-float-bits bits)))
  (cl:setf (cl:slot-value msg 'actual_joint_position) (cl:make-array 6))
  (cl:let ((vals (cl:slot-value msg 'actual_joint_position)))
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
  (cl:setf (cl:slot-value msg 'actual_joint_position_abs) (cl:make-array 6))
  (cl:let ((vals (cl:slot-value msg 'actual_joint_position_abs)))
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
  (cl:setf (cl:slot-value msg 'actual_joint_velocity) (cl:make-array 6))
  (cl:let ((vals (cl:slot-value msg 'actual_joint_velocity)))
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
  (cl:setf (cl:slot-value msg 'actual_joint_velocity_abs) (cl:make-array 6))
  (cl:let ((vals (cl:slot-value msg 'actual_joint_velocity_abs)))
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
  (cl:setf (cl:slot-value msg 'actual_tcp_position) (cl:make-array 6))
  (cl:let ((vals (cl:slot-value msg 'actual_tcp_position)))
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
  (cl:setf (cl:slot-value msg 'actual_tcp_velocity) (cl:make-array 6))
  (cl:let ((vals (cl:slot-value msg 'actual_tcp_velocity)))
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
  (cl:setf (cl:slot-value msg 'actual_flange_position) (cl:make-array 6))
  (cl:let ((vals (cl:slot-value msg 'actual_flange_position)))
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
  (cl:setf (cl:slot-value msg 'actual_flange_velocity) (cl:make-array 6))
  (cl:let ((vals (cl:slot-value msg 'actual_flange_velocity)))
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
  (cl:setf (cl:slot-value msg 'actual_motor_torque) (cl:make-array 6))
  (cl:let ((vals (cl:slot-value msg 'actual_motor_torque)))
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
  (cl:setf (cl:slot-value msg 'actual_joint_torque) (cl:make-array 6))
  (cl:let ((vals (cl:slot-value msg 'actual_joint_torque)))
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
  (cl:setf (cl:slot-value msg 'raw_joint_torque) (cl:make-array 6))
  (cl:let ((vals (cl:slot-value msg 'raw_joint_torque)))
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
  (cl:setf (cl:slot-value msg 'raw_force_torque) (cl:make-array 6))
  (cl:let ((vals (cl:slot-value msg 'raw_force_torque)))
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
  (cl:setf (cl:slot-value msg 'external_joint_torque) (cl:make-array 6))
  (cl:let ((vals (cl:slot-value msg 'external_joint_torque)))
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
  (cl:setf (cl:slot-value msg 'external_tcp_force) (cl:make-array 6))
  (cl:let ((vals (cl:slot-value msg 'external_tcp_force)))
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
  (cl:setf (cl:slot-value msg 'target_joint_position) (cl:make-array 6))
  (cl:let ((vals (cl:slot-value msg 'target_joint_position)))
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
  (cl:setf (cl:slot-value msg 'target_joint_velocity) (cl:make-array 6))
  (cl:let ((vals (cl:slot-value msg 'target_joint_velocity)))
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
  (cl:setf (cl:slot-value msg 'target_joint_acceleration) (cl:make-array 6))
  (cl:let ((vals (cl:slot-value msg 'target_joint_acceleration)))
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
  (cl:setf (cl:slot-value msg 'target_motor_torque) (cl:make-array 6))
  (cl:let ((vals (cl:slot-value msg 'target_motor_torque)))
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
  (cl:setf (cl:slot-value msg 'target_tcp_position) (cl:make-array 6))
  (cl:let ((vals (cl:slot-value msg 'target_tcp_position)))
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
  (cl:setf (cl:slot-value msg 'target_tcp_velocity) (cl:make-array 6))
  (cl:let ((vals (cl:slot-value msg 'target_tcp_velocity)))
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
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'jacobian_matrix) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'jacobian_matrix)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'std_msgs-msg:Float64MultiArray))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  (cl:setf (cl:slot-value msg 'gravity_torque) (cl:make-array 6))
  (cl:let ((vals (cl:slot-value msg 'gravity_torque)))
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
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'coriolis_matrix) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'coriolis_matrix)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'std_msgs-msg:Float64MultiArray))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'mass_matrix) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'mass_matrix)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'std_msgs-msg:Float64MultiArray))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'solution_space)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'solution_space)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'singularity) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'operation_speed_rate) (roslisp-utils:decode-double-float-bits bits)))
  (cl:setf (cl:slot-value msg 'joint_temperature) (cl:make-array 6))
  (cl:let ((vals (cl:slot-value msg 'joint_temperature)))
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
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'controller_digital_input)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'controller_digital_input)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'controller_digital_output)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'controller_digital_output)) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'controller_analog_input_type) (cl:make-array 2))
  (cl:let ((vals (cl:slot-value msg 'controller_analog_input_type)))
    (cl:dotimes (i 2)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream))))
  (cl:setf (cl:slot-value msg 'controller_analog_input) (cl:make-array 2))
  (cl:let ((vals (cl:slot-value msg 'controller_analog_input)))
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
  (cl:setf (cl:slot-value msg 'controller_analog_output_type) (cl:make-array 2))
  (cl:let ((vals (cl:slot-value msg 'controller_analog_output_type)))
    (cl:dotimes (i 2)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream))))
  (cl:setf (cl:slot-value msg 'controller_analog_output) (cl:make-array 2))
  (cl:let ((vals (cl:slot-value msg 'controller_analog_output)))
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
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'flange_digital_input)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'flange_digital_output)) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'flange_analog_input) (cl:make-array 4))
  (cl:let ((vals (cl:slot-value msg 'flange_analog_input)))
    (cl:dotimes (i 4)
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
  (cl:setf (cl:slot-value msg 'external_encoder_strobe_count) (cl:make-array 2))
  (cl:let ((vals (cl:slot-value msg 'external_encoder_strobe_count)))
    (cl:dotimes (i 2)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream))))
  (cl:setf (cl:slot-value msg 'external_encoder_count) (cl:make-array 2))
  (cl:let ((vals (cl:slot-value msg 'external_encoder_count)))
    (cl:dotimes (i 2)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:aref vals i)) (cl:read-byte istream))))
  (cl:setf (cl:slot-value msg 'goal_joint_position) (cl:make-array 6))
  (cl:let ((vals (cl:slot-value msg 'goal_joint_position)))
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
  (cl:setf (cl:slot-value msg 'goal_tcp_position) (cl:make-array 6))
  (cl:let ((vals (cl:slot-value msg 'goal_tcp_position)))
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
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'robot_mode)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'robot_state)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'control_mode)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'control_mode)) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'reserved) (cl:make-array 256))
  (cl:let ((vals (cl:slot-value msg 'reserved)))
    (cl:dotimes (i 256)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RobotStateRT>)))
  "Returns string type for a message object of type '<RobotStateRT>"
  "dsr_msgs/RobotStateRT")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RobotStateRT)))
  "Returns string type for a message object of type 'RobotStateRT"
  "dsr_msgs/RobotStateRT")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RobotStateRT>)))
  "Returns md5sum for a message object of type '<RobotStateRT>"
  "3fc4bdbba50c12ddf9126a58ad825fc4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RobotStateRT)))
  "Returns md5sum for a message object of type 'RobotStateRT"
  "3fc4bdbba50c12ddf9126a58ad825fc4")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RobotStateRT>)))
  "Returns full string definition for message of type '<RobotStateRT>"
  (cl:format cl:nil "# timestamp at the data of data acquisition~%float64                      time_stamp~%# actual joint position from incremental encoder at motor side(used for control) [deg]~%float64[6]                   actual_joint_position~%# actual joint position from absolute encoder at link side (used for exact link position) [deg]~%float64[6]                   actual_joint_position_abs~%# actual joint velocity from incremental encoder at motor side [deg/s]~%float64[6]                   actual_joint_velocity~%# actual joint velocity from absolute encoder at link side [deg/s]~%float64[6]                   actual_joint_velocity_abs~%# actual robot tcp position w.r.t. base coordinates: (x, y, z, a, b, c), where (a, b, c) follows Euler ZYZ notation [mm, deg]~%float64[6]                   actual_tcp_position~%# actual robot tcp velocity w.r.t. base coordinates [mm, deg/s]~%float64[6]                   actual_tcp_velocity~%# actual robot flange position w.r.t. base coordinates: (x, y, z, a, b, c), where (a, b, c) follows Euler ZYZ notation [mm, deg]~%float64[6]                   actual_flange_position~%# robot flange velocity w.r.t. base coordinates [mm, deg/s]~%float64[6]                   actual_flange_velocity~%# actual motor torque applying gear ratio = gear_ratio * current2torque_constant * motor current [Nm]~%float64[6]                   actual_motor_torque~%# estimated joint torque by robot controller [Nm]~%float64[6]                   actual_joint_torque~%# calibrated joint torque sensor data [Nm]~%float64[6]                   raw_joint_torque~%# calibrated force torque sensor data w.r.t. flange coordinates [N, Nm]~%float64[6]                   raw_force_torque~%# estimated external joint torque [Nm]~%float64[6]                   external_joint_torque~%# estimated tcp force w.r.t. base coordinates [N, Nm] ~%float64[6]                   external_tcp_force~%# target joint position [deg]~%float64[6]                   target_joint_position~%# target joint velocity [deg/s]~%float64[6]                   target_joint_velocity~%# target joint acceleration [deg/s^2] ~%float64[6]                   target_joint_acceleration~%# target motor torque [Nm] ~%float64[6]                   target_motor_torque~%# target tcp position w.r.t. base coordinates: (x, y, z, a, b, c), where (a, b, c) follows Euler ZYZ notation [mm, deg] ~%float64[6]                   target_tcp_position~%# target tcp velocity w.r.t. base coordinates [mm, deg/s]~%float64[6]                   target_tcp_velocity~%# jacobian matrix=J(q) w.r.t. base coordinates~%std_msgs/Float64MultiArray[] jacobian_matrix~%# gravity torque=g(q) [Nm]~%float64[6]                   gravity_torque~%# coriolis matrix=C(q,q_dot)  [6][6]~%std_msgs/Float64MultiArray[] coriolis_matrix~%# mass matrix=M(q) [6][6]~%std_msgs/Float64MultiArray[] mass_matrix~%# robot configuration ~%uint16                       solution_space~%# minimum singular value ~%float64                      singularity~%# current operation speed rate(1~~100 %) ~%float64                      operation_speed_rate~%# joint temperature(celsius) ~%float64[6]                   joint_temperature~%# controller digital input(16 channel) ~%uint16                       controller_digital_input~%# controller digital output(16 channel) ~%uint16                       controller_digital_output~%# controller analog input type(2 channel) ~%uint8[2]                      controller_analog_input_type~%# controller analog input(2 channel) ~%float64[2]                   controller_analog_input~%# controller analog output type(2 channel) ~%uint8[2]                     controller_analog_output_type~%# controller analog output(2 channel) ~%float64[2]                   controller_analog_output~%# flange digital input(A-Series: 2 channel, M/H-Series: 6 channel) ~%uint8                        flange_digital_input~%# flange digital output(A-Series: 2 channel, M/H-Series: 6 channel) ~%uint8                        flange_digital_output~%# flange analog input(A-Series: 2 channel, M/H-Series: 4 channel) ~%float64[4]                   flange_analog_input~%# strobe count(increased by 1 when detecting setting edge) ~%uint8[2]                     external_encoder_strobe_count~%# external encoder count ~%uint16[2]                    external_encoder_count~%# final goal joint position (reserved) ~%float64[6]                   goal_joint_position~%# final goal tcp position (reserved) ~%float64[6]                   goal_tcp_position~%# ROBOT_MODE_MANUAL(0), ROBOT_MODE_AUTONOMOUS(1), ROBOT_MODE_MEASURE(2) ~%uint8                        robot_mode~%# STATE_INITIALIZING(0), STATE_STANDBY(1), STATE_MOVING(2), STATE_SAFE_OFF(3), STATE_TEACHING(4), STATE_SAFE_STOP(5), STATE_EMERGENCY_STOP, STATE_HOMMING, STATE_RECOVERY, STATE_SAFE_STOP2, STATE_SAFE_OFF2, ~%uint8                        robot_state~%# position control mode, torque mode ~%uint16                       control_mode~%# Reserved ~%uint8[256]                   reserved~%================================================================================~%MSG: std_msgs/Float64MultiArray~%# Please look at the MultiArrayLayout message definition for~%# documentation on all multiarrays.~%~%MultiArrayLayout  layout        # specification of data layout~%float64[]         data          # array of data~%~%~%================================================================================~%MSG: std_msgs/MultiArrayLayout~%# The multiarray declares a generic multi-dimensional array of a~%# particular data type.  Dimensions are ordered from outer most~%# to inner most.~%~%MultiArrayDimension[] dim # Array of dimension properties~%uint32 data_offset        # padding elements at front of data~%~%# Accessors should ALWAYS be written in terms of dimension stride~%# and specified outer-most dimension first.~%# ~%# multiarray(i,j,k) = data[data_offset + dim_stride[1]*i + dim_stride[2]*j + k]~%#~%# A standard, 3-channel 640x480 image with interleaved color channels~%# would be specified as:~%#~%# dim[0].label  = \"height\"~%# dim[0].size   = 480~%# dim[0].stride = 3*640*480 = 921600  (note dim[0] stride is just size of image)~%# dim[1].label  = \"width\"~%# dim[1].size   = 640~%# dim[1].stride = 3*640 = 1920~%# dim[2].label  = \"channel\"~%# dim[2].size   = 3~%# dim[2].stride = 3~%#~%# multiarray(i,j,k) refers to the ith row, jth column, and kth channel.~%~%================================================================================~%MSG: std_msgs/MultiArrayDimension~%string label   # label of given dimension~%uint32 size    # size of given dimension (in type units)~%uint32 stride  # stride of given dimension~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RobotStateRT)))
  "Returns full string definition for message of type 'RobotStateRT"
  (cl:format cl:nil "# timestamp at the data of data acquisition~%float64                      time_stamp~%# actual joint position from incremental encoder at motor side(used for control) [deg]~%float64[6]                   actual_joint_position~%# actual joint position from absolute encoder at link side (used for exact link position) [deg]~%float64[6]                   actual_joint_position_abs~%# actual joint velocity from incremental encoder at motor side [deg/s]~%float64[6]                   actual_joint_velocity~%# actual joint velocity from absolute encoder at link side [deg/s]~%float64[6]                   actual_joint_velocity_abs~%# actual robot tcp position w.r.t. base coordinates: (x, y, z, a, b, c), where (a, b, c) follows Euler ZYZ notation [mm, deg]~%float64[6]                   actual_tcp_position~%# actual robot tcp velocity w.r.t. base coordinates [mm, deg/s]~%float64[6]                   actual_tcp_velocity~%# actual robot flange position w.r.t. base coordinates: (x, y, z, a, b, c), where (a, b, c) follows Euler ZYZ notation [mm, deg]~%float64[6]                   actual_flange_position~%# robot flange velocity w.r.t. base coordinates [mm, deg/s]~%float64[6]                   actual_flange_velocity~%# actual motor torque applying gear ratio = gear_ratio * current2torque_constant * motor current [Nm]~%float64[6]                   actual_motor_torque~%# estimated joint torque by robot controller [Nm]~%float64[6]                   actual_joint_torque~%# calibrated joint torque sensor data [Nm]~%float64[6]                   raw_joint_torque~%# calibrated force torque sensor data w.r.t. flange coordinates [N, Nm]~%float64[6]                   raw_force_torque~%# estimated external joint torque [Nm]~%float64[6]                   external_joint_torque~%# estimated tcp force w.r.t. base coordinates [N, Nm] ~%float64[6]                   external_tcp_force~%# target joint position [deg]~%float64[6]                   target_joint_position~%# target joint velocity [deg/s]~%float64[6]                   target_joint_velocity~%# target joint acceleration [deg/s^2] ~%float64[6]                   target_joint_acceleration~%# target motor torque [Nm] ~%float64[6]                   target_motor_torque~%# target tcp position w.r.t. base coordinates: (x, y, z, a, b, c), where (a, b, c) follows Euler ZYZ notation [mm, deg] ~%float64[6]                   target_tcp_position~%# target tcp velocity w.r.t. base coordinates [mm, deg/s]~%float64[6]                   target_tcp_velocity~%# jacobian matrix=J(q) w.r.t. base coordinates~%std_msgs/Float64MultiArray[] jacobian_matrix~%# gravity torque=g(q) [Nm]~%float64[6]                   gravity_torque~%# coriolis matrix=C(q,q_dot)  [6][6]~%std_msgs/Float64MultiArray[] coriolis_matrix~%# mass matrix=M(q) [6][6]~%std_msgs/Float64MultiArray[] mass_matrix~%# robot configuration ~%uint16                       solution_space~%# minimum singular value ~%float64                      singularity~%# current operation speed rate(1~~100 %) ~%float64                      operation_speed_rate~%# joint temperature(celsius) ~%float64[6]                   joint_temperature~%# controller digital input(16 channel) ~%uint16                       controller_digital_input~%# controller digital output(16 channel) ~%uint16                       controller_digital_output~%# controller analog input type(2 channel) ~%uint8[2]                      controller_analog_input_type~%# controller analog input(2 channel) ~%float64[2]                   controller_analog_input~%# controller analog output type(2 channel) ~%uint8[2]                     controller_analog_output_type~%# controller analog output(2 channel) ~%float64[2]                   controller_analog_output~%# flange digital input(A-Series: 2 channel, M/H-Series: 6 channel) ~%uint8                        flange_digital_input~%# flange digital output(A-Series: 2 channel, M/H-Series: 6 channel) ~%uint8                        flange_digital_output~%# flange analog input(A-Series: 2 channel, M/H-Series: 4 channel) ~%float64[4]                   flange_analog_input~%# strobe count(increased by 1 when detecting setting edge) ~%uint8[2]                     external_encoder_strobe_count~%# external encoder count ~%uint16[2]                    external_encoder_count~%# final goal joint position (reserved) ~%float64[6]                   goal_joint_position~%# final goal tcp position (reserved) ~%float64[6]                   goal_tcp_position~%# ROBOT_MODE_MANUAL(0), ROBOT_MODE_AUTONOMOUS(1), ROBOT_MODE_MEASURE(2) ~%uint8                        robot_mode~%# STATE_INITIALIZING(0), STATE_STANDBY(1), STATE_MOVING(2), STATE_SAFE_OFF(3), STATE_TEACHING(4), STATE_SAFE_STOP(5), STATE_EMERGENCY_STOP, STATE_HOMMING, STATE_RECOVERY, STATE_SAFE_STOP2, STATE_SAFE_OFF2, ~%uint8                        robot_state~%# position control mode, torque mode ~%uint16                       control_mode~%# Reserved ~%uint8[256]                   reserved~%================================================================================~%MSG: std_msgs/Float64MultiArray~%# Please look at the MultiArrayLayout message definition for~%# documentation on all multiarrays.~%~%MultiArrayLayout  layout        # specification of data layout~%float64[]         data          # array of data~%~%~%================================================================================~%MSG: std_msgs/MultiArrayLayout~%# The multiarray declares a generic multi-dimensional array of a~%# particular data type.  Dimensions are ordered from outer most~%# to inner most.~%~%MultiArrayDimension[] dim # Array of dimension properties~%uint32 data_offset        # padding elements at front of data~%~%# Accessors should ALWAYS be written in terms of dimension stride~%# and specified outer-most dimension first.~%# ~%# multiarray(i,j,k) = data[data_offset + dim_stride[1]*i + dim_stride[2]*j + k]~%#~%# A standard, 3-channel 640x480 image with interleaved color channels~%# would be specified as:~%#~%# dim[0].label  = \"height\"~%# dim[0].size   = 480~%# dim[0].stride = 3*640*480 = 921600  (note dim[0] stride is just size of image)~%# dim[1].label  = \"width\"~%# dim[1].size   = 640~%# dim[1].stride = 3*640 = 1920~%# dim[2].label  = \"channel\"~%# dim[2].size   = 3~%# dim[2].stride = 3~%#~%# multiarray(i,j,k) refers to the ith row, jth column, and kth channel.~%~%================================================================================~%MSG: std_msgs/MultiArrayDimension~%string label   # label of given dimension~%uint32 size    # size of given dimension (in type units)~%uint32 stride  # stride of given dimension~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RobotStateRT>))
  (cl:+ 0
     8
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'actual_joint_position) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'actual_joint_position_abs) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'actual_joint_velocity) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'actual_joint_velocity_abs) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'actual_tcp_position) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'actual_tcp_velocity) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'actual_flange_position) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'actual_flange_velocity) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'actual_motor_torque) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'actual_joint_torque) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'raw_joint_torque) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'raw_force_torque) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'external_joint_torque) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'external_tcp_force) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'target_joint_position) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'target_joint_velocity) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'target_joint_acceleration) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'target_motor_torque) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'target_tcp_position) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'target_tcp_velocity) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'jacobian_matrix) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'gravity_torque) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'coriolis_matrix) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'mass_matrix) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     2
     8
     8
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'joint_temperature) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     2
     2
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'controller_analog_input_type) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'controller_analog_input) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'controller_analog_output_type) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'controller_analog_output) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     1
     1
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'flange_analog_input) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'external_encoder_strobe_count) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'external_encoder_count) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 2)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'goal_joint_position) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'goal_tcp_position) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     1
     1
     2
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'reserved) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RobotStateRT>))
  "Converts a ROS message object to a list"
  (cl:list 'RobotStateRT
    (cl:cons ':time_stamp (time_stamp msg))
    (cl:cons ':actual_joint_position (actual_joint_position msg))
    (cl:cons ':actual_joint_position_abs (actual_joint_position_abs msg))
    (cl:cons ':actual_joint_velocity (actual_joint_velocity msg))
    (cl:cons ':actual_joint_velocity_abs (actual_joint_velocity_abs msg))
    (cl:cons ':actual_tcp_position (actual_tcp_position msg))
    (cl:cons ':actual_tcp_velocity (actual_tcp_velocity msg))
    (cl:cons ':actual_flange_position (actual_flange_position msg))
    (cl:cons ':actual_flange_velocity (actual_flange_velocity msg))
    (cl:cons ':actual_motor_torque (actual_motor_torque msg))
    (cl:cons ':actual_joint_torque (actual_joint_torque msg))
    (cl:cons ':raw_joint_torque (raw_joint_torque msg))
    (cl:cons ':raw_force_torque (raw_force_torque msg))
    (cl:cons ':external_joint_torque (external_joint_torque msg))
    (cl:cons ':external_tcp_force (external_tcp_force msg))
    (cl:cons ':target_joint_position (target_joint_position msg))
    (cl:cons ':target_joint_velocity (target_joint_velocity msg))
    (cl:cons ':target_joint_acceleration (target_joint_acceleration msg))
    (cl:cons ':target_motor_torque (target_motor_torque msg))
    (cl:cons ':target_tcp_position (target_tcp_position msg))
    (cl:cons ':target_tcp_velocity (target_tcp_velocity msg))
    (cl:cons ':jacobian_matrix (jacobian_matrix msg))
    (cl:cons ':gravity_torque (gravity_torque msg))
    (cl:cons ':coriolis_matrix (coriolis_matrix msg))
    (cl:cons ':mass_matrix (mass_matrix msg))
    (cl:cons ':solution_space (solution_space msg))
    (cl:cons ':singularity (singularity msg))
    (cl:cons ':operation_speed_rate (operation_speed_rate msg))
    (cl:cons ':joint_temperature (joint_temperature msg))
    (cl:cons ':controller_digital_input (controller_digital_input msg))
    (cl:cons ':controller_digital_output (controller_digital_output msg))
    (cl:cons ':controller_analog_input_type (controller_analog_input_type msg))
    (cl:cons ':controller_analog_input (controller_analog_input msg))
    (cl:cons ':controller_analog_output_type (controller_analog_output_type msg))
    (cl:cons ':controller_analog_output (controller_analog_output msg))
    (cl:cons ':flange_digital_input (flange_digital_input msg))
    (cl:cons ':flange_digital_output (flange_digital_output msg))
    (cl:cons ':flange_analog_input (flange_analog_input msg))
    (cl:cons ':external_encoder_strobe_count (external_encoder_strobe_count msg))
    (cl:cons ':external_encoder_count (external_encoder_count msg))
    (cl:cons ':goal_joint_position (goal_joint_position msg))
    (cl:cons ':goal_tcp_position (goal_tcp_position msg))
    (cl:cons ':robot_mode (robot_mode msg))
    (cl:cons ':robot_state (robot_state msg))
    (cl:cons ':control_mode (control_mode msg))
    (cl:cons ':reserved (reserved msg))
))
