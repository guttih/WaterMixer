cmake_minimum_required(VERSION 3.12)
project(glibTester)

# Add the executable for the console application
# add_executable(glibTester WIN32 main.cpp)
add_executable(glibTester main.cpp)

# Link the PidController library
target_link_libraries(glibTester PRIVATE PidController)

# Include directories for PidController library
target_include_directories(glibTester PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../glib/PidController/include")
