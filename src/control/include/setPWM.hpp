#ifndef SETPWM_HPP
#define SETPWM_HPP

#include "msgs/HardwareCommand.h"

msgs::HardwareCommand PWM;  
double PWMvalue;

void moveForward();
void slideLeft();
void moveBackward();
void slideRight();
void rotate();
void stopRobot();

#endif