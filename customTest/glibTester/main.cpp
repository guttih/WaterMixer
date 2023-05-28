// #include <windows.h> 
// #include<unistd.h>  
#include <chrono>
#include <iostream>
#include "PidController.h"

unsigned long  nowMs() {
    auto sysTime = std::chrono::system_clock::now();
    return (unsigned long)std::chrono::duration_cast<std::chrono::milliseconds>(sysTime.time_since_epoch()).count();
}

int main() {
    PidController pidController;  // Declare a new instance of PidController
    unsigned long x = nowMs();
    std::cout << "millis" << x << std::endl;  // Print "Hello, World!" to the console
    while (nowMs() < x + 1000) { continue;  }
    std::cout << "millis" << nowMs() << std::endl;  // Print "Hello, World!" to the console
    while (nowMs() < x + 3000) { continue;  }
    // // Call getSuggestedValue() and print the result
    std::cout << "Suggested val ue: " << pidController.getSuggestedValue() << std::endl;

    return 0;
}