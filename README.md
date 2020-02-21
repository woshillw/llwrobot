# llwrobot
a simple ros robot

#before you use, make sure install [ros](http://wiki.ros.org/)

#then install [ros_control](https://wiki.ros.org/ros_control)  
`sudo apt-get install ros-melodic-ros-control ros-melodic-ros-controllers`

#first build project  
`mkdir ~/catkin_ws/src -p`  
`cd ~/catkin_ws/src`  
`catkin_init_workspace`  
`cd ~/catkin_ws`  
`catkin_make`  
`echo "~/catkin_ws/devel/setup.bash" >> ~/.bashrc`  
`source ~/.bashrc`  

#second use  
`roslaunch llwrobot_description llwrobot_gazebo.launch`

#then  
`rosrun llwrobot_control_pub 1.5 0.5`

#you can change the param what you like
