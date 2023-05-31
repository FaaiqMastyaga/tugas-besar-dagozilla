#include "setDirection.hpp"

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