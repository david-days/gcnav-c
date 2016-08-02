cmake_minimum_required(VERSION 3.5)
project(graphcut)

set (PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Set version numbers
set (GC_VERSION_MAJOR 1)
set (GC_VERSION_MINOR 0)

configure_file (
        "${PROJECT_INCLUDE_DIR}/GraphcutConfig.h.in"
        "${PROJECT_BINARY_DIR}/GraphcutConfig.h"
)

include_directories(${PROJECT_INCLUDE_DIR})

# add the binary tree to the search path for include files
# so that we will find GCNavConfig.h
include_directories("${PROJECT_BINARY_DIR}")

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall")

set(SOURCE_FILES
        ${PROJECT_INCLUDE_DIR}/graphcut.h
        ${PROJECT_INCLUDE_DIR}/graphstructs.h
        ${PROJECT_SOURCE_DIR}/graphcut.c
        ${PROJECT_SOURCE_DIR}/utils/mathutils.c
        ${PROJECT_INCLUDE_DIR}/utils/mathutils.h
        ${PROJECT_SOURCE_DIR}/utils/edgeutils.c
        ${PROJECT_INCLUDE_DIR}/utils/edgeutils.h
        ${PROJECT_SOURCE_DIR}/ug/ungraph.c 
        ${PROJECT_INCLUDE_DIR}/ug/ungraph.h
        ${PROJECT_SOURCE_DIR}/structs/queue.c 
        ${PROJECT_INCLUDE_DIR}/structs/queue.h
        ${PROJECT_SOURCE_DIR}/structs/stack.c 
        ${PROJECT_INCLUDE_DIR}/structs/stack.h
        ${PROJECT_SOURCE_DIR}/structs/unionfind.c 
        ${PROJECT_INCLUDE_DIR}/structs/unionfind.h
        ${PROJECT_SOURCE_DIR}/gmgt/graphmgt.c 
        ${PROJECT_INCLUDE_DIR}/gmgt/graphmgt.h
        ${PROJECT_SOURCE_DIR}/dg/digraph.c 
        ${PROJECT_INCLUDE_DIR}/dg/digraph.h
)


# Create shared library
add_library(graphcut SHARED ${SOURCE_FILES})

