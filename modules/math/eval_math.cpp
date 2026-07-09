#include "eval_math.h"


namespace eval_math
{
    std::string evaluate(parser::TreeNode& root_node)
    {
        if (root_node.element == "+")
        {
            return std::to_string(std::stod(evaluate(*root_node.left)) + std::stod(evaluate(*root_node.right)));
        }
        else if (root_node.element == "-")
        {
            return std::to_string(std::stod(evaluate(*root_node.left)) - std::stod(evaluate(*root_node.right)));
        }
        else if (root_node.element == "*")
        {
            return std::to_string(std::stod(evaluate(*root_node.left)) * std::stod(evaluate(*root_node.right)));
        }
        else if (root_node.element == "/")
        {
            return std::to_string(std::stod(evaluate(*root_node.left)) / std::stod(evaluate(*root_node.right)));
        }
        else if (root_node.element == "%")
        {
            return std::to_string(std::stoi(evaluate(*root_node.left)) % std::stoi(evaluate(*root_node.right)));
        }
        return root_node.element;
    }
}