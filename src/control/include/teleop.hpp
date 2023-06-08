#ifndef TELEOP_HPP
#define TELEOP_HPP

#include <termios.h>
#include <signal.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/poll.h>

#include <boost/thread/thread.hpp>
#include <ros/ros.h>

#include "msgs/HardwareCommand.h"
#include "setPWM.hpp"

#define KEYCODE_W 0x77
#define KEYCODE_A 0x61
#define KEYCODE_S 0x73
#define KEYCODE_D 0x64
#define KEYCODE_R 0x72

int kfd = 0;
struct termios cooked, raw;
bool done;
msgs::HardwareCommand PWM;

class TeleopKeyboard {
    private:
        ros::NodeHandle nh;
        ros::Publisher pub;

    public:
        TeleopKeyboard();
        // ~TeleopKeyboard(); // this method is not used
        void keyboardLoop();
        void stopRobot();
};

#endif