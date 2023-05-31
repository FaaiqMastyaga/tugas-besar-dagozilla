#include "ros/ros.h"

#include "std_msgs/String.h"
#include "msgs/HardwareCommand.h"

#include "setDirection.hpp"
#include "setPWM.hpp"

#include <iostream>
#include <string>

msgs::HardwareCommand PWM;  

int main(int argc, char **argv)
{
    ros::init(argc, argv, "control_node");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("/control/command/pc", 1, setDirection);
    ros::Publisher pub = nh.advertise<msgs::HardwareCommand>("/control/command/hardware", 1);

    ros::Rate loop_rate(20);

    while(ros::ok) {
        pub.publish(PWM);
        
        ros::spinOnce();
        loop_rate.sleep();
    }

    ros::spin();
    return 0;
}

void setDirection(const std_msgs::String::ConstPtr& msg) {
    std::string commandInput = msg->data.c_str();

    if (commandInput == "w") {
        moveForward();
    } 
    else if (commandInput == "a") {
        slideLeft();
    }
    else if (commandInput == "s") {
        moveBackward();
    }
    else if (commandInput == "d") {
        slideRight();
    }
    else if (commandInput == "r") {
        Rotate();
    }
    else {
        std::cout << "input error" << std::endl;
    }
}

void moveForward() {
    PWM.motor1 = -1;
    PWM.motor2 = 1;
    PWM.motor3 = -1;
    PWM.motor4 = 1;
    ROS_INFO("Move Forward");
}

void slideLeft() {
    PWM.motor1 = 1;
    PWM.motor2 = 1;
    PWM.motor3 = -1;
    PWM.motor4 = -1;
    ROS_INFO("Slide Left");
}

void moveBackward() {
    PWM.motor1 = 1;
    PWM.motor2 = -1;
    PWM.motor3 = 1;
    PWM.motor4 = -1;
    ROS_INFO("Move Backward");
}

void slideRight() {
    PWM.motor1 = -1;
    PWM.motor2 = -1;
    PWM.motor3 = 1;
    PWM.motor4 = 1;
    ROS_INFO("Slide Right");
}

void Rotate() {
    PWM.motor1 = -1;
    PWM.motor2 = -1;
    PWM.motor3 = -1;
    PWM.motor4 = -1;
    ROS_INFO("Rotate");
}