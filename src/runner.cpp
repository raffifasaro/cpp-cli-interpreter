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
    parser::treeNode ast_root = parse_math::build_tree(tokens);
    std::string evaluated = evaluator::evaluate(ast_root);

    return evaluated;
}