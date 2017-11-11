; Auto-generated. Do not edit!


(cl:in-package recognition_msgs-msg)


;//! \htmlinclude Recognition.msg.html

(cl:defclass <Recognition> (roslisp-msg-protocol:ros-message)
  ((x
    :reader x
    :initarg :x
    :type cl:float
    :initform 0.0)
   (y
    :reader y
    :initarg :y
    :type cl:float
    :initform 0.0)
   (label
    :reader label
    :initarg :label
    :type cl:string
    :initform ""))
)

(cl:defclass Recognition (<Recognition>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Recognition>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Recognition)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name recognition_msgs-msg:<Recognition> is deprecated: use recognition_msgs-msg:Recognition instead.")))

(cl:ensure-generic-function 'x-val :lambda-list '(m))
(cl:defmethod x-val ((m <Recognition>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader recognition_msgs-msg:x-val is deprecated.  Use recognition_msgs-msg:x instead.")
  (x m))

(cl:ensure-generic-function 'y-val :lambda-list '(m))
(cl:defmethod y-val ((m <Recognition>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader recognition_msgs-msg:y-val is deprecated.  Use recognition_msgs-msg:y instead.")
  (y m))

(cl:ensure-generic-function 'label-val :lambda-list '(m))
(cl:defmethod label-val ((m <Recognition>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader recognition_msgs-msg:label-val is deprecated.  Use recognition_msgs-msg:label instead.")
  (label m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Recognition>) ostream)
  "Serializes a message object of type '<Recognition>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'label))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'label))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Recognition>) istream)
  "Deserializes a message object of type '<Recognition>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'y) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'label) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'label) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Recognition>)))
  "Returns string type for a message object of type '<Recognition>"
  "recognition_msgs/Recognition")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Recognition)))
  "Returns string type for a message object of type 'Recognition"
  "recognition_msgs/Recognition")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Recognition>)))
  "Returns md5sum for a message object of type '<Recognition>"
  "758d8c9fcfdf72f4de3bde06357b9c26")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Recognition)))
  "Returns md5sum for a message object of type 'Recognition"
  "758d8c9fcfdf72f4de3bde06357b9c26")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Recognition>)))
  "Returns full string definition for message of type '<Recognition>"
  (cl:format cl:nil "float32 x~%float32 y~%string label~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Recognition)))
  "Returns full string definition for message of type 'Recognition"
  (cl:format cl:nil "float32 x~%float32 y~%string label~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Recognition>))
  (cl:+ 0
     4
     4
     4 (cl:length (cl:slot-value msg 'label))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Recognition>))
  "Converts a ROS message object to a list"
  (cl:list 'Recognition
    (cl:cons ':x (x msg))
    (cl:cons ':y (y msg))
    (cl:cons ':label (label msg))
))
