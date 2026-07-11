#include "eval_math.h"


namespace eval_math
{
    std::string evaluate(parser::TreeNode& root_node, std::unordered_map<std::string*, std::unique_ptr<variable::Variable>>& variables)
    {
        if (root_node.element.inner == "+")
        {
            return std::to_string(std::stod(evaluate(*root_node.left, variables)) + std::stod(evaluate(*root_node.right, variables)));
        }
        else if (root_node.element.inner == "-")
        {
            return std::to_string(std::stod(evaluate(*root_node.left, variables)) - std::stod(evaluate(*root_node.right, variables)));
        }
        else if (root_node.element.inner == "*")
        {
            return std::to_string(std::stod(evaluate(*root_node.left, variables)) * std::stod(evaluate(*root_node.right, variables)));
        }
        else if (root_node.element.inner == "/")
        {
            return std::to_string(std::stod(evaluate(*root_node.left, variables)) / std::stod(evaluate(*root_node.right, variables)));
        }
        else if (root_node.element.inner == "%")
        {
            return std::to_string(std::stoi(evaluate(*root_node.left, variables)) % std::stoi(evaluate(*root_node.right, variables)));
        }
        else if (root_node.element.inner == "=")
        {
            if (root_node.left.get()->element.category == token::IDENTIFIER)
            {
                // TODO define logic for ident handling
            }
            
        }

        return std::string(root_node.element.inner);
    }
}