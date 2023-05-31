#ifndef SETDIRECTION_HPP
#define SETDIRECTION_HPP

#include "std_msgs/String.h"
#include "setPWM.hpp"
#include <iostream>
#include <string>

void setDirection(const std_msgs::String::ConstPtr& msg);

#endif