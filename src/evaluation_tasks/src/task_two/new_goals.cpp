#include "ros/ros.h"
#include <nav_msgs/GetMap.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/PoseStamped.h>
#include <actionlib_msgs/GoalStatusArray.h>
#include <move_base_msgs/MoveBaseActionGoal.h>
#include <tf/transform_datatypes.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <queue>
#include <iostream>
#include <fstream>

using namespace std;
using namespace cv;

Mat cv_map;
float map_resolution = 0;
tf::Transform map_transform;
queue <geometry_msgs::PoseStamped> goalQeue;
ros::Publisher goal_pub;
ros::Subscriber map_sub;
ros::Subscriber baseStatus_sub;
bool isStart=true;
ofstream myfile;

clock_t begin_time;


void mapCallback(const nav_msgs::OccupancyGridConstPtr& msg_map) {
    int size_x = msg_map->info.width;
    int size_y = msg_map->info.height;

    if ((size_x < 3) || (size_y < 3) ) {
        ROS_INFO("Map size is only x: %d,  y: %d . Not running map to image conversion", size_x, size_y);
        return;
    }

    // resize cv image if it doesn't have the same dimensions as the map
    if ( (cv_map.rows != size_y) && (cv_map.cols != size_x)) {
        cv_map = cv::Mat(size_y, size_x, CV_8U);
    }

    map_resolution = msg_map->info.resolution;
	tf::poseMsgToTF(msg_map->info.origin, map_transform);

    const std::vector<int8_t>& map_msg_data (msg_map->data);

    unsigned char *cv_map_data = (unsigned char*) cv_map.data;

    //We have to flip around the y axis, y for image starts at the top and y for map at the bottom
    int size_y_rev = size_y-1;

    for (int y = size_y_rev; y >= 0; --y) {

        int idx_map_y = size_x * (size_y -y);
        int idx_img_y = size_x * y;

        for (int x = 0; x < size_x; ++x) {

            int idx = idx_img_y + x;

            switch (map_msg_data[idx_map_y + x])
            {
            case -1:
                cv_map_data[idx] = 127;
                break;

            case 0:
                cv_map_data[idx] = 255;
                break;

            case 100:
                cv_map_data[idx] = 0;
                break;
            }
        }
    }

}
void baseStatusCallback(const actionlib_msgs::GoalStatusArray::ConstPtr &msg)
{
	bool hasActiveGoal = false;
    for (int i=0; i<msg->status_list.size(); i++)
    {
    	//ROS_INFO("goal status: %d",msg->status_list[i].status);
        if (msg->status_list[i].status != msg->status_list[i].SUCCEEDED)
        {
            hasActiveGoal = true;
        }
    }
    if (!hasActiveGoal && !isStart)
    {
    	 if(myfile.is_open())
	     {
	        ROS_INFO("Writing time to file.");
	        //string result = std::to_string(;
	        myfile << float( clock () - begin_time ) /  CLOCKS_PER_SEC << endl;
	        myfile.close();
	     }
		if(!goalQeue.empty() )
		{
			geometry_msgs::PoseStamped goal;
			goal = goalQeue.front();
			goal.header.stamp = ros::Time::now();
		    ROS_INFO("Moving to goal pose (x: %f, y: %f)", goal.pose.position.x, goal.pose.position.y);
			goal_pub.publish(goal);
			goalQeue.pop();
			myfile.open ("/home/odroid/catkin_ws/src/evaluation_tasks/Time.txt", ios::out | ios::binary | ios::app);
			myfile << "NEW ITERATION"<< endl;
			begin_time = clock();
			
		}
		
    }

}

void mouseCallback(int event, int x, int y, int, void* data) {

    if( event != EVENT_LBUTTONDOWN || cv_map.empty())
        return;

    int v = (int)cv_map.at<unsigned char>(y, x);

	if (v != 255) {
		ROS_WARN("Unable to move to (x: %d, y: %d), not reachable", x, y);
		return;
	}

    ROS_INFO("Moving to (x: %d, y: %d)", x, y);

	tf::Point pt((float)x * map_resolution, (float)y * map_resolution, 0.0);
	tf::Point transformed = map_transform * pt;

	geometry_msgs::PoseStamped goal;
	goal.header.frame_id = "map";
	goal.pose.orientation.w = 1;
	goal.pose.position.x = 2.950000;
	goal.pose.position.y = 0.850000;
	//goal.pose.position.x = transformed.x();
	//goal.pose.position.y = -transformed.y();
	goal.header.stamp = ros::Time::now();
	isStart=false;	
	
	 ROS_INFO("Moving to goal pose (x: %f, y: %f)", goal.pose.position.x, goal.pose.position.y);

	goal_pub.publish(goal);
}
void initGoals()
{
	geometry_msgs::PoseStamped goal1;
	goal1.header.frame_id = "map";
	goal1.pose.orientation.w = 1;
	goal1.pose.position.x =  1.190000;
	goal1.pose.position.y = -0.350000;
	
	geometry_msgs::PoseStamped goal2;
	goal2.header.frame_id = "map";
	goal2.pose.orientation.w = 1;
	goal2.pose.position.x = 3.050000;
	goal2.pose.position.y = 0.700000;
	
	geometry_msgs::PoseStamped goal3;
	goal3.header.frame_id = "map";
	goal3.pose.orientation.w = 1;
	goal3.pose.position.x =  3.050000;
	goal3.pose.position.y = -1.500000;
	
	geometry_msgs::PoseStamped goal4;
	goal4.header.frame_id = "map";
	goal4.pose.orientation.w = 1;
	goal4.pose.position.x = 1.600000;
	goal4.pose.position.y = 0.700000;
	
	geometry_msgs::PoseStamped goal5;
	goal5.header.frame_id = "map";
	goal5.pose.orientation.w = 1;
	goal5.pose.position.x =  2.850000;
	goal5.pose.position.y = -0.850000;

	geometry_msgs::PoseStamped goal6;
	goal6.header.frame_id = "map";
	goal6.pose.orientation.w = 1;
	goal6.pose.position.x =  1.550000;
	goal6.pose.position.y = -1.550000;
	
	geometry_msgs::PoseStamped goal7;
	goal7.header.frame_id = "map";
	goal7.pose.orientation.w = 1;
	goal7.pose.position.x =  2.950000;
	goal7.pose.position.y =  0.850000;
	
	//goalQeue.push(goal1);
	//goalQeue.push(goal2);
	goalQeue.push(goal3);
	goalQeue.push(goal4);
	goalQeue.push(goal5);
	goalQeue.push(goal6);
	goalQeue.push(goal7);
}
int main(int argc, char** argv) {

	initGoals();
    ros::init(argc, argv, "map_goals");
    ros::NodeHandle n;

    map_sub = n.subscribe("map", 10, &mapCallback);
	goal_pub = n.advertise<geometry_msgs::PoseStamped>("goal", 10);
	baseStatus_sub = n.subscribe("/move_base/status", 1, &baseStatusCallback);
    namedWindow("Map");

    setMouseCallback("Map", mouseCallback, NULL);

	myfile.open ("/home/odroid/catkin_ws/src/evaluation_tasks/Time.txt", ios::out | ios::binary | ios::app);
	myfile << "NEW ITERATION"<< endl;
	myfile.close();
	
    while(ros::ok()) {

        if (!cv_map.empty()) imshow("Map", cv_map);

        waitKey(30);

        ros::spinOnce();
    }
    return 0;

}
