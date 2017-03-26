cmake_minimum_required(VERSION 3.5)
project(sensors)

set (PROJECT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Set version numbers
set (GCSENSORS_VERSION_MAJOR 1)
set (GCSENSORS_VERSION_MINOR 0)

include_directories(${PROJECT_INCLUDE_DIR})

# add the binary tree to the search path for include files
# so that we will find GCNavConfig.h
include_directories("${PROJECT_BINARY_DIR}")

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall")

set(SOURCE_FILES

)


# Create shared library
add_library(gcnav-sensors SHARED ${SOURCE_FILES})

