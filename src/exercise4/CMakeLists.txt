cmake_minimum_required(VERSION 2.8.3)
project(exercise4)

find_package(catkin REQUIRED COMPONENTS rospy std_msgs geometry_msgs visualization_msgs tf)

catkin_python_setup()

catkin_package(CATKIN_DEPENDS message_runtime)

install(PROGRAMS bin/breadcrumbs DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

