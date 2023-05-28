cmake_minimum_required(VERSION 3.12)
project(pid)

# Set C++ version
set(CMAKE_CXX_STANDARD 11)

# set(ARDUINO_CORE_DIR "/c/Users/gutti/AppData/Local/Arduino15/packages/arduino/hardware/avr/1.8.6/cores/arduino")

# Specify the Arduino board and core
# set(ARDUINO_BOARD "arduino:avr:uno")
# set(ARDUINO_CORE "arduino:avr")

# Add library target
add_library(pid SHARED PID_v1.cpp)


# Set library properties
set_target_properties(pid PROPERTIES
  VERSION 1.0.0
  SOVERSION 1
)

# Include directory
target_include_directories(pid PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
# PRIVATE "${ARDUINO_CORE_DIR}"
)

# target_link_libraries(pid PUBLIC Arduino)

# Install rules
install(TARGETS pid
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin)
install(FILES PID_v1.h DESTINATION include)