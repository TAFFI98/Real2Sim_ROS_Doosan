;; Auto-generated. Do not edit!


(when (boundp 'dsr_msgs::SetToolDigitalOutput)
  (if (not (find-package "DSR_MSGS"))
    (make-package "DSR_MSGS"))
  (shadow 'SetToolDigitalOutput (find-package "DSR_MSGS")))
(unless (find-package "DSR_MSGS::SETTOOLDIGITALOUTPUT")
  (make-package "DSR_MSGS::SETTOOLDIGITALOUTPUT"))
(unless (find-package "DSR_MSGS::SETTOOLDIGITALOUTPUTREQUEST")
  (make-package "DSR_MSGS::SETTOOLDIGITALOUTPUTREQUEST"))
(unless (find-package "DSR_MSGS::SETTOOLDIGITALOUTPUTRESPONSE")
  (make-package "DSR_MSGS::SETTOOLDIGITALOUTPUTRESPONSE"))

(in-package "ROS")





(defclass dsr_msgs::SetToolDigitalOutputRequest
  :super ros::object
  :slots (_index _value ))

(defmethod dsr_msgs::SetToolDigitalOutputRequest
  (:init
   (&key
    ((:index __index) 0)
    ((:value __value) 0)
    )
   (send-super :init)
   (setq _index (round __index))
   (setq _value (round __value))
   self)
  (:index
   (&optional __index)
   (if __index (setq _index __index)) _index)
  (:value
   (&optional __value)
   (if __value (setq _value __value)) _value)
  (:serialization-length
   ()
   (+
    ;; int8 _index
    1
    ;; int8 _value
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int8 _index
       (write-byte _index s)
     ;; int8 _value
       (write-byte _value s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int8 _index
     (setq _index (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _index 127) (setq _index (- _index 256)))
   ;; int8 _value
     (setq _value (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _value 127) (setq _value (- _value 256)))
   ;;
   self)
  )

(defclass dsr_msgs::SetToolDigitalOutputResponse
  :super ros::object
  :slots (_success ))

(defmethod dsr_msgs::SetToolDigitalOutputResponse
  (:init
   (&key
    ((:success __success) nil)
    )
   (send-super :init)
   (setq _success __success)
   self)
  (:success
   (&optional __success)
   (if __success (setq _success __success)) _success)
  (:serialization-length
   ()
   (+
    ;; bool _success
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _success
       (if _success (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _success
     (setq _success (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass dsr_msgs::SetToolDigitalOutput
  :super ros::object
  :slots ())

(setf (get dsr_msgs::SetToolDigitalOutput :md5sum-) "fb5dce2e6988e39a422dd00d9d97c412")
(setf (get dsr_msgs::SetToolDigitalOutput :datatype-) "dsr_msgs/SetToolDigitalOutput")
(setf (get dsr_msgs::SetToolDigitalOutput :request) dsr_msgs::SetToolDigitalOutputRequest)
(setf (get dsr_msgs::SetToolDigitalOutput :response) dsr_msgs::SetToolDigitalOutputResponse)

(defmethod dsr_msgs::SetToolDigitalOutputRequest
  (:response () (instance dsr_msgs::SetToolDigitalOutputResponse :init)))

(setf (get dsr_msgs::SetToolDigitalOutputRequest :md5sum-) "fb5dce2e6988e39a422dd00d9d97c412")
(setf (get dsr_msgs::SetToolDigitalOutputRequest :datatype-) "dsr_msgs/SetToolDigitalOutputRequest")
(setf (get dsr_msgs::SetToolDigitalOutputRequest :definition-)
      "#____________________________________________________________________________________________
# set_tool_digital_output  
# This service sends ouptput to tool io.
#____________________________________________________________________________________________

int8       index   # flange digital output port(1 ~ 6)
int8       value   # 0 : ON, 1 : OFF
---
bool       success
")

(setf (get dsr_msgs::SetToolDigitalOutputResponse :md5sum-) "fb5dce2e6988e39a422dd00d9d97c412")
(setf (get dsr_msgs::SetToolDigitalOutputResponse :datatype-) "dsr_msgs/SetToolDigitalOutputResponse")
(setf (get dsr_msgs::SetToolDigitalOutputResponse :definition-)
      "#____________________________________________________________________________________________
# set_tool_digital_output  
# This service sends ouptput to tool io.
#____________________________________________________________________________________________

int8       index   # flange digital output port(1 ~ 6)
int8       value   # 0 : ON, 1 : OFF
---
bool       success
")



(provide :dsr_msgs/SetToolDigitalOutput "fb5dce2e6988e39a422dd00d9d97c412")


