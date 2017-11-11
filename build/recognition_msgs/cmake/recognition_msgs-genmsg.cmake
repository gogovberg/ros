# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "recognition_msgs: 1 messages, 0 services")

set(MSG_I_FLAGS "-Irecognition_msgs:/home/odroid/catkin_ws/src/recognition_msgs/msg;-Isensor_msgs:/opt/ros/indigo/share/sensor_msgs/cmake/../msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/indigo/share/geometry_msgs/cmake/../msg;-Ivisualization_msgs:/opt/ros/indigo/share/visualization_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(recognition_msgs_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/odroid/catkin_ws/src/recognition_msgs/msg/Recognition.msg" NAME_WE)
add_custom_target(_recognition_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "recognition_msgs" "/home/odroid/catkin_ws/src/recognition_msgs/msg/Recognition.msg" ""
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(recognition_msgs
  "/home/odroid/catkin_ws/src/recognition_msgs/msg/Recognition.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/recognition_msgs
)

### Generating Services

### Generating Module File
_generate_module_cpp(recognition_msgs
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/recognition_msgs
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(recognition_msgs_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(recognition_msgs_generate_messages recognition_msgs_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/odroid/catkin_ws/src/recognition_msgs/msg/Recognition.msg" NAME_WE)
add_dependencies(recognition_msgs_generate_messages_cpp _recognition_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(recognition_msgs_gencpp)
add_dependencies(recognition_msgs_gencpp recognition_msgs_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS recognition_msgs_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(recognition_msgs
  "/home/odroid/catkin_ws/src/recognition_msgs/msg/Recognition.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/recognition_msgs
)

### Generating Services

### Generating Module File
_generate_module_lisp(recognition_msgs
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/recognition_msgs
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(recognition_msgs_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(recognition_msgs_generate_messages recognition_msgs_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/odroid/catkin_ws/src/recognition_msgs/msg/Recognition.msg" NAME_WE)
add_dependencies(recognition_msgs_generate_messages_lisp _recognition_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(recognition_msgs_genlisp)
add_dependencies(recognition_msgs_genlisp recognition_msgs_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS recognition_msgs_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(recognition_msgs
  "/home/odroid/catkin_ws/src/recognition_msgs/msg/Recognition.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/recognition_msgs
)

### Generating Services

### Generating Module File
_generate_module_py(recognition_msgs
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/recognition_msgs
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(recognition_msgs_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(recognition_msgs_generate_messages recognition_msgs_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/odroid/catkin_ws/src/recognition_msgs/msg/Recognition.msg" NAME_WE)
add_dependencies(recognition_msgs_generate_messages_py _recognition_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(recognition_msgs_genpy)
add_dependencies(recognition_msgs_genpy recognition_msgs_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS recognition_msgs_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/recognition_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/recognition_msgs
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET sensor_msgs_generate_messages_cpp)
  add_dependencies(recognition_msgs_generate_messages_cpp sensor_msgs_generate_messages_cpp)
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(recognition_msgs_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(recognition_msgs_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()
if(TARGET visualization_msgs_generate_messages_cpp)
  add_dependencies(recognition_msgs_generate_messages_cpp visualization_msgs_generate_messages_cpp)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/recognition_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/recognition_msgs
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET sensor_msgs_generate_messages_lisp)
  add_dependencies(recognition_msgs_generate_messages_lisp sensor_msgs_generate_messages_lisp)
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(recognition_msgs_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(recognition_msgs_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()
if(TARGET visualization_msgs_generate_messages_lisp)
  add_dependencies(recognition_msgs_generate_messages_lisp visualization_msgs_generate_messages_lisp)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/recognition_msgs)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/recognition_msgs\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/recognition_msgs
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET sensor_msgs_generate_messages_py)
  add_dependencies(recognition_msgs_generate_messages_py sensor_msgs_generate_messages_py)
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(recognition_msgs_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(recognition_msgs_generate_messages_py geometry_msgs_generate_messages_py)
endif()
if(TARGET visualization_msgs_generate_messages_py)
  add_dependencies(recognition_msgs_generate_messages_py visualization_msgs_generate_messages_py)
endif()
