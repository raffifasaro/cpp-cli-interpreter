#include "evaluator.h"

namespace evaluator 
{
    std::optional<std::string> evaluate(parser::TreeNode& root_node, std::unordered_map<std::string, std::unique_ptr<variable::Variable>>& variables)
    {
        std::optional<double> eval_result = eval_math::evaluate(root_node, variables);

        if (!eval_result)
        {
            return std::nullopt;
        }
        else
        {
            return std::to_string(*eval_result);
        }
    }
}