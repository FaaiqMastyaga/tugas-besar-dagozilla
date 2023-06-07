#include "ros/ros.h"
#include "msgs/HardwareCommand.h"

void callback(const msgs::HardwareCommand::ConstPtr& msg)
{
    ROS_INFO("Received message:");
    ROS_INFO("Motor1 : %f", msg->motor1);
    ROS_INFO("Motor2 : %f", msg->motor2);
    ROS_INFO("Motor3 : %f", msg->motor3);
    ROS_INFO("Motor4 : %f", msg->motor4);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "subs");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("/control/command/hardware", 1, callback);

    ros::spin();
    ros::shutdown();
    return 0;
}
