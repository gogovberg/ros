cmake_minimum_required(VERSION 2.8.3)
project(recognition_msgs)


find_package(catkin REQUIRED COMPONENTS
  roscpp rospy std_msgs sensor_msgs genmsg geometry_msgs visualization_msgs nodelet tf image_geometry cv_bridge
)
add_message_files(FILES Recognition.msg)
generate_messages(DEPENDENCIES sensor_msgs std_msgs geometry_msgs visualization_msgs)
catkin_package(CATKIN_DEPENDS message_runtime std_msgs geometry_msgs sensor_msgs)

include_directories(include
	${catkin_INCLUDE_DIRS} ${Eigen_INCLUDE_DIRS}
)

include_directories(include ${catkin_INCLUDE_DIRS})
