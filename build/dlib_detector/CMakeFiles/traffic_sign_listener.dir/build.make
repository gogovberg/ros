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
include dlib_detector/CMakeFiles/traffic_sign_listener.dir/depend.make

# Include the progress variables for this target.
include dlib_detector/CMakeFiles/traffic_sign_listener.dir/progress.make

# Include the compile flags for this target's objects.
include dlib_detector/CMakeFiles/traffic_sign_listener.dir/flags.make

dlib_detector/CMakeFiles/traffic_sign_listener.dir/src/traffic_sign_listener.cpp.o: dlib_detector/CMakeFiles/traffic_sign_listener.dir/flags.make
dlib_detector/CMakeFiles/traffic_sign_listener.dir/src/traffic_sign_listener.cpp.o: /home/odroid/catkin_ws/src/dlib_detector/src/traffic_sign_listener.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/odroid/catkin_ws/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object dlib_detector/CMakeFiles/traffic_sign_listener.dir/src/traffic_sign_listener.cpp.o"
	cd /home/odroid/catkin_ws/build/dlib_detector && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/traffic_sign_listener.dir/src/traffic_sign_listener.cpp.o -c /home/odroid/catkin_ws/src/dlib_detector/src/traffic_sign_listener.cpp

dlib_detector/CMakeFiles/traffic_sign_listener.dir/src/traffic_sign_listener.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traffic_sign_listener.dir/src/traffic_sign_listener.cpp.i"
	cd /home/odroid/catkin_ws/build/dlib_detector && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/odroid/catkin_ws/src/dlib_detector/src/traffic_sign_listener.cpp > CMakeFiles/traffic_sign_listener.dir/src/traffic_sign_listener.cpp.i

dlib_detector/CMakeFiles/traffic_sign_listener.dir/src/traffic_sign_listener.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traffic_sign_listener.dir/src/traffic_sign_listener.cpp.s"
	cd /home/odroid/catkin_ws/build/dlib_detector && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/odroid/catkin_ws/src/dlib_detector/src/traffic_sign_listener.cpp -o CMakeFiles/traffic_sign_listener.dir/src/traffic_sign_listener.cpp.s

dlib_detector/CMakeFiles/traffic_sign_listener.dir/src/traffic_sign_listener.cpp.o.requires:
.PHONY : dlib_detector/CMakeFiles/traffic_sign_listener.dir/src/traffic_sign_listener.cpp.o.requires

dlib_detector/CMakeFiles/traffic_sign_listener.dir/src/traffic_sign_listener.cpp.o.provides: dlib_detector/CMakeFiles/traffic_sign_listener.dir/src/traffic_sign_listener.cpp.o.requires
	$(MAKE) -f dlib_detector/CMakeFiles/traffic_sign_listener.dir/build.make dlib_detector/CMakeFiles/traffic_sign_listener.dir/src/traffic_sign_listener.cpp.o.provides.build
.PHONY : dlib_detector/CMakeFiles/traffic_sign_listener.dir/src/traffic_sign_listener.cpp.o.provides

dlib_detector/CMakeFiles/traffic_sign_listener.dir/src/traffic_sign_listener.cpp.o.provides.build: dlib_detector/CMakeFiles/traffic_sign_listener.dir/src/traffic_sign_listener.cpp.o

# Object files for target traffic_sign_listener
traffic_sign_listener_OBJECTS = \
"CMakeFiles/traffic_sign_listener.dir/src/traffic_sign_listener.cpp.o"

# External object files for target traffic_sign_listener
traffic_sign_listener_EXTERNAL_OBJECTS =

