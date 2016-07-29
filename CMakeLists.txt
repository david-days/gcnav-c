cmake_minimum_required(VERSION 3.5)
project(gcnav_c)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall")

set(SOURCE_FILES bordercut.h graphstructs.h bordercut.c utils/mathutils.c utils/mathutils.h utils/edgeutils.c utils/edgeutils.h ug/ungraph.c ug/ungraph.h structs/queue.c structs/queue.h structs/stack.c structs/stack.h structs/unionfind.c structs/unionfind.h gmgt/graphmgt.c gmgt/graphmgt.h dg/digraph.c dg/digraph.h)
add_executable(gcnav_c ${SOURCE_FILES} bordercut.c)