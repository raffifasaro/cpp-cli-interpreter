#include "runner.h"
#include "lexer.h"
#include "parser.h"
#include "evaluator.h"

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

        std::cout << interpret(input) << "\n";

    }
}

std::string interpret(std::string argument) 
{
    std::vector<token::Token> tokens = lexer::tokenize(argument);
    std::vector<parser::treeNode> ast_roots = parser::parse(tokens);

    std::string evaluated{};

    for (auto &&root : ast_roots)
    {
        evaluated.append(evaluator::evaluate(root));
        evaluated.append("\n");
    }

    return evaluated;
}