#include "evaluator.h"

namespace evaluator 
{
    std::string evaluate(parser::TreeNode& root_node, std::unordered_map<std::string, std::unique_ptr<variable::Variable>>& variables)
    {
        return eval_math::evaluate(root_node, variables);
    }
}