# Tugas Besar Dagozilla (Mari Hidupkan Jacobi)

## Author
- Albert
- Faaiq
- Nafi
- Dika

&nbsp;

## Table of Contents
1. Overview
2. Detail Program
3. How to Run Program

&nbsp;

## Overview
Jacobi is one of a robots in dagozilla team that has been exist. But, this robot has small size compare to other robots (Kirchoff, Laplace, and Maxwell). Therefore, we as 15th crew candidate of Dagozilla team is assigned to modify Jacobi so that it has bigger size.

The robot that we develop now has 4WD omni-directional as driver which can move to any direction. The robot will be moved by keyboard input. The command w, a, s, d, and r will drive the robot move forward, slide left, move backward, slide right, and rotate in position. 

The robot has a PC which used as the main functionality of ROS (Robot Operating System). The ROS program will accept command from keyboard input and processing the data into motion commands that will be published to STM32 Nucleo microcontroller. This motion commands will be executed by hardware motor of the robot.

&nbsp;

## Detail Program
### a. Main Specification
1. ROS program:
- Keyboard input reading
- Decision making of moving command
- Movement command in form of PWM that will be published to STM32 Nucleo
2. Decision making of movement command which each command will lasts in 1 second
- Move forward (w)
- Slide left (a)
- Move backward (s)
- Slide right (d)
- Rotate (r)
3. ROS package: control, launch, and msgs.
- Package control containing publisher for rostopic /control/command/hardware.
- Package launch as a shortcut to run nodes in package control. The launch file containing arg 'param_compute_period' with default value 50 and will be assigned to param 'compute_period' to set the compute_period of nodes in control package.
- Package msgs containing wrapped message (data) in HardwareCommand.msg file that will be published. The data/messages wrapped in the file are: float32 motor1, float32 motor2, float32 motor3, and float32 motor4.
4. ROS topic: '/control/command/hardware'
- Receive data from publisher node in form of PWM with value between -1.0 and 1.0
- Subscribed by STM32 Nucleo.

&nbsp;

### b. Bonus Specification
Same with program in main specification. But, there is a difference in point number 2. The decision making from keyboard input will run in real-time. This utilize the concept of interrupt and multithreading.

&nbsp;

## How to Run Program
1. Open terminal
2. Change directory to this workspace
3. Sourcing this workspace using command below
```
source devel/setup.zsh 
```
or
```
source devel/setup.bash
```
4. Launch node file in this workspace using command below
```
roslaunch launch control.launch
```
5. To set the value of PWM that will be published to microcontroller, use the command below (change the value inside bracket with float number between 0 and 1)
```
rosparam set /PWMvalue {value}
```

&nbsp;

## References
- [ROS Custom Launch Files Args , Params , Remap](https://www.youtube.com/watch?v=0-zTU4_S6vY&list=PLBbhfIdh4NdgBBkX7q0Y3UukO2_ZoICee&index=5)
- [mode input bonus](https://github.com/arebgun/erratic_robot/blob/master/erratic_teleop/src/keyboard.cpp)
- [rosserial MBED Setup](http://wiki.ros.org/rosserial_mbed/Tutorials/rosserial_mbed%20Setup)
- [How to Enable SSH on Ubuntu 20.04](https://linuxize.com/post/how-to-enable-ssh-on-ubuntu-20-04/)