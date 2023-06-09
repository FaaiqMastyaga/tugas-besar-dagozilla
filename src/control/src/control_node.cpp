#include "ros/ros.h"

#include "msgs/HardwareCommand.h"

#include "processKeyboardInput.hpp"
#include "setPWM.hpp"
#include "signalHandler.hpp"

#include <iostream>
#include <csignal>
#include <string>

msgs::HardwareCommand PWM;  
double PWMvalue;
int freq;

int main(int argc, char **argv)
{
    // initialize node
    ros::init(argc, argv, "control_node");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<msgs::HardwareCommand>("/control/command/hardware", 1);
    signal(SIGINT, signalHandler);

    // get PWMvalue parameter
    if (!nh.getParam("PWMvalue", PWMvalue)) {
        PWMvalue = 1.0;
    }
    // get freq parameter
    if (!nh.getParam("freq", freq)) {
        freq = 50;
    }
    ros::Rate loop_rate(freq);

    char commandInput;

    ros::Time beginTime;
    ros::Time endTime;
    ros::Duration duration = ros::Duration(1.0);

    while(ros::ok) {
        // input command every 1 second
        sleep(1.0);
        std::cout << "\nInput command (w,a,s,d,r): ";
        std::cin >> commandInput;
        processKeyboardInput(commandInput);

        // set time for 1 second
        beginTime = ros::Time::now();
        endTime = beginTime + duration;

        // publish PWM for 1 second
        while (ros::Time::now() <= endTime) {
            pub.publish(PWM);
            
            ros::spinOnce();
            loop_rate.sleep();
        }

        stopRobot();
        pub.publish(PWM);

        // get PWMvalue parameter
        if (!nh.getParam("PWMvalue", PWMvalue)) {
            PWMvalue = 1.0;
        }
        // get freq parameter
        if (!nh.getParam("freq", freq)) {
            freq = 50;
        }
        loop_rate = freq;
    }

    ros::spin();
    return 0;
}

void processKeyboardInput(char commandInput) {
    switch (commandInput) {
        case 'w':
            moveForward();
            break;
        case 'a':
            slideLeft();
            break;
        case 's':
            moveBackward();
            break;
        case 'd':
            slideRight();
            break;
        case 'r':
            rotate();
            break;
        case '0':
            stopRobot();
            break;
        default:
            std::cout << "Invalid input!" << std::endl;
    }
}

void moveForward() {
    PWM.motor1 = -PWMvalue;
    PWM.motor2 = PWMvalue;
    PWM.motor3 = -PWMvalue;
    PWM.motor4 = PWMvalue;
    ROS_INFO("Move Forward\n");
}

void slideLeft() {
    PWM.motor1 = PWMvalue;
    PWM.motor2 = PWMvalue;
    PWM.motor3 = -PWMvalue;
    PWM.motor4 = -PWMvalue;
    ROS_INFO("Slide Left\n");
}

void moveBackward() {
    PWM.motor1 = PWMvalue;
    PWM.motor2 = -PWMvalue;
    PWM.motor3 = PWMvalue;
    PWM.motor4 = -PWMvalue;
    ROS_INFO("Move Backward\n");
}

void slideRight() {
    PWM.motor1 = -PWMvalue;
    PWM.motor2 = -PWMvalue;
    PWM.motor3 = PWMvalue;
    PWM.motor4 = PWMvalue;
    ROS_INFO("Slide Right\n");
}

void rotate() {
    PWM.motor1 = -PWMvalue;
    PWM.motor2 = -PWMvalue;
    PWM.motor3 = -PWMvalue;
    PWM.motor4 = -PWMvalue;
    ROS_INFO("Rotate\n");
}

void stopRobot() {
    PWM.motor1 = 0;
    PWM.motor2 = 0;
    PWM.motor3 = 0;
    PWM.motor4 = 0;
    ROS_INFO("Robot stopped\n");
}

void signalHandler(int signal) {
    stopRobot();
    // add code to publish PWM here
    exit(0);
}