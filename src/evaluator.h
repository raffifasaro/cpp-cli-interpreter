#pragma once

#include "eval_math.h"

#include <unordered_map>

namespace evaluator 
{
    std::string evaluate(parser::TreeNode& root_node, std::unordered_map<std::string*, std::unique_ptr<variable::Variable>>& variables);
}