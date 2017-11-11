cmake_minimum_required(VERSION 2.8.3)
project(evaluation_tasks)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  geometry_msgs
)

catkin_package()

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(cliff_listener src/task_one/cliff_listener.cpp)
target_link_libraries(cliff_listener ${catkin_LIBRARIES})
add_dependencies(cliff_listener evaluation_tasks_generate_messages_cpp)
