#include "evaluator.h"

namespace evaluator 
{
    std::string evaluate(parser::TreeNode& root_node)
    {
        return eval_math::evaluate(root_node);
    }
}