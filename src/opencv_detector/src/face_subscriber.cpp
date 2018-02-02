#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>

#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"

#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>


#include <tf/transform_listener.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

#include "std_msgs/String.h"
#include <detection_msgs/Detection.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/QuaternionStamped.h>
#include <geometry_msgs/Pose.h>
#include <visualization_msgs/Marker.h>

//#include "multiclass.h"


using namespace std;
using namespace cv;


void FacesCallback(const detection_msgs::Detection::ConstPtr &msg)
{   

    ROS_INFO("I heard: x:[%d] y:[%d]", msg->x,msg->y);
    
}

int main(int argc, char** argv)
{
    
  
    ros::init(argc, argv, "face subscriber");
    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("/recognition/faces", 10, FacesCallback);
  
    ros::spin();
    return 0;
}
