cmake_minimum_required(VERSION 3.5)
project(graphcut)

set (PROJECT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
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
        include/graphcut.h
        include/graphstructs.h
        src/graphcut.c
        src/utils/mathutils.c
        include/utils/mathutils.h
        src/utils/edgeutils.c
        include/utils/edgeutils.h
        src/ug/ungraph.c
        include/ug/ungraph.h
        src/structs/queue.c
        include/structs/queue.h
        src/structs/stack.c
        include/structs/stack.h
        src/structs/unionfind.c
        include/structs/unionfind.h
        src/gmgt/graphmgt.c
        include/gmgt/graphmgt.h
        src/dg/digraph.c
        include/dg/digraph.h
)


# Create shared library
add_library(graphcut SHARED ${SOURCE_FILES})

