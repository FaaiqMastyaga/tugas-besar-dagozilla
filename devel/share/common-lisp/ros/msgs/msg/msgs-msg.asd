
(cl:in-package :asdf)

(defsystem "msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "HardwareCommand" :depends-on ("_package_HardwareCommand"))
    (:file "_package_HardwareCommand" :depends-on ("_package"))
  ))