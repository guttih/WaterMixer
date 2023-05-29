cmake_minimum_required(VERSION 3.10)
project(PID_Simulator)

set(CMAKE_CXX_STANDARD 11)

add_executable(PID_Simulator main.cpp)

target_link_libraries(PID_Simulator)