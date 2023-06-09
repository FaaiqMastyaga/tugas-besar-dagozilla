#!/usr/bin/env python3
import rospy
import signal
import sys
from std_msgs.msg import String

def sigint_handler(signal,frame):
    commandInput = String("stop")
    pub.publish(commandInput)
    rospy.loginfo("SIGINT success, preparing to exit...")
    sys.exit(0)

if __name__ == '__main__' :
    try:
        rospy.init_node("input_node")
        pub = rospy.Publisher("/control/command/pc", String, queue_size=1)
        loop_rate = rospy.Rate(20)
        signal.signal(signal.SIGINT, sigint_handler)

        while not rospy.is_shutdown():
            commandInput = String(input("Command: "))
            pub.publish(commandInput)
            loop_rate.sleep()

    except rospy.ROSInterruptException:
        pass