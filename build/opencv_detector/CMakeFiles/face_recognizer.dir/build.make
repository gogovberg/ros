# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/odroid/catkin_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/odroid/catkin_ws/build

# Include any dependencies generated for this target.
include opencv_detector/CMakeFiles/face_recognizer.dir/depend.make

# Include the progress variables for this target.
include opencv_detector/CMakeFiles/face_recognizer.dir/progress.make

# Include the compile flags for this target's objects.
include opencv_detector/CMakeFiles/face_recognizer.dir/flags.make

opencv_detector/CMakeFiles/face_recognizer.dir/src/face_recognizer.cpp.o: opencv_detector/CMakeFiles/face_recognizer.dir/flags.make
opencv_detector/CMakeFiles/face_recognizer.dir/src/face_recognizer.cpp.o: /home/odroid/catkin_ws/src/opencv_detector/src/face_recognizer.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/odroid/catkin_ws/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object opencv_detector/CMakeFiles/face_recognizer.dir/src/face_recognizer.cpp.o"
	cd /home/odroid/catkin_ws/build/opencv_detector && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/face_recognizer.dir/src/face_recognizer.cpp.o -c /home/odroid/catkin_ws/src/opencv_detector/src/face_recognizer.cpp

opencv_detector/CMakeFiles/face_recognizer.dir/src/face_recognizer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/face_recognizer.dir/src/face_recognizer.cpp.i"
	cd /home/odroid/catkin_ws/build/opencv_detector && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/odroid/catkin_ws/src/opencv_detector/src/face_recognizer.cpp > CMakeFiles/face_recognizer.dir/src/face_recognizer.cpp.i

opencv_detector/CMakeFiles/face_recognizer.dir/src/face_recognizer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/face_recognizer.dir/src/face_recognizer.cpp.s"
	cd /home/odroid/catkin_ws/build/opencv_detector && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/odroid/catkin_ws/src/opencv_detector/src/face_recognizer.cpp -o CMakeFiles/face_recognizer.dir/src/face_recognizer.cpp.s

opencv_detector/CMakeFiles/face_recognizer.dir/src/face_recognizer.cpp.o.requires:
.PHONY : opencv_detector/CMakeFiles/face_recognizer.dir/src/face_recognizer.cpp.o.requires

opencv_detector/CMakeFiles/face_recognizer.dir/src/face_recognizer.cpp.o.provides: opencv_detector/CMakeFiles/face_recognizer.dir/src/face_recognizer.cpp.o.requires
	$(MAKE) -f opencv_detector/CMakeFiles/face_recognizer.dir/build.make opencv_detector/CMakeFiles/face_recognizer.dir/src/face_recognizer.cpp.o.provides.build
.PHONY : opencv_detector/CMakeFiles/face_recognizer.dir/src/face_recognizer.cpp.o.provides

opencv_detector/CMakeFiles/face_recognizer.dir/src/face_recognizer.cpp.o.provides.build: opencv_detector/CMakeFiles/face_recognizer.dir/src/face_recognizer.cpp.o

# Object files for target face_recognizer
face_recognizer_OBJECTS = \
"CMakeFiles/face_recognizer.dir/src/face_recognizer.cpp.o"

# External object files for target face_recognizer
face_recognizer_EXTERNAL_OBJECTS =

