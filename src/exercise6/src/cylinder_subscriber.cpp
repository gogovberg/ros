#include <iostream>
#include <fstream>
#include <boost/shared_ptr.hpp>

// PCL specific includes
#include <pcl/ModelCoefficients.h>
#include <pcl/PointIndices.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/segmentation/extract_clusters.h>
#include <pcl_ros/segmentation/sac_segmentation.h>
#include <pcl/surface/convex_hull.h>
#include <pcl/filters/project_inliers.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/segmentation/extract_polygonal_prism_data.h>
#include <pcl/features/normal_3d.h>

//Filters and Downsampling
#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/filters/passthrough.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/filters/radius_outlier_removal.h>

//Clustering
#include <pcl/features/normal_3d.h>
#include <pcl/kdtree/kdtree.h>
#include <pcl/features/normal_3d.h>

// ROS
#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>

using namespace std;

// Type Defs
typedef pcl::PointXYZ PointT;
typedef pcl::PointCloud<PointT> CloudT;


void callbackCylinder(const sensor_msgs::PointCloud2ConstPtr& cloud_msg)
{ 
   ROS_INFO("Cylinder found");
}

int main (int argc, char** argv) {

  // Initialize ROS
  ros::init (argc, argv, "cylinder subscriber");
  ros::NodeHandle nh;

  // Create a ROS subscriber for the input point cloud
  ros::Subscriber sub = nh.subscribe ("cylinders", 1, callbackCylinder);
  // Spin
  ros::spin ();
}
