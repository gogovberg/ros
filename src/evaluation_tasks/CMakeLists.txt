cmake_minimum_required(VERSION 2.8.3)
project(evaluation_tasks)

find_package(catkin REQUIRED COMPONENTS
	roscpp
	rospy
	cv_bridge
	sensor_msgs
	nav_msgs
	std_msgs
	geometry_msgs
	tf
	image_transport
	genmsg
	message_generation
	visualization_msgs
	message_generation
)

catkin_package()

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(cliff_listener src/task_one/cliff_listener.cpp)
target_link_libraries(cliff_listener ${catkin_LIBRARIES})
add_dependencies(cliff_listener evaluation_tasks_generate_messages_cpp)

add_executable(new_goals src/task_two/new_goals.cpp)
target_link_libraries(new_goals ${catkin_LIBRARIES})
add_dependencies(new_goals evaluation_tasks_generate_messages_cpp)

