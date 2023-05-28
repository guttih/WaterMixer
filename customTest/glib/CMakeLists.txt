cmake_minimum_required(VERSION 3.12)
project(glib)

# Add the pid library
add_library(pid
    pid/PID_v1.cpp
    pid/PID_v1.h
)
# Add the PidController library
add_library(PidController
    PidController/src/PidController.cpp
    PidController/include/PidController.h
)

# Set include directories for PidController library
target_include_directories(PidController PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/PidController/include" "${CMAKE_CURRENT_SOURCE_DIR}/pid")


# Link the PidController library with the pid library
target_link_libraries(PidController PRIVATE pid)








