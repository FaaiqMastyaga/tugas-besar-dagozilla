#include "setPWM.hpp"

void moveForward() {
    PWM.motor1 = 0;
    PWM.motor2 = 0;
    PWM.motor3 = 0;
    PWM.motor4 = 0;
    ROS_INFO("Move Forward");
}

void slideLeft() {
    PWM.motor1 = 0;
    PWM.motor2 = 0;
    PWM.motor3 = 0;
    PWM.motor4 = 0;
    ROS_INFO("Slide Left");
}

void moveBackward() {
    PWM.motor1 = 0;
    PWM.motor2 = 0;
    PWM.motor3 = 0;
    PWM.motor4 = 0;
    ROS_INFO("Move Backward");
}

void slideRight() {
    PWM.motor1 = 0;
    PWM.motor2 = 0;
    PWM.motor3 = 0;
    PWM.motor4 = 0;
    ROS_INFO("Slide Right");
}

void Rotate() {
    PWM.motor1 = 0;
    PWM.motor2 = 0;
    PWM.motor3 = 0;
    PWM.motor4 = 0;
    ROS_INFO("Rotate");
}