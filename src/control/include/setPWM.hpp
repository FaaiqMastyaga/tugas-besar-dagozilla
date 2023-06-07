#ifndef SETPWM_HPP
#define SETPWM_HPP

double pwm = 1.0; // set value of pwm here

class SetPWM {
    public:
        static void moveForward();
        static void slideLeft();
        static void moveBackward();
        static void slideRight();
        static void Rotate();
};


#endif