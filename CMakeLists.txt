cmake_minimum_required(VERSION 3.1.2)
project(mrs_dummy4_package)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  nodelet
  std_msgs
  )

set(LIBRARIES
  MrsDummy5
  )

catkin_package(
  LIBRARIES ${LIBRARIES}
  CATKIN_DEPENDS roscpp nodelet std_msgs
  )

include_directories(include
  ${catkin_INCLUDE_DIRS}
  )

add_library(MrsDummy5
  src/dummy.cpp
)

## --------------------------------------------------------------
## |                           Install                          |
## --------------------------------------------------------------

install(TARGETS ${LIBRARIES}
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
  )

install(TARGETS ${EXECUTABLES}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
  )

install(DIRECTORY
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
  FILES_MATCHING PATTERN "*.xml"
  )
