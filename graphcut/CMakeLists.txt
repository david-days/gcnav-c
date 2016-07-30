cmake_minimum_required(VERSION 3.5)
project(graphcut)

# Set version numbers
set (GC_VERSION_MAJOR 1)
set (GC_VERSION_MINOR 0)

configure_file (
        "${PROJECT_SOURCE_DIR}/GraphcutConfig.h.in"
        "${PROJECT_BINARY_DIR}/GraphcutConfig.h"
)

set (PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# add the binary tree to the search path for include files
# so that we will find GCNavConfig.h
include_directories("${PROJECT_BINARY_DIR}")

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall")

set(SOURCE_FILES
        ${PROJECT_SOURCE_DIR}/bordercut.h
        ${PROJECT_SOURCE_DIR}/graphstructs.h
        ${PROJECT_SOURCE_DIR}/bordercut.c
        ${PROJECT_SOURCE_DIR}/utils/mathutils.c
        ${PROJECT_SOURCE_DIR}/utils/mathutils.h
        ${PROJECT_SOURCE_DIR}/utils/edgeutils.c
        ${PROJECT_SOURCE_DIR}/utils/edgeutils.h
        ${PROJECT_SOURCE_DIR}/ug/ungraph.c 
        ${PROJECT_SOURCE_DIR}/ug/ungraph.h 
        ${PROJECT_SOURCE_DIR}/structs/queue.c 
        ${PROJECT_SOURCE_DIR}/structs/queue.h 
        ${PROJECT_SOURCE_DIR}/structs/stack.c 
        ${PROJECT_SOURCE_DIR}/structs/stack.h 
        ${PROJECT_SOURCE_DIR}/structs/unionfind.c 
        ${PROJECT_SOURCE_DIR}/structs/unionfind.h 
        ${PROJECT_SOURCE_DIR}/gmgt/graphmgt.c 
        ${PROJECT_SOURCE_DIR}/gmgt/graphmgt.h 
        ${PROJECT_SOURCE_DIR}/dg/digraph.c 
        ${PROJECT_SOURCE_DIR}/dg/digraph.h
)


# Create shared library
add_library(graphcut SHARED ${SOURCE_FILES})

# Installation settings
install(TARGETS graphcut DESTINATION lib)
install(FILES graphcut.h graphstructs.h DESTINATION include)

# Create installers for binary and source
# build a CPack driven installer package
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE
        "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${GC_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${GC_VERSION_MINOR}")
include (CPack)
