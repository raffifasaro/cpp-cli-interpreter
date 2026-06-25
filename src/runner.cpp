#include "runner.h"
#include "parse_math.h"
#include "lexer.h"

#include <iostream>

void run_interpreter() 
{
    std::cout << "Interpreter running\n";

    std::string input;

    while(true) 
    {

        std::cout << ">>> ";

        if(!std::getline(std::cin, input) || input == "exit") 
        {
            break;
        }

        std::cout << interpret(input);

        std::cout << "\n";
    }
}

std::string interpret(std::string argument) 
{
    return parse_math(argument);
}