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
ros::Publisher pub_above_plane;
ros::Publisher pub_ground_plane;
ofstream myfile;
clock_t begin_time;

void callbackPlane(const sensor_msgs::PointCloud2ConstPtr& cloud_msg)
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
      //             Passthrough filter                //
      //                                               //
      ///////////////////////////////////////////////////
      pcl::PassThrough<pcl::PCLPointCloud2> pass;
      pass.setInputCloud(cloudPtr);
      pass.setFilterFieldName("z");
      pass.setFilterLimits(0, 2); //1.3 works well
      pass.filter(*cloud);

      ///////////////////////////////////////////////////
      //                                               //
      //             Voxel Grid Downsample             //
      //                                               //
      ///////////////////////////////////////////////////
      pcl::VoxelGrid<pcl::PCLPointCloud2> sor;
      sor.setInputCloud (cloudPtr);
      sor.setLeafSize (downsample_leaf_size, downsample_leaf_size, downsample_leaf_size);
      sor.filter (*cloud);

      ///////////////////////////////////////////////////
      //                                               //
      //              Filter out the noise             //
      //                                               //
      ///////////////////////////////////////////////////
      pcl::StatisticalOutlierRemoval<pcl::PCLPointCloud2> sor2;
      sor2.setInputCloud(cloudPtr);
      sor2.setMeanK(80);
      sor2.setStddevMulThresh(0.15);
      sor2.filter(*cloud);

      ///////////////////////////////////////////////////
      //                                               //
      //             Ground Extraction                 //
      //                                               //
      ///////////////////////////////////////////////////

      boost::shared_ptr<pcl::PCLPointCloud2> temp(new pcl::PCLPointCloud2);
      *temp = *cloud;

      //// Did I mention pointers?
      pcl::PCLPointCloud2ConstPtr tempPtr(temp);
      pcl::PointCloud<pcl::PointXYZRGB>::Ptr groundcloudPtr(new pcl::PointCloud<pcl::PointXYZRGB>);
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

      pcl::fromPCLPointCloud2(*temp, *groundcloudPtr);

      ne.setSearchMethod (tree);
      ne.setInputCloud (groundcloudPtr);
      ne.setKSearch (50);
      ne.compute (*cloud_normals);

      //// Find the ground plane using RANSAC
     
      pcl::SACSegmentationFromNormals<pcl::PointXYZRGB, pcl::Normal> seg;
      seg.setOptimizeCoefficients (true);
      seg.setModelType (pcl::SACMODEL_PLANE);
      seg.setMethodType (pcl::SAC_RANSAC);
      seg.setMaxIterations (200);
      seg.setDistanceThreshold (0.014); // 0.0195
      seg.setInputCloud (groundcloudPtr);
      seg.setInputNormals (cloud_normals);
      seg.segment (*groundindicPtr, *groundcoeffPtr);
      ROS_INFO("Ground cloud before filtering: %d data points.",groundcloudPtr->height * groundcloudPtr->width);

      ////Extract ground plane inliers
      pcl::ExtractIndices<pcl::PointXYZRGB> extractor;
      extractor.setInputCloud(groundcloudPtr);
      extractor.setIndices(groundindicPtr);
      extractor.filter(*groundpointsPtr);
      ROS_INFO("Ground cloud after filtering: %d data points.",groundpointsPtr->height * groundpointsPtr->width);
     

      // publish filtered ground plane
      pcl::PCLPointCloud2 ground_plane_cloud;
      pcl::toPCLPointCloud2(*groundpointsPtr, ground_plane_cloud);
      pub_ground_plane.publish(ground_plane_cloud);



      ////Extract the ground plane outliers
      pcl::ExtractIndices<pcl::PointXYZRGB> outlier_extractor;
      outlier_extractor.setInputCloud(groundcloudPtr);
      outlier_extractor.setIndices(groundindicPtr);
      outlier_extractor.setNegative(true);
      outlier_extractor.filter(*objectpointsPtr);

      extract_normals.setNegative (true);
      extract_normals.setInputCloud (cloud_normals);
      extract_normals.setIndices (groundindicPtr);
      extract_normals.filter (*cloud_normals2);

      ROS_INFO("Objects cloud before filtering: %d data points.",objectpointsPtr->height * objectpointsPtr->width);

      // publish filtered ground plane
      pcl::PCLPointCloud2 above_plane_cloud;
      pcl::toPCLPointCloud2(*objectpointsPtr, above_plane_cloud);
      pub_above_plane.publish(above_plane_cloud);

     
      // Create the segmentation object for the planar model and set all the parameters
	  /*
      pcl::ModelCoefficients::Ptr coefficients_cylinder (new pcl::ModelCoefficients);
      pcl::PointIndices::Ptr inliers_cylinder (new pcl::PointIndices);
      pcl::PointCloud<pcl::PointXYZRGB>::Ptr cylinder_outliers (new pcl::PointCloud<pcl::PointXYZRGB>);
     
      ROS_INFO("Start segmentation");
      seg.setOptimizeCoefficients (true);
      seg.setModelType (pcl::SACMODEL_CYLINDER);
      seg.setMethodType (pcl::SAC_RANSAC);
      seg.setMaxIterations (10000);
      seg.setDistanceThreshold (0.05);
      seg.setRadiusLimits (0, 0.2);
      seg.setInputCloud (objectpointsPtr);
      seg.setInputNormals (cloud_normals2);
      seg.segment (*inliers_cylinder, *coefficients_cylinder);
      ROS_INFO(" Extract");

      pcl::ExtractIndices<pcl::PointXYZRGB> extract;
      pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_cylinder (new pcl::PointCloud<pcl::PointXYZRGB>);
      extract.setInputCloud (objectpointsPtr);
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
	  
      */
            
    
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
  ros::init (argc, argv, "find_plane");
  ros::NodeHandle nh;
  downsample_leaf_size = 0.01; // 1cm
  path = "/home/team_lambda/catkin_ws/src/exercise6/cylinderTime.txt";

  nh.getParam("downsample_leaf_size", downsample_leaf_size);
  nh.getParam("/find_plane/file_path",path);

  ROS_INFO_STREAM("obstacle detection: using a leaf size of '" << downsample_leaf_size << "' m for downsampling.");
  ROS_INFO_STREAM("File path for writing time elapsed " << path);
  
  ros::Subscriber sub = nh.subscribe ("input", 1, callbackPlane);

  // Create a ROS publisher for the output point cloud
  pub_ground_plane = nh.advertise<pcl::PCLPointCloud2> ("ground_plane", 1);
  pub_above_plane = nh.advertise<pcl::PCLPointCloud2> ("above_plane", 1);
  // Spin
  ros::spin ();
}