/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: opencv_detector/CMakeFiles/face_recognizer.dir/src/face_recognizer.cpp.o
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: opencv_detector/CMakeFiles/face_recognizer.dir/build.make
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /opt/ros/indigo/lib/libimage_transport.so
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /opt/ros/indigo/lib/libclass_loader.so
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /usr/lib/libPocoFoundation.so
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /usr/lib/arm-linux-gnueabihf/libdl.so
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /opt/ros/indigo/lib/libroslib.so
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /opt/ros/indigo/lib/librospack.so
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /usr/lib/arm-linux-gnueabihf/libpython2.7.so
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /usr/lib/arm-linux-gnueabihf/libboost_program_options.so
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /usr/lib/arm-linux-gnueabihf/libtinyxml.so
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /opt/ros/indigo/lib/libcv_bridge.so
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /usr/lib/arm-linux-gnueabihf/libopencv_videostab.so.2.4.8
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /usr/lib/arm-linux-gnueabihf/libopencv_video.so.2.4.8
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /usr/lib/arm-linux-gnueabihf/libopencv_superres.so.2.4.8
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /usr/lib/arm-linux-gnueabihf/libopencv_stitching.so.2.4.8
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /usr/lib/arm-linux-gnueabihf/libopencv_photo.so.2.4.8
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /usr/lib/arm-linux-gnueabihf/libopencv_ocl.so.2.4.8
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /usr/lib/arm-linux-gnueabihf/libopencv_objdetect.so.2.4.8
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /usr/lib/arm-linux-gnueabihf/libopencv_ml.so.2.4.8
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /usr/lib/arm-linux-gnueabihf/libopencv_legacy.so.2.4.8
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /usr/lib/arm-linux-gnueabihf/libopencv_imgproc.so.2.4.8
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /usr/lib/arm-linux-gnueabihf/libopencv_highgui.so.2.4.8
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /usr/lib/arm-linux-gnueabihf/libopencv_gpu.so.2.4.8
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /usr/lib/arm-linux-gnueabihf/libopencv_flann.so.2.4.8
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /usr/lib/arm-linux-gnueabihf/libopencv_features2d.so.2.4.8
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /usr/lib/arm-linux-gnueabihf/libopencv_core.so.2.4.8
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /usr/lib/arm-linux-gnueabihf/libopencv_contrib.so.2.4.8
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /usr/lib/arm-linux-gnueabihf/libopencv_calib3d.so.2.4.8
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /opt/ros/indigo/lib/libtf.so
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /opt/ros/indigo/lib/libtf2_ros.so
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /opt/ros/indigo/lib/libactionlib.so
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /opt/ros/indigo/lib/libmessage_filters.so
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /opt/ros/indigo/lib/libroscpp.so
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /usr/lib/arm-linux-gnueabihf/libboost_signals.so
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /usr/lib/arm-linux-gnueabihf/libboost_filesystem.so
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /opt/ros/indigo/lib/libxmlrpcpp.so
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /opt/ros/indigo/lib/libtf2.so
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /opt/ros/indigo/lib/librosconsole.so
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /opt/ros/indigo/lib/librosconsole_log4cxx.so
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /opt/ros/indigo/lib/librosconsole_backend_interface.so
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /usr/lib/liblog4cxx.so
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /usr/lib/arm-linux-gnueabihf/libboost_regex.so
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /opt/ros/indigo/lib/libroscpp_serialization.so
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /opt/ros/indigo/lib/librostime.so
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /usr/lib/arm-linux-gnueabihf/libboost_date_time.so
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /opt/ros/indigo/lib/libcpp_common.so
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /usr/lib/arm-linux-gnueabihf/libboost_system.so
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /usr/lib/arm-linux-gnueabihf/libboost_thread.so
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /usr/lib/arm-linux-gnueabihf/libpthread.so
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: /usr/lib/arm-linux-gnueabihf/libconsole_bridge.so
/home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer: opencv_detector/CMakeFiles/face_recognizer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable /home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer"
	cd /home/odroid/catkin_ws/build/opencv_detector && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/face_recognizer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
opencv_detector/CMakeFiles/face_recognizer.dir/build: /home/odroid/catkin_ws/devel/lib/opencv_detector/face_recognizer
.PHONY : opencv_detector/CMakeFiles/face_recognizer.dir/build

opencv_detector/CMakeFiles/face_recognizer.dir/requires: opencv_detector/CMakeFiles/face_recognizer.dir/src/face_recognizer.cpp.o.requires
.PHONY : opencv_detector/CMakeFiles/face_recognizer.dir/requires

opencv_detector/CMakeFiles/face_recognizer.dir/clean:
	cd /home/odroid/catkin_ws/build/opencv_detector && $(CMAKE_COMMAND) -P CMakeFiles/face_recognizer.dir/cmake_clean.cmake
.PHONY : opencv_detector/CMakeFiles/face_recognizer.dir/clean

opencv_detector/CMakeFiles/face_recognizer.dir/depend:
	cd /home/odroid/catkin_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/odroid/catkin_ws/src /home/odroid/catkin_ws/src/opencv_detector /home/odroid/catkin_ws/build /home/odroid/catkin_ws/build/opencv_detector /home/odroid/catkin_ws/build/opencv_detector/CMakeFiles/face_recognizer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : opencv_detector/CMakeFiles/face_recognizer.dir/depend

