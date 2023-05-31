#!/usr/bin/env python3
import rospy
from std_msgs.msg import String

if __name__ == '__main__' :
    try:
        rospy.init_node("input_node")
        pub = rospy.Publisher("/control/command/pc", String, queue_size=1)
        loop_rate = rospy.Rate(20)

        while not rospy.is_shutdown():
            commandInput = String(input("Command: "))
            pub.publish(commandInput)
            loop_rate.sleep()

    except rospy.ROSInterruptException:
        pass