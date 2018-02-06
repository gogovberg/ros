 #include <iostream>
#include <fstream>
#include <boost/shared_ptr.hpp>


// ROS
#include <ros/ros.h>
#include <create_node/TurtlebotSensorState.h>
#include <geometry_msgs/Twist.h>

using namespace std;

ros::Publisher pub;
geometry_msgs::Twist base_cmd;
bool isChange = false;
double cliffThreshold = 1800; 
double drive = 0;
double turn = 1;
string time_path;
ofstream myfile;
void callbackCliff(const create_node::TurtlebotSensorState& cliff_msg)
{ 
  myfile.open (time_path.c_str(), ios::out | ios::binary | ios::app);
  const clock_t begin_time = clock();
  try
    {
  	  base_cmd.linear.y = 0;
      base_cmd.linear.z = 0;
      base_cmd.angular.x = 0;
      base_cmd.angular.y = 0;
      
      //this is what we use for moving
      base_cmd.angular.z = 0;
      base_cmd.linear.x = 0;
      
      ROS_INFO("Cliff left signal: %d",cliff_msg.cliff_left_signal);
      ROS_INFO("Cliff front left signal: %d",cliff_msg.cliff_front_left_signal);
 	    ROS_INFO("Cliff front right signal: %d",cliff_msg.cliff_front_right_signal);
      ROS_INFO("Cliff right signal: %d",cliff_msg.cliff_right_signal);
      
     
      if(cliff_msg.cliff_left_signal < cliffThreshold)
      {
      	 turn = 1;
      	 drive = 0;
      	 isChange = true;
      }
      else if(cliff_msg.cliff_front_left_signal< cliffThreshold)
      {
      	 turn = 0.2;
      	 drive = 0.2;
      	 isChange = true;
      }
      else if(cliff_msg.cliff_front_right_signal< cliffThreshold)
      {
     	 
      	 turn = -0.2;
      	 drive = 0.2;
      	 isChange = true;
     	       	
      }
      else if(cliff_msg.cliff_right_signal < cliffThreshold)
      {
     	 
      	 turn = -1;
      	 drive = 0;
     	 isChange = true;
      }
      else
      {
      	if(!isChange)
		{
			drive= 0.2;
			turn = 0.5;
		}
		else
		{
			drive = 0.2;
		}
	  }
      
      base_cmd.angular.z = turn;
      base_cmd.linear.x = drive;
      
      ROS_INFO("BASE CMD drive %f",base_cmd.linear.x);
      ROS_INFO("BASE CMD turn %f",base_cmd.angular.z);
  }
  catch ( ros::Exception &e )
  {
      ROS_ERROR("Error occured: %s ", e.what());
  }
  try
  {
  if(myfile.is_open())
    {
       ROS_INFO("Writing time to file.");
        //string result = std::to_string(;
        myfile << float( clock () - begin_time ) /  CLOCKS_PER_SEC << endl;
        myfile.close();
  }
  } catch (ros::Exception &e) {

        ROS_ERROR("Error occured: %s ", e.what());
    }

}

int main (int argc, char** argv) {

  // Initialize ROS
  ros::init (argc, argv, "task_one");
  ros::NodeHandle nh;
  
  ros::NodeHandle np("~");
  np.param<string>("time_path", time_path, string(""));
  // Create a ROS subscriber for the input point cloud
  ros::Subscriber sub = nh.subscribe ("/mobile_base/sensors/core", 1, callbackCliff);
  ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop", 1);
  ROS_INFO_STREAM("File path for writing time elapsed " << time_path);
  // Spin
  while(ros::ok){
    pub.publish(base_cmd);
    ros::spinOnce();
  }
 //ros::spin();
 return 0;
}

