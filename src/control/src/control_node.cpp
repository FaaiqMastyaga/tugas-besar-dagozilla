#include "ros/ros.h"
#include "std_msgs/Char.h"
#include "msgs/msg/HardwareCommand.msg"
#include "setDirection.hpp"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "control_node");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("/control/command/PC", Char, setDirection);
    ros::Publisher pub = nh.advertise<msg::HardwareCommand>("/control/command/hardware", 1);

    ros::Rate loop_rate(20);

    whil(ros::ok) {
        pub.publish(PWM);
        
        ros::spinOnce();
        loop_rate.sleep();
    }

    ros::spin();
    return 0;
}
