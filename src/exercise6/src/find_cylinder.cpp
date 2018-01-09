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

double downsample_leaf_size;
string path;

ros::Publisher pub_cylinders;

ofstream myfile;


void callbackCylinder(const sensor_msgs::PointCloud2ConstPtr& cloud_msg)
{ 
  
  try
    {
      myfile.open (path.c_str(), ios::out | ios::binary | ios::app);
      const clock_t begin_time = clock();
	  
      // Container for original & filtered data
      boost::shared_ptr<pcl::PCLPointCloud2> cloud(new pcl::PCLPointCloud2);
      pcl::PCLPointCloud2ConstPtr cloudPtr(cloud);
      pcl::PCLPointCloud2 cloud_filtered_out;

      ///////////////////////////////////////////////////
      //                                               //
      //                 Conversion                    //
      //                                               //
      ///////////////////////////////////////////////////
      pcl_conversions::toPCL(*cloud_msg, *cloud);


      ///////////////////////////////////////////////////
      //                                               //
      //             Cylinder Extraction                 //
      //                                               //
      ///////////////////////////////////////////////////

     boost::shared_ptr<pcl::PCLPointCloud2> temp(new pcl::PCLPointCloud2);
      *temp = *cloud;

      //// Did I mention pointers?
      pcl::PCLPointCloud2ConstPtr tempPtr(temp);
      pcl::PointCloud<pcl::PointXYZRGB>::Ptr aboveCloudPtr(new pcl::PointCloud<pcl::PointXYZRGB>);
      pcl::ModelCoefficients::Ptr groundcoeffPtr(new pcl::ModelCoefficients);
      pcl::PointIndices::Ptr groundindicPtr(new pcl::PointIndices);
      pcl::PointCloud<pcl::PointXYZRGB>::Ptr groundpointsPtr(new pcl::PointCloud<pcl::PointXYZRGB>);
      pcl::PointCloud<pcl::PointXYZRGB>::Ptr objectpointsPtr(new pcl::PointCloud<pcl::PointXYZRGB>);
      pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloudprojPtr(new pcl::PointCloud<pcl::PointXYZRGB>);
      pcl::PointCloud<pcl::PointXYZRGB>::Ptr groundhullPtr(new pcl::PointCloud<pcl::PointXYZRGB>);
      pcl::PointIndices::Ptr objectindicPtr(new pcl::PointIndices);
      pcl::NormalEstimation<pcl::PointXYZRGB, pcl::Normal> ne;
      pcl::ExtractIndices<pcl::Normal> extract_normals;
      pcl::PointCloud<pcl::Normal>::Ptr cloud_normals (new pcl::PointCloud<pcl::Normal>);
      pcl::PointCloud<pcl::Normal>::Ptr cloud_normals2 (new pcl::PointCloud<pcl::Normal>);
      pcl::search::KdTree<pcl::PointXYZRGB>::Ptr tree (new pcl::search::KdTree<pcl::PointXYZRGB> ());
	    pcl::ModelCoefficients::Ptr coefficients_cylinder (new pcl::ModelCoefficients);
      pcl::PointIndices::Ptr inliers_cylinder (new pcl::PointIndices);
     
	    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cylinder_outliers (new pcl::PointCloud<pcl::PointXYZRGB>);
      
	    pcl::fromPCLPointCloud2(*temp, *aboveCloudPtr);

      ne.setSearchMethod (tree);
      ne.setInputCloud (aboveCloudPtr);
      ne.setKSearch (50);
      ne.compute (*cloud_normals);
	  
      ROS_INFO("Start segmentation");
	    pcl::SACSegmentationFromNormals<pcl::PointXYZRGB, pcl::Normal> seg;
      seg.setOptimizeCoefficients (true);
      seg.setModelType (pcl::SACMODEL_CYLINDER);
      seg.setMethodType (pcl::SAC_RANSAC);
      seg.setMaxIterations (10000);
      seg.setDistanceThreshold (0.05);
      seg.setRadiusLimits (0, 0.2);
      seg.setInputCloud (aboveCloudPtr);
      seg.setInputNormals (cloud_normals);
      seg.segment (*inliers_cylinder, *coefficients_cylinder);

      ROS_INFO(" Extract");
      pcl::ExtractIndices<pcl::PointXYZRGB> extract;
      pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_cylinder (new pcl::PointCloud<pcl::PointXYZRGB>);

      extract.setInputCloud (aboveCloudPtr);
      extract.setIndices (inliers_cylinder);
      extract.setNegative (false);
      extract.filter (*cloud_cylinder);
      
            
      if (cloud_cylinder->points.empty())
      {
         ROS_INFO("Can't find the cylindrical component.");
      }
      else
      {
         ROS_INFO("PointCloud representing the cylindrical component: %ld data points.",cloud_cylinder->points.size());
           // Publish the found plane
          pcl::PCLPointCloud2 outcloud;
          pcl::toPCLPointCloud2 (*cloud_cylinder, outcloud);
          pub_cylinders.publish (outcloud);
      }
      if(myfile.is_open())
      {
        ROS_INFO("Writing time to file.");
        //string result = std::to_string(;
        myfile << float( clock () - begin_time ) /  CLOCKS_PER_SEC << endl;
        myfile.close();
      }
      
  }
  catch ( ros::Exception &e )
  {
      ROS_ERROR("Error occured: %s ", e.what());
  }

}

int main (int argc, char** argv) {

  // Initialize ROS
  ros::init (argc, argv, "find_cylinder");
  ros::NodeHandle nh;
  
  downsample_leaf_size = 0.01; // 1cm
  path = "/home/team_lambda/catkin_ws/src/exercise6/cylinderTime.txt";

  nh.getParam("downsample_leaf_size", downsample_leaf_size);
  nh.getParam("/find_cylinder/file_path",path);

  ROS_INFO_STREAM("obstacle detection: using a leaf size of '" << downsample_leaf_size << "' m for downsampling.");
  ROS_INFO_STREAM("File path for writing time elapsed " << path);
  // Create a ROS subscriber for the input point cloud
  ros::Subscriber sub = nh.subscribe ("above_plane", 1, callbackCylinder);

  // Create a ROS publisher for the output point cloud
  pub_cylinders = nh.advertise<pcl::PCLPointCloud2> ("cylinders", 1);
  // Spin
  ros::spin ();
}
