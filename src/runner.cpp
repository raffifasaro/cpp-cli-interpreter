#include "runner.h"
#include "lexer.h"
#include "parser.h"
#include "evaluator.h"

#include <iostream>

std::unordered_map<std::string, std::unique_ptr<variable::Variable>> variables{};

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
    std::vector<parser::TreeNode> ast_roots = parser::parse(tokens);

    std::string evaluated{};

    for (size_t i = 0; i < ast_roots.size(); i++)
    {
        evaluated.append(evaluator::evaluate(ast_roots.at(i), variables));
        if (i < ast_roots.size() - 1)
        {
            evaluated.append("\n");
        }
    }

    return evaluated;
}