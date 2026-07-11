#include "eval_math.h"

namespace eval_math
{
    double evaluate(parser::TreeNode& root_node, std::unordered_map<std::string, std::unique_ptr<variable::Variable>>& variables)
    {
        switch (root_node.element.inner[0])
        {
        case '+':
            return evaluate(*root_node.left, variables) + evaluate(*root_node.right, variables);
        case '-':
            return evaluate(*root_node.left, variables) - evaluate(*root_node.right, variables);
        case '*':
            return evaluate(*root_node.left, variables) * evaluate(*root_node.right, variables);
        case '/':
            return evaluate(*root_node.left, variables) / evaluate(*root_node.right, variables);
        case '%':
            return int(evaluate(*root_node.left, variables)) % int(evaluate(*root_node.right, variables));
        case '=':
        {
            if (root_node.left->element.category == token::IDENTIFIER && 
                (root_node.right->element.category == token::NUMBER || root_node.right->element.category == token::IDENTIFIER))
            {
                std::unique_ptr<variable::Variable> var = std::make_unique<variable::Variable>();
                var->name = root_node.left->element.inner;
                var->value = root_node.right->element;

                variables.emplace(var->name, std::move(var));
                return 0;
            }
        }
        default:
            return std::stod(std::string(root_node.element.inner));
        }
    }
}