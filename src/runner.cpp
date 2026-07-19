#include "runner.h"
#include "lexer/lexer.h"
#include "parser/parser.h"
#include "evaluator/evaluator.h"

#include <iostream>
#include <format>

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

        std::string output = interpret(input);

        if (!output.empty())
        {
            std::cout << output << "\n";
        }
    }
}

std::string interpret(std::string argument) 
{
    std::vector<token::Token> tokens = lexer::tokenize(argument);
    std::vector<parser::TreeNode> ast_roots = parser::parse(tokens);

    std::string evaluated{};

    for (size_t i = 0; i < ast_roots.size(); i++)
    {
        std::optional<std::string> eval_res = evaluator::evaluate(ast_roots.at(i), variables);

        if (!eval_res)
        {
            //TODO add handling for var write nullopt return
            //evaluated.append(std::format("Error for expression {}, see error message above for more information", i));
        }
        else
        {
            evaluated.append(*eval_res);
        }

        if (i < ast_roots.size() - 1)
        {
            evaluated.append("\n");
        }
    }

    return evaluated;
}