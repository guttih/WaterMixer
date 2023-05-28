cmake_minimum_required(VERSION 3.12)
project(PidController)


message(STATUS "------------------------------------------------------")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "------------------------------------------------------")


# Set C++ version
set(CMAKE_CXX_STANDARD 11)

# Add library target
add_library(PidController SHARED 
    src/PidController.cpp
    include/PidController.h
)


# Include directory
target_include_directories(PidController PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}/include 
)

target_link_libraries(PidController PUBLIC pid)

# Link with pid library

# Install rules
install(TARGETS PidController
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib
RUNTIME DESTINATION bin)
install(FILES PidController.h DESTINATION include)  # Install header file to the special include folder
