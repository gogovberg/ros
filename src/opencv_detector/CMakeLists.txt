cmake_minimum_required(VERSION 2.8.3)
project(opencv_detector)

find_package(catkin REQUIRED COMPONENTS
  roscpp 
  rospy 
  std_msgs 
  sensor_msgs 
  image_transport 
  cv_bridge 
  genmsg 
  geometry_msgs 
  visualization_msgs 
  tf detection_msgs 
  message_generation
)

catkin_python_setup()

catkin_package(CATKIN_DEPENDS message_runtime)

install(PROGRAMS src/detector DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})


add_executable(face_recognizer src/face_recognizer.cpp) 
target_link_libraries(face_recognizer ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})


add_executable(face_detector src/face_detector.cpp) 
target_link_libraries(face_detector ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})

add_executable(face_subscriber src/face_subscriber.cpp) 
target_link_libraries(face_subscriber ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})