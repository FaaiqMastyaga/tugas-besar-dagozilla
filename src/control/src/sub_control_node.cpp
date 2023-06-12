#include <ros/ros.h>
#include "msgs/HardwareCommand.h"

void showPWM(const msgs::HardwareCommand::ConstPtr& pwm) {
    ROS_INFO("PWM:");
    ROS_INFO("motor 1: %f", pwm->motor1);
    ROS_INFO("motor 2: %f", pwm->motor2);
    ROS_INFO("motor 3: %f", pwm->motor3);
    ROS_INFO("motor 4: %f", pwm->motor4);
    ROS_INFO("\n");
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "sub_control_node");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("/control/command/hardware", 1, showPWM);
    ros::spin();
    return 0;
}
