#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/Image.h"
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <detection_msgs/Detection.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <stdio.h>

static const std::string OPENCV_WINDOW = "Image window";

using namespace std;
using namespace cv;

image_transport::Subscriber sub;
image_transport::Publisher pub;
ros::Publisher pubDet;

cv::CascadeClassifier face_cascade;

string data_path;
string time_path;

double image_scale;
bool show_window;
int message_counter;

ofstream myfile;

void chatterCallback(const sensor_msgs::Image::ConstPtr& msg)
{
	myfile.open (time_path.c_str(), ios::out | ios::binary | ios::app);
	const clock_t begin_time = clock();
	cv_bridge::CvImagePtr cv_ptr;
	std::vector<cv::Rect> faces;
	std::vector<cv::Mat> detections;
	double haar_scale=1.2;
	int min_neighbors=3;
	int haar_flags=0;
	
	try
    {
      cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    }
    catch (cv_bridge::Exception& e)
    {
      ROS_ERROR("cv_bridge exception: %s", e.what());
      return;
    }
	if(image_scale==0.0)
	{
		image_scale = cv_ptr->image.cols/240;
		ROS_INFO("Image scale %.2f",image_scale);
	}
	cv::Mat gray_image;
	cvtColor(cv_ptr->image, gray_image, CV_BGR2GRAY );
	
	cv::Mat smallImage;
	cv::resize(gray_image, smallImage, cv::Size(round(cv_ptr->image.cols/image_scale), round(cv_ptr->image.rows / image_scale)), CV_INTER_LINEAR);
  
	cv::equalizeHist(smallImage, smallImage);
	
	face_cascade.detectMultiScale( smallImage, faces, haar_scale, min_neighbors, haar_flags,  cv::Size(30, 30) ,cv::Size(60,60));
	for ( size_t i = 0; i < faces.size(); i++ )
	{
		cv::Point pt1(faces[i].x * image_scale,faces[i].y * image_scale);
		cv::Point pt2((faces[i].x + faces[i].width)*image_scale,(faces[i].y + faces[i].height)*image_scale);
		//cv::rectangle(cv_ptr->image,pt1,pt2,cv::Scalar(255,0,0),3,8,0);
		
		cv::Mat detection_image;
		cv_ptr->image(cv::Rect(pt1.x,pt1.y,pt2.x - pt1.x,pt2.y-pt1.y)).copyTo(detection_image);
		
		if(show_window)
		{
			//cv::imshow(OPENCV_WINDOW, detection_image);
		}
		
		detection_msgs::Detection face_det= detection_msgs::Detection();
		face_det.header.seq = message_counter;
		face_det.header.stamp = cv_ptr->header.stamp;
		face_det.header.frame_id = cv_ptr->header.frame_id;
		face_det.x = pt1.x;
		face_det.y = pt1.y;
		face_det.width = pt2.x - pt1.x;
		face_det.height = pt2.y - pt1.y;
		face_det.source = "opencv";
		face_det.confidence = 1;
		
		//ROS_INFO("I Sent det: x:[%d] y:[%d]  w:[%d] h:[%d]", face_det.x,face_det.y, face_det.width,face_det.height);
	
		cv_bridge::CvImage img_bridge = cv_bridge::CvImage(face_det.header, sensor_msgs::image_encodings::RGB8,detection_image);
		sensor_msgs::Image img_msg;
		img_bridge.toImageMsg(img_msg);
		
		face_det.image = img_msg;
		
		//ROS_INFO("I Sent img:  w:[%d] h:[%d]",img_msg.width,img_msg.height);

		pubDet.publish(face_det);
		
		message_counter++;
	}
	  // Update GUI Window
    //cv::imshow(OPENCV_WINDOW, cv_ptr->image);
    cv::waitKey(3);

    // Output modified video stream
    pub.publish(cv_ptr->toImageMsg());

	try
	{
		if(myfile.is_open())
	    {
	   		 ROS_INFO("Writing time to file.");
	    		//string result = std::to_string(;
	    		myfile << float( clock () - begin_time ) /  CLOCKS_PER_SEC << endl;
	    		myfile.close();
		}
	} catch (cv::Exception& e) {

        ROS_ERROR("Exception: %s \n Line number: %d",e.what(), e.line);
    }
	
}
int main(int argc, char **argv)
{
	ros::init(argc, argv, "listener");
	ros::NodeHandle nh;
	ros::NodeHandle np("~");
	image_transport::ImageTransport it(nh);
	image_scale=0.0;
	message_counter=0;
	data_path=" ";
	show_window = false;
	
	nh.getParam("/facedetector/detector_file",data_path);
	nh.getParam("/facedetector/show_cv_window",show_window);
	np.param<string>("time_path", time_path, string(""));

	if( !face_cascade.load(data_path) ){ printf("--(!)Error loading face cascade\n"); return -1; };
	sub = it.subscribe("camera", 1, chatterCallback);
	pub = it.advertise("detections", 10);
	pubDet = nh.advertise<detection_msgs::Detection>("/detection/faces", 10);
	
	//cv::namedWindow(OPENCV_WINDOW);
	ros::spin();
	return 0;
}
