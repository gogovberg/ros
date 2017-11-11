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

#include "std_msgs/String.h"
#include <detection_msgs/Detection.h>

//#include "multiclass.h"

using namespace std;
using namespace dlib;
using namespace cv;

string base_source;


int count_pics = 0;



Ptr<FaceRecognizer> model = createEigenFaceRecognizer();
cv::vector<Mat> images;
cv::vector<int> labels;

ros::Publisher pub;

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
                label = "turn left";
                break;
            case 1:
                label = "horn";
                break;
            case 2:
                label = "stop";
                break;
            case 3:
                label = "speed limit";
                break;
            case 4:
                label = "one way";
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
    model->train(images, labels);

}

void SignCallback(const detection_msgs::Detection::ConstPtr &msg)
{   
    Mat src_detection,gray_detection;
    Size size(100,100);
    Mat resized_image;

    //ROS_INFO("I heard: x:[%d] y:[%d] width:[%d] height[%d]", msg->x,msg->y,msg->width,msg->height);
    //ROS_INFO("%s",base_source.c_str());
    cv_bridge::CvImagePtr cv_ptr;
    cv_ptr = cv_bridge::toCvCopy(msg->image, sensor_msgs::image_encodings::BGR8);
    Mat image = cv_ptr->image;
    resize(image,resized_image,size);
    /*
    if(count_pics % 10 ==0 && count_pics < 301)
    {
        string path = format("/home/team_nu/ROS/src/dlib_detector/data/stop/stop_%d.jpg",count_pics);
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

    detection_msgs::Detection traff_rec = detection_msgs::Detection();

    traff_rec.header = msg->header;
    traff_rec.x = msg->x;
    traff_rec.y = msg->y;
    traff_rec.width = msg->width;
    traff_rec.height = msg->height;
    traff_rec.source = msg->source;
    traff_rec.label = DetectionLabel(predictedLabel);
    traff_rec.confidence = msg->confidence;	

    //ROS_INFO("Classified in group[%s]",DetectionLabel(predictedLabel).c_str());
    pub.publish(traff_rec);
}

int main(int argc, char** argv)
{
    
    count_pics=0;
    ros::init(argc, argv, "traffic_sign_listener");

    ros::NodeHandle n;
    ros::NodeHandle np("~");
    ros::NodeHandle pubn;

    np.param<string>("base_source", base_source, string(""));
    PrepareModel();
    ros::Subscriber sub = n.subscribe("/detector/traffic_signs", 10, SignCallback);
    pub = pubn.advertise<detection_msgs::Detection>("/recognition/traffic_signs", 1000);
    ros::spin();
    return 0;
}
