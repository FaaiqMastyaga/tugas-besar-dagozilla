#include "teleop.hpp"
#include "setPWM.hpp"
#include "signalHandler.hpp"

int main(int argc, char** argv)
{
    signal(SIGINT, signalHandler);
    ros::init(argc,argv,"tbk", ros::init_options::AnonymousName | ros::init_options::NoSigintHandler);
    ros::NodeHandle nh;
    pub = nh.advertise<msgs::HardwareCommand>("/control/command/hardware", 1);
    TeleopKeyboard tbk;
    signal(SIGINT, signalHandler); //signal interrupt
    boost::thread t = boost::thread(boost::bind(&TeleopKeyboard::keyboardLoop, &tbk));
    ros::spin();
    t.interrupt();
    t.join();
    tbk.stopRobot();
    tcsetattr(kfd, TCSANOW, &cooked);
    return(0);
}

void signalHandler(int signal) {
    TeleopKeyboard::stopRobot();
    ROS_INFO("Motor1 : %f", PWM.motor1);
    ROS_INFO("Motor2 : %f", PWM.motor2);
    ROS_INFO("Motor3 : %f", PWM.motor3);
    ROS_INFO("Motor4 : %f", PWM.motor4);

    pub.publish(PWM);

    std::cout << "\nPress Enter\n" << std::endl;
    exit(signal);
}

void TeleopKeyboard::keyboardLoop() {
    char c;
    bool dirty = false;

    // get the consol in raw mode
    tcgetattr(kfd, &cooked);
    memcpy(&raw, &cooked, sizeof(struct termios));
    raw.c_lflag &=~ (ICANON | ECHO);
    raw.c_cc[VEOL] = 1;
    raw.c_cc[VEOF] = 2;
    tcsetattr(kfd, TCSANOW, &raw);

    puts("Reading from keyboard");
    puts("Use WASD keys to control the robot");
    
    struct pollfd ufd;
    ufd.fd = kfd;
    ufd.events = POLLIN;
    for(;;) {
        boost::this_thread::interruption_point();
        // get the next event from the keyboard
        int num;

        if ((num = poll(&ufd, 1, 250)) < 0) {
            perror("read():");
            return;
        }
        else if (num > 0) {
            if (read(kfd, &c, 1) < 0) {
                perror("read():");
                return;
            }
        }
        else {
            if (dirty == true) {
                stopRobot();
                dirty = false;
            }
            pub.publish(PWM);
            continue;
        }
        
        if (!nh.getParam("PWMvalue", PWMvalue)) { //added rosparam for PWMvalue variable
            PWMvalue = 0.5;
        }
        
        switch (c) {
            case KEYCODE_W:
                SetPWM::moveForward();
                dirty = true;
                break;
            case KEYCODE_S:
                SetPWM::moveBackward();
                dirty = true;
                break;
            case KEYCODE_A:
                SetPWM::slideLeft();
                dirty = true;
                break;
            case KEYCODE_D:
                SetPWM::slideRight();
                dirty = true;
                break;
            case KEYCODE_R:
                SetPWM::Rotate();
                dirty = true;
                break;
            
            default:
                dirty = false;
                break;
        }
        pub.publish(PWM);
    }
}

void TeleopKeyboard::stopRobot() {
    PWM.motor1 = 0;
    PWM.motor2 = 0;
    PWM.motor3 = 0;
    PWM.motor4 = 0;

    ROS_INFO("\n");
    ROS_INFO("Robot stopped");
    pub.publish(PWM);
}

void SetPWM::moveForward() {
    PWM.motor1 = -PWMvalue;
    PWM.motor2 = PWMvalue;
    PWM.motor3 = -PWMvalue;
    PWM.motor4 = PWMvalue;

    ROS_INFO("\n");
    ROS_INFO("Move Forward");
}

void SetPWM::slideLeft() {
    PWM.motor1 = -PWMvalue;
    PWM.motor2 = -PWMvalue;
    PWM.motor3 = PWMvalue;
    PWM.motor4 = PWMvalue;

    ROS_INFO("\n");
    ROS_INFO("Slide Left");
}

void SetPWM::moveBackward() {
    PWM.motor1 = PWMvalue;
    PWM.motor2 = -PWMvalue;
    PWM.motor3 = PWMvalue;
    PWM.motor4 = -PWMvalue;

    ROS_INFO("\n");
    ROS_INFO("Move Backward");
}

void SetPWM::slideRight() {
    PWM.motor1 = PWMvalue;
    PWM.motor2 = PWMvalue;
    PWM.motor3 = -PWMvalue;
    PWM.motor4 = -PWMvalue;

    ROS_INFO("\n");
    ROS_INFO("Slide Right");
}

void SetPWM::Rotate() {
    PWM.motor1 = -PWMvalue;
    PWM.motor2 = -PWMvalue;
    PWM.motor3 = -PWMvalue;
    PWM.motor4 = -PWMvalue;

    ROS_INFO("\n");
    ROS_INFO("Rotate");
}