# Testing PID Controller

Custom tests for different components of the WaterMixer project.
These project do not use the arduino library and do not need a micro controller.
They are built with cmake which usually uses GCC to build.

## Building

Commands to perform from the directory this README.md resides:
 - on linux terminal or
 - on windows in a git bash console


### First build

To be able to build this project for the first time, give one of the following commands:
- Building by selecting the default build environment
  - `mkdir build; cd build && cmake .. && cmake --build .`
- Building in windows with MinGW:
  - `mkdir build; cd build &&  cmake -G "MinGW Makefiles" .. && cmake --build .`

### Normal build

After first successful build you only need to give the following command from the **customTest/build** directory.
```shell
cmake --build .
```

