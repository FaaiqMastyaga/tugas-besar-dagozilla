#include "ros/ros.h"
#include "msgs/HardwareCommand.h"

void showPWM(const msgs::HardwareCommand::ConstPtr& pwm)
{
    ROS_INFO("Received message:");
    ROS_INFO("Motor1 : %f", pwm->motor1);
    ROS_INFO("Motor2 : %f", pwm->motor2);
    ROS_INFO("Motor3 : %f", pwm->motor3);
    ROS_INFO("Motor4 : %f", pwm->motor4);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "subs");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("/control/command/hardware", 1, showPWM);

    ros::spin();
    ros::shutdown();
    return 0;
}
