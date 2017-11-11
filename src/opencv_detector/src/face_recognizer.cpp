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
#include <recognition_msgs/Recognition.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/QuaternionStamped.h>
#include <geometry_msgs/Pose.h>

//#include "multiclass.h"

using namespace std;
using namespace cv;

string base_source;
int count_pics=0;

Ptr<FaceRecognizer> model = createFisherFaceRecognizer();
cv::vector<Mat> images;
cv::vector<int> labels;

ros::Publisher pub;
ros::Publisher pub_markers;


static void read_csv(const string& filename, cv::vector<Mat>& images, cv::vector<int>& labels, char separator = ';') {
    std::ifstream file(filename.c_str(), ifstream::in);
    if (!file) {
        ROS_ERROR("No valid input file was given, please check the given filename.");
    }
    string line, path, classlabel;
    while (getline(file, line)) {
        stringstream liness(line);
        getline(liness, path, separator);
        getline(liness, classlabel);
        if(!path.empty() && !classlabel.empty()) {
            images.push_back(imread(path, 0));
            labels.push_back(atoi(classlabel.c_str()));
        }
    }
}
string DetectionLabel(int predictedLabel)
{
    string label="unknown";
        switch(predictedLabel)
        {
            case 0:
                label = "tina";
                break;
            case 1:
                label = "harry";
                break;
            case 2:
                label = "kim";
                break;
            case 3:
                label = "forest";
                break;
            case 4:
                label = "filip";
                break;
            case 5:
                label = "peter";
                break;
            case 6:
                label = "ellen";
		        break;
    	    case 7:
    		label = "metthew";
                    break;
    	    case 8:
    		label = "scarlett";
                    break;
            default:
                label="unknown";
                break;
        }
    return label;
}
void PrepareModel()
{
    try {
        read_csv(base_source, images, labels);
    } catch (cv::Exception& e) {

        ROS_ERROR("Error opening file!");
    }
	
	try
	{
		  // Quit if there are not enough images for this demo.
		if(images.size() <= 1) {
			ROS_INFO("This demo needs at least 2 images to work. Please add more images to your data set!");

		}
		else
		{
		  model->train(images, labels);
		}
	} catch (cv::Exception& e) {

	  ROS_ERROR("Exception: %s \n Line number: %d",e.what(), e.line);
    }
  

}


void FacesCallback(const detection_msgs::Detection::ConstPtr &msg)
{   
	try
	{
		
		Mat gray_detection;
		Size size(100,100);
		Mat resized_image;
		//geometry_msgs::

		//ROS_INFO("I heard: x:[%d] y:[%d]", msg->x,msg->y);
		//ROS_INFO("%s",base_source.c_str());

		cv_bridge::CvImagePtr cv_ptr;
		cv_ptr = cv_bridge::toCvCopy(msg->image, sensor_msgs::image_encodings::BGR8);
		Mat image = cv_ptr->image;
		resize(image,resized_image,size);	
		 /*
		 if(count_pics % 10 ==0 && count_pics < 301)
		{
			string path = format("/home/team_nu/ROS/src/opencv_detector/data/filip/filip_%d.jpg",count_pics);
			imwrite(path,resized_image);
			if(count_pics % 10 ==0)
			{
				ROS_INFO("CHANGE %d",count_pics);
			}
        
		}
		count_pics++;
		*/
		cvtColor(resized_image,gray_detection,CV_BGR2GRAY);
    

		int predictedLabel = model->predict(gray_detection);
		string label = DetectionLabel(predictedLabel);
		ROS_INFO("Classified in group[%s]",label.c_str());

		detection_msgs::Detection face_rec = detection_msgs::Detection();

		face_rec.header = msg->header;
		face_rec.x = msg->x;
		face_rec.y = msg->y;
		face_rec.width = msg->width;
		face_rec.height = msg->height;
		face_rec.source = msg->source;
		face_rec.label = label;
		face_rec.confidence = msg->confidence;
		//face_rec.image = msg->image;

		//ROS_INFO("I heard: x:[%d] y:[%d] label:[%s]", face_rec.x,face_rec.y,face_rec.label.c_str());
		pub.publish(face_rec);
	} catch (cv::Exception& e) {

        ROS_ERROR("Exception: %s \n Line number: %d",e.what(), e.line);
    }
	ROS_INFO("I heard: x:[%d] y:[%d]", msg->x,msg->y);
 	
}

int main(int argc, char** argv)
{
    
    count_pics=0;
    ros::init(argc, argv, "recognizer");
    ros::NodeHandle n;
    ros::NodeHandle np("~");
    ros::NodeHandle pubn;
    np.param<string>("base_source", base_source, string(""));
    PrepareModel();
    ros::Subscriber sub = n.subscribe("/detection/faces", 10, FacesCallback);
    pub = pubn.advertise<detection_msgs::Detection>("/recognition/faces", 10);
    ros::spin();
    return 0;
}
