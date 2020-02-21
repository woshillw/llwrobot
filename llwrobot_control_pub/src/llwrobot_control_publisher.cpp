#include "ros/ros.h"
#include "std_msgs/Float64.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "llwrobot_control_publisher");

    ros::NodeHandle n;

    ros::Publisher pub = n.advertise<std_msgs::Float64>("/llwrobot/joint1_position_controller/command", 1000);

    ros::Rate loop_rate(10);

    double pos = 0;
    int flag = 1;

    while (ros::ok())
    {
        std_msgs::Float64 msg;

        if (flag == 1)
        {
            pos += 0.1;
        }
        else if (flag == -1)
        {
            pos -= 0.1;
        }
        if (pos > 1.5)
            flag = -1;
        else if (pos < -1.5)
            flag = 1;

        msg.data = pos;

        ROS_INFO("%f", msg.data);

        pub.publish(msg);

        ros::spinOnce();

        loop_rate.sleep();
    }
    return 0;
}
