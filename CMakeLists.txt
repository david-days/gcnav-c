cmake_minimum_required(VERSION 3.5)
project(gcnav_c)

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

set(SOURCE_FILES bordercut.h graphstructs.h bordercut.c utils/mathutils.c utils/mathutils.h utils/edgeutils.c utils/edgeutils.h ug/ungraph.c ug/ungraph.h structs/queue.c structs/queue.h structs/stack.c structs/stack.h structs/unionfind.c structs/unionfind.h gmgt/graphmgt.c gmgt/graphmgt.h dg/digraph.c dg/digraph.h)


# Create shared library
add_library(bordercut SHARED ${SOURCE_FILES})

# Installation settings
install(TARGETS bordercut DESTINATION lib)
install(FILES bordercut.h graphstructs.h DESTINATION include)

# Create installers for binary and source
# build a CPack driven installer package
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE
        "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${GCNAV_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${GCNAV_VERSION_MINOR}")
include (CPack)