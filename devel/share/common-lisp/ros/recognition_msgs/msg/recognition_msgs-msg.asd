
(cl:in-package :asdf)

(defsystem "recognition_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Recognition" :depends-on ("_package_Recognition"))
    (:file "_package_Recognition" :depends-on ("_package"))
  ))