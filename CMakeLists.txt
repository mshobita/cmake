cmake_minimum_required(VERSION 3.22)
project(HELLOAPP)
set(SRC_FILES main.cpp src/calc.cpp)
# message(WARNING "Src File has ${SRC_FILES}")
# message(FATAL_ERROR "Src File has ${SRC_FILES}")

message("${MINGW}")

message(STATUS "Src File has ${SRC_FILES}")
add_executable(hellobinary ${SRC_FILES})
target_include_directories(hellobinary PUBLIC include/)