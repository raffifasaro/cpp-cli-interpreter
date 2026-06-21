#include "runner.h"
#include <iostream>
#include <string>

void runInterpreter() {
    std::cout << "Interpreter running\n";

    std::string input;

    while(true) {

        std::cout << ">>> ";

        if(!std::getline(std::cin, input) || input == "exit") {
            break;
        }

        std::cout << "test " << input;

        std::cout << "\n";
    }
}