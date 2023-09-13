;; Auto-generated. Do not edit!


(when (boundp 'dsr_msgs::GetRTControlInputDataList)
  (if (not (find-package "DSR_MSGS"))
    (make-package "DSR_MSGS"))
  (shadow 'GetRTControlInputDataList (find-package "DSR_MSGS")))
(unless (find-package "DSR_MSGS::GETRTCONTROLINPUTDATALIST")
  (make-package "DSR_MSGS::GETRTCONTROLINPUTDATALIST"))
(unless (find-package "DSR_MSGS::GETRTCONTROLINPUTDATALISTREQUEST")
  (make-package "DSR_MSGS::GETRTCONTROLINPUTDATALISTREQUEST"))
(unless (find-package "DSR_MSGS::GETRTCONTROLINPUTDATALISTRESPONSE")
  (make-package "DSR_MSGS::GETRTCONTROLINPUTDATALISTRESPONSE"))

(in-package "ROS")





(defclass dsr_msgs::GetRTControlInputDataListRequest
  :super ros::object
  :slots (_version ))

(defmethod dsr_msgs::GetRTControlInputDataListRequest
  (:init
   (&key
    ((:version __version) "")
    )
   (send-super :init)
   (setq _version (string __version))
   self)
  (:version
   (&optional __version)
   (if __version (setq _version __version)) _version)
  (:serialization-length
   ()
   (+
    ;; string _version
    4 (length _version)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _version
       (write-long (length _version) s) (princ _version s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _version
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _version (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass dsr_msgs::GetRTControlInputDataListResponse
  :super ros::object
  :slots (_success _data ))

(defmethod dsr_msgs::GetRTControlInputDataListResponse
  (:init
   (&key
    ((:success __success) nil)
    ((:data __data) "")
    )
   (send-super :init)
   (setq _success __success)
   (setq _data (string __data))
   self)
  (:success
   (&optional __success)
   (if __success (setq _success __success)) _success)
  (:data
   (&optional __data)
   (if __data (setq _data __data)) _data)
  (:serialization-length
   ()
   (+
    ;; bool _success
    1
    ;; string _data
    4 (length _data)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _success
       (if _success (write-byte -1 s) (write-byte 0 s))
     ;; string _data
       (write-long (length _data) s) (princ _data s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _success
     (setq _success (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; string _data
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _data (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass dsr_msgs::GetRTControlInputDataList
  :super ros::object
  :slots ())

(setf (get dsr_msgs::GetRTControlInputDataList :md5sum-) "af5686a9e1b1a378bc0983d164821af1")
(setf (get dsr_msgs::GetRTControlInputDataList :datatype-) "dsr_msgs/GetRTControlInputDataList")
(setf (get dsr_msgs::GetRTControlInputDataList :request) dsr_msgs::GetRTControlInputDataListRequest)
(setf (get dsr_msgs::GetRTControlInputDataList :response) dsr_msgs::GetRTControlInputDataListResponse)

(defmethod dsr_msgs::GetRTControlInputDataListRequest
  (:response () (instance dsr_msgs::GetRTControlInputDataListResponse :init)))

(setf (get dsr_msgs::GetRTControlInputDataListRequest :md5sum-) "af5686a9e1b1a378bc0983d164821af1")
(setf (get dsr_msgs::GetRTControlInputDataListRequest :datatype-) "dsr_msgs/GetRTControlInputDataListRequest")
(setf (get dsr_msgs::GetRTControlInputDataListRequest :definition-)
      "#____________________________________________________________________________________________
# get_rt_control_input_data_list
#____________________________________________________________________________________________
string     version
---
bool       success
string     data
")

(setf (get dsr_msgs::GetRTControlInputDataListResponse :md5sum-) "af5686a9e1b1a378bc0983d164821af1")
(setf (get dsr_msgs::GetRTControlInputDataListResponse :datatype-) "dsr_msgs/GetRTControlInputDataListResponse")
(setf (get dsr_msgs::GetRTControlInputDataListResponse :definition-)
      "#____________________________________________________________________________________________
# get_rt_control_input_data_list
#____________________________________________________________________________________________
string     version
---
bool       success
string     data
")



(provide :dsr_msgs/GetRTControlInputDataList "af5686a9e1b1a378bc0983d164821af1")

