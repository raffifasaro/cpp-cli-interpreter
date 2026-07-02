#include "eval_math.h"


namespace eval_math
{
    std::string evaluate(parser::treeNode& root_node)
    {
        if (root_node.element == "+")
        {
            return std::to_string(std::stoi(evaluate(*root_node.left)) + std::stoi(evaluate(*root_node.right)));
        }
        return root_node.element;
    }
}