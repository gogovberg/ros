#include <iostream>
#include <fstream>
#include <boost/shared_ptr.hpp>


// ROS
#include <ros/ros.h>
#include <create_node/TurtlebotSensorState.h>
#include <geometry_msgs/Twist.h>

using namespace std;

ros::Publisher pub;

void callbackCliff(const create_node::TurtlebotSensorState& cliff_msg)
{ 
  
  try
    {
  
      ROS_INFO("Cliff front left signal: %d",cliff_msg.cliff_front_left_signal);
      ROS_INFO("Cliff front right signal: %d",cliff_msg.cliff_front_right_signal);
      geometry_msgs::Twist base_cmd;
      base_cmd.linear.y = 0;
      base_cmd.linear.z = 0;
      base_cmd.angular.x = 0;
      base_cmd.angular.y = 0;
      base_cmd.angular.z = 5;
      base_cmd.linear.x = 10;
      ROS_INFO("BASE CMD %f",base_cmd.linear.x);
      pub.publish(base_cmd);

  }
  catch ( ros::Exception &e )
  {
      ROS_ERROR("Error occured: %s ", e.what());
  }

}

int main (int argc, char** argv) {

  // Initialize ROS
  ros::init (argc, argv, "task_one");
  ros::NodeHandle nh;
  // Create a ROS subscriber for the input point cloud
  ros::Subscriber sub = nh.subscribe ("/mobile_base/sensors/core", 1, callbackCliff);
  ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop", 1);
  // Spin
  ros::spin ();
}

