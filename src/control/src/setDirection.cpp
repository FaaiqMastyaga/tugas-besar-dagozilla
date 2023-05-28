#include "setDirection.hpp"

void setDirection(const std_msgs::Char::ConstPtr& msg) {
    char commandInput = msg->data.c_str();

    switch(commandInput) {
        case 'w':
            moveForward();
            break;
        case 'a':
            moveLeft();
            break;
        case 's':
            moveBackward();
            break;
        case 'd':
            moveRight();
            break;
        case 'r':
            Rotate();
            break;
    }
}