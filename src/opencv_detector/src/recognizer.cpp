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

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

#include <detection_msgs/Detection.h>

//#include "multiclass.h"

using namespace std;
using namespace cv;

string base_source;
int count_pics=0;

Ptr<FaceRecognizer> model = createFisherFaceRecognizer();
cv::vector<Mat> images;
cv::vector<int> labels;


static void read_csv(const string& filename, cv::vector<Mat>& images, cv::vector<int>& labels, char separator = ';') {
    std::ifstream file(filename.c_str(), ifstream::in);
    if (!file) {
        ROS_INFO("No valid input file was given, please check the given filename.");
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
                label = "stop";
                break;
            case 1:
                label = "horn";
                break;
            case 2:
                label = "one way";
                break;
            case 3:
                label = "turn left";
                break;
            case 4:
                label = "speed limit";
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

        ROS_INFO("Error opening file!");
    }
    // Quit if there are not enough images for this demo.
    if(images.size() <= 1) {
        ROS_INFO("This demo needs at least 2 images to work. Please add more images to your data set!");
    }
    else
    {
         model->train(images, labels);
    }
   
}


void FacesCallback(const detection_msgs::Detection::ConstPtr &msg)
{   
    Mat src_detection,gray_detection;
    Size size(150,150);
    Mat resized_image;

    //ROS_INFO("I heard: x:[%d] y:[%d] width:[%d] height[%d]", msg->x,msg->y,msg->width,msg->height);
    //ROS_INFO("%s",base_source.c_str());
    cv_bridge::CvImagePtr cv_ptr;
    cv_ptr = cv_bridge::toCvCopy(msg->image, sensor_msgs::image_encodings::BGR8);
    //Mat image = cv_ptr->image;
    //resize(image,resized_image,size);
    
    if(count_pics % 10 ==0 && count_pics < 301)
    {
        string path = format("/home/gogov/caktin_ws/src/opencv_detector/data/face_%d.jpg",count_pics);
        imwrite(path,resized_image);
        if(count_pics % 10 ==0)
        {
            ROS_INFO("CHANGE");
        }
        
    }
    count_pics++;
    
    //cvtColor(resized_image,gray_detection,CV_BGR2GRAY);
    

    //int predictedLabel = model->predict(gray_detection);

    //ROS_INFO("Classified in group[%s]",DetectionLabel(predictedLabel).c_str());
}

int main(int argc, char** argv)
{
    
    count_pics=0;
    ros::init(argc, argv, "recognizer");
    ros::NodeHandle n;
    ros::NodeHandle np("~");
    np.param<string>("base_source", base_source, string(""));
    //PrepareModel();
    ros::Subscriber sub = n.subscribe("/facedetector/faces", 10, FacesCallback);
    
    ros::spin();
    return 0;
}