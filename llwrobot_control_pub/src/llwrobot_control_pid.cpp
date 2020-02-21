#include "ros/ros.h"
#include "sensor_msgs/JointState.h"
#include "std_msgs/Float64.h"

double return_pos = 0;
double pid_ctrl(double in, double back, double Kp);

void subCallback(const sensor_msgs::JointState::ConstPtr &msg)
{
    return_pos = msg->position[0];
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "llwrobot_control_pid");

    if (argc != 3)
    {
        ROS_INFO("Please input 3 argv");
        return -1;
    }

    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("/llwrobot/joint_states", 1000, subCallback);
    ros::Publisher pub = n.advertise<std_msgs::Float64>("/llwrobot/joint1_position_controller/command", 1000);

    ros::Rate loop_rate(10);

    std_msgs::Float64 msg;

    // double pos = 0;
    // int flag = 1;

    while (ros::ok())
    {
        ros::spinOnce();

        // if (flag == 1)
        //     pos += 0.1;
        // else if (flag == -1)
        //     pos -= 0.1;

        // if (pos > 1.5)
        //     flag = -1;
        // else if (pos < -1.5)
        //     flag = 1;

        // msg.data = pos;

        msg.data = pid_ctrl(atof(argv[1]), return_pos, atof(argv[2]));

        ROS_INFO("sub=%.3lf\n pub=%.3lf\n out=%.3lf", return_pos, msg.data, pid_ctrl(atof(argv[1]), return_pos, atof(argv[2])));

        pub.publish(msg);

        loop_rate.sleep();
    }

    return 0;
}

double pid_ctrl(double in, double back, double Kp)
{
    double err = in - back;
    double out = Kp * err;
    return out;
}
