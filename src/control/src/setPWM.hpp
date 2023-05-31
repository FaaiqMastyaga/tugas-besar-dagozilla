#ifndef SETPWM_HPP
#define SETPWM_HPP

#include "msgs/HardwareCommand.h"

msgs::HardwareCommand PWM;

void moveForward();
void slideLeft();
void moveBackward();
void slideRight();
void Rotate();

#endif