#include "ros/ros.h"
#include "sensor_msgs/JointState.h"

double return_pos = 0;
void subCallback(const sensor_msgs::JointState::ConstPtr &msg)
{
    return_pos = msg->position[0];
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "llwrobot_control_subscriber");

    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("/llwrobot/joint_states", 1000, subCallback);

    ros::Rate loop_rate(10);
    while (ros::ok())
    {
        ros::spinOnce();
        ROS_INFO("heard %lf", return_pos);
        loop_rate.sleep();
    }
    return 0;
}