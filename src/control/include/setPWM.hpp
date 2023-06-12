#ifndef SETPWM_HPP
#define SETPWM_HPP

#include "control/HardwareCommand.h"

control::HardwareCommand PWM;
double PWMvalue;

class SetPWM {
    public:
        static void moveForward();
        static void slideLeft();
        static void moveBackward();
        static void slideRight();
        static void Rotate();
};


#endif