/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: dlib_detector/CMakeFiles/traffic_sign_listener.dir/src/traffic_sign_listener.cpp.o
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: dlib_detector/CMakeFiles/traffic_sign_listener.dir/build.make
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /opt/ros/indigo/lib/libnodeletlib.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /opt/ros/indigo/lib/libbondcpp.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/arm-linux-gnueabihf/libuuid.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /opt/ros/indigo/lib/libclass_loader.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/libPocoFoundation.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/arm-linux-gnueabihf/libdl.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /opt/ros/indigo/lib/libroslib.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /opt/ros/indigo/lib/librospack.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/arm-linux-gnueabihf/libpython2.7.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/arm-linux-gnueabihf/libboost_program_options.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/arm-linux-gnueabihf/libtinyxml.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /opt/ros/indigo/lib/libtf.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /opt/ros/indigo/lib/libtf2_ros.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /opt/ros/indigo/lib/libactionlib.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /opt/ros/indigo/lib/libmessage_filters.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /opt/ros/indigo/lib/libroscpp.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/arm-linux-gnueabihf/libboost_signals.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/arm-linux-gnueabihf/libboost_filesystem.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /opt/ros/indigo/lib/libxmlrpcpp.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /opt/ros/indigo/lib/libtf2.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /opt/ros/indigo/lib/libimage_geometry.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /opt/ros/indigo/lib/libcv_bridge.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/arm-linux-gnueabihf/libopencv_videostab.so.2.4.8
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/arm-linux-gnueabihf/libopencv_video.so.2.4.8
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/arm-linux-gnueabihf/libopencv_superres.so.2.4.8
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/arm-linux-gnueabihf/libopencv_stitching.so.2.4.8
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/arm-linux-gnueabihf/libopencv_photo.so.2.4.8
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/arm-linux-gnueabihf/libopencv_ocl.so.2.4.8
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/arm-linux-gnueabihf/libopencv_objdetect.so.2.4.8
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/arm-linux-gnueabihf/libopencv_ml.so.2.4.8
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/arm-linux-gnueabihf/libopencv_legacy.so.2.4.8
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/arm-linux-gnueabihf/libopencv_imgproc.so.2.4.8
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/arm-linux-gnueabihf/libopencv_highgui.so.2.4.8
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/arm-linux-gnueabihf/libopencv_gpu.so.2.4.8
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/arm-linux-gnueabihf/libopencv_flann.so.2.4.8
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/arm-linux-gnueabihf/libopencv_features2d.so.2.4.8
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/arm-linux-gnueabihf/libopencv_core.so.2.4.8
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/arm-linux-gnueabihf/libopencv_contrib.so.2.4.8
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/arm-linux-gnueabihf/libopencv_calib3d.so.2.4.8
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /opt/ros/indigo/lib/librosconsole.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /opt/ros/indigo/lib/librosconsole_log4cxx.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /opt/ros/indigo/lib/librosconsole_backend_interface.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/liblog4cxx.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/arm-linux-gnueabihf/libboost_regex.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /opt/ros/indigo/lib/libroscpp_serialization.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /opt/ros/indigo/lib/librostime.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/arm-linux-gnueabihf/libboost_date_time.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /opt/ros/indigo/lib/libcpp_common.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/arm-linux-gnueabihf/libboost_system.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/arm-linux-gnueabihf/libboost_thread.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/arm-linux-gnueabihf/libpthread.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/arm-linux-gnueabihf/libconsole_bridge.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /home/odroid/catkin_ws/devel/lib/libdlib.a
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/arm-linux-gnueabihf/libpthread.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/arm-linux-gnueabihf/libnsl.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/arm-linux-gnueabihf/libSM.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/arm-linux-gnueabihf/libICE.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/arm-linux-gnueabihf/libX11.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/arm-linux-gnueabihf/libXext.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/arm-linux-gnueabihf/libpng.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/arm-linux-gnueabihf/libjpeg.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: /usr/lib/arm-linux-gnueabihf/libsqlite3.so
/home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener: dlib_detector/CMakeFiles/traffic_sign_listener.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable /home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener"
	cd /home/odroid/catkin_ws/build/dlib_detector && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/traffic_sign_listener.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
dlib_detector/CMakeFiles/traffic_sign_listener.dir/build: /home/odroid/catkin_ws/devel/lib/dlib_detector/traffic_sign_listener
.PHONY : dlib_detector/CMakeFiles/traffic_sign_listener.dir/build

dlib_detector/CMakeFiles/traffic_sign_listener.dir/requires: dlib_detector/CMakeFiles/traffic_sign_listener.dir/src/traffic_sign_listener.cpp.o.requires
.PHONY : dlib_detector/CMakeFiles/traffic_sign_listener.dir/requires

dlib_detector/CMakeFiles/traffic_sign_listener.dir/clean:
	cd /home/odroid/catkin_ws/build/dlib_detector && $(CMAKE_COMMAND) -P CMakeFiles/traffic_sign_listener.dir/cmake_clean.cmake
.PHONY : dlib_detector/CMakeFiles/traffic_sign_listener.dir/clean

dlib_detector/CMakeFiles/traffic_sign_listener.dir/depend:
	cd /home/odroid/catkin_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/odroid/catkin_ws/src /home/odroid/catkin_ws/src/dlib_detector /home/odroid/catkin_ws/build /home/odroid/catkin_ws/build/dlib_detector /home/odroid/catkin_ws/build/dlib_detector/CMakeFiles/traffic_sign_listener.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : dlib_detector/CMakeFiles/traffic_sign_listener.dir/depend

