#include <iostream>
#include "PidController.h"

int main() {
    PidController pidController;  // Declare a new instance of PidController
    std::cout << "Hello, World3!" << std::endl;  // Print "Hello, World!" to the console
    // // Call getSuggestedValue() and print the result
    std::cout << "Suggested val ue: " << pidController.getSuggestedValue() << std::endl;

    return 0;
}