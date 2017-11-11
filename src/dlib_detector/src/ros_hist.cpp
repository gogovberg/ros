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

#include <dlib/svm_threaded.h>
#include <dlib/image_processing.h>
#include <dlib/data_io.h>
#include <dlib/image_transforms.h>
#include <dlib/opencv.h>

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

#include <detection_msgs/Detection.h>

//#include "multiclass.h"

using namespace std;
using namespace dlib;
using namespace cv;

string base_source;
/// Histograms
MatND hist_stop;
MatND hist_speed_limit;
MatND hist_one_way;
MatND hist_man_left;
MatND hist_horn;

int count_pics = 0;
//string hist_num ;
int hist_num = 3;
int h_bins = 12; 
int s_bins = 12;
int histSize[] = { h_bins, s_bins };
float h_ranges[] = { 0, 180 };
float s_ranges[] = { 0, 256 };
const float* ranges[] = { h_ranges, s_ranges };
int channels[] = { 0, 1 };

MatND SpatialHistograms(Mat hsv_image,int parts)
{
    //number of histograms 
    int n = parts*parts;
    MatND one_histo;
    Mat spatials[n];
    MatND histograms[n];

  
    
   
    //if the image is not nxn we have to devide cols and rows to equal parts
    int row_rate = hsv_image.rows/parts;
    int col_rate = hsv_image.cols/parts;

    //if the devision of rows and cols  module parts is not equal to 0 we have to make sure we do not go over the image size
    int row_stop = parts*row_rate;
    int column_stop = parts*col_rate;

    int count=0;
   // printf("rows[%d], row_rate[%d]\ncols[%d], cols_rate[%d]\n",hsv_image.rows,row_rate,hsv_image.cols,col_rate);

    //loop that creates n images each one of size row_rate x col_rate 
    for(int i=0; i<row_stop; i=i+row_rate)
    {
        //printf("row_b[%d] row_e[%d] \n",i,i+row_rate-1 );
        for(int j=0; j<column_stop; j=j+col_rate)
        {
           
            //printf("col_b[%d] col_e[%d] \n",j,j+col_rate-1 );
            
            spatials[count] = hsv_image( Range( i, i+row_rate-1), Range( j, j+col_rate-1));
            count++;
        }
        //printf("-----------------------\n");
    }
    // calculate all n histograms 
    for(int i=0; i<n; i++)
    {
         /// Calculate the histograms for the HSV images
        calcHist( &spatials[i], 1, channels, Mat(), histograms[i], 2, histSize, ranges, true, false );
        normalize( histograms[i], histograms[i], 0, 1, NORM_MINMAX, -1, Mat() );
    }
    //concatinate all n histograms in one_hist ( no deference between h and v concatination)
    hconcat(histograms,n,one_histo);
    return one_histo;
}

void facesCallback(const detection_msgs::Detection::ConstPtr &msg)
{   
    Mat src_detection,hsv_detection;
    MatND hist_detection;
   

    //ROS_INFO("I heard: x:[%d] y:[%d] width:[%d] height[%d]", msg->x,msg->y,msg->width,msg->height);
    //ROS_INFO("%s",base_source.c_str());
    cv_bridge::CvImagePtr cv_ptr;
    cv_ptr = cv_bridge::toCvCopy(msg->image, sensor_msgs::image_encodings::BGR8);
    //cv_bridge::CvImageConstPtr cv_ptr; 
    //cv_ptr = toCvCopy(msg->image,CV_8UC3);
    
    
    cvtColor(cv_ptr->image,hsv_detection,COLOR_BGR2HSV);
    // Calculate the histograms for the HSV images
    if(count_pics%10==0)
    {
        //imwrite("/home/gogov/caktin_ws/src/dlib_detector/data/slika.jpg", cv_ptr->image );
    }
    hist_detection = SpatialHistograms(hsv_detection,hist_num);


    double base_stop = compareHist( hist_stop, hist_detection, CV_COMP_CORREL );
    double base_speed_limit = compareHist( hist_speed_limit, hist_detection, CV_COMP_CORREL );
    double base_one_way = compareHist( hist_one_way, hist_detection, CV_COMP_CORREL );
    double base_mat_left = compareHist( hist_man_left, hist_detection, CV_COMP_CORREL );
    double base_horn = compareHist( hist_horn, hist_detection, CV_COMP_CORREL );
    ROS_INFO( " Method [%d] Stop, Speed limit, One way,Left, Horn: %f, %f, %f, %f, %f", CV_COMP_CORREL, base_stop, base_speed_limit , base_one_way, base_mat_left,base_horn);

   
}
void prepare_base_histograms()
{

    Mat src_stop,           hsv_stop;
    Mat src_speed_limit,    hsv_speed_limit;
    Mat src_one_way,        hsv_one_way;
    Mat src_man_left,       hsv_man_left;
    Mat src_horn,           hsv_horn;

    //read images from data folder 
    src_stop = imread( base_source+"/stop.jpg", 1 );
    src_speed_limit = imread( base_source+"/speed_limit.jpg", 1 );
    src_one_way = imread( base_source+"/one_way_street.jpg", 1 );
    src_man_left = imread( base_source+"/turn_left.jpg", 1 );
    src_horn = imread( base_source+"/horny.jpg", 1 );

     /// Convert to HSV
    cvtColor( src_stop, hsv_stop, COLOR_BGR2HSV );
    cvtColor( src_speed_limit, hsv_speed_limit, COLOR_BGR2HSV );
    cvtColor( src_one_way, hsv_one_way, COLOR_BGR2HSV );
    cvtColor( src_man_left, hsv_man_left, COLOR_BGR2HSV );
    cvtColor( src_horn, hsv_horn, COLOR_BGR2HSV );

    hist_stop = SpatialHistograms(hsv_stop,hist_num);
    hist_speed_limit = SpatialHistograms(hsv_speed_limit,hist_num);
    hist_one_way = SpatialHistograms(hsv_one_way,hist_num);
    hist_man_left = SpatialHistograms(hsv_man_left,hist_num);
    hist_horn = SpatialHistograms(hsv_horn,hist_num);

    
}
int main(int argc, char** argv)
{
    
    count_pics=0;
    ros::init(argc, argv, "traffic_sign_listener");
    ros::NodeHandle n;
    ros::NodeHandle np("~");
    np.param<string>("base_source", base_source, string(""));
    //np.param<string>("hist_num", hist_num, string(""));
    prepare_base_histograms();
    ros::Subscriber sub = n.subscribe("/detector/traffic_signs", 10, facesCallback);
    
    ros::spin();
    return 0;
}