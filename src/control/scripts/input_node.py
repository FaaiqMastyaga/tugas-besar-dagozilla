import rospy
from std_msgs.msg import Char

if __name__ == '__main__' :
    try:
        rospy.init_node("input_node")
        pub = rospy.Publisher("/control/command/pc", Char, queue_size=1)
        loop_rate = rospy.Rate(20)

        while not rospy.is_shutdown():
            commandInput = input("Command: ")
            pub.publish(commandInput)
            loop_rate.sleep()

    except rospy.ROSInterruptException:
        pass