cmake_minimum_required(VERSION 3.5)
project(gcnav)

#Set version numbers
set (GCNAV_VERSION_MAJOR 1)
set (GCNAV_VERSION_MINOR 0)



configure_file (
        "${PROJECT_SOURCE_DIR}/GCNavConfig.h.in"
        "${PROJECT_BINARY_DIR}/GCNavConfig.h"
)

# add the binary tree to the search path for include files
# so that we will find GCNavConfig.h
include_directories("${PROJECT_BINARY_DIR}")

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall")

add_subdirectory(graphcut)
