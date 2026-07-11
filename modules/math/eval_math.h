#pragma once

#include "src/parser.h"
#include "src/variable.h"

#include <unordered_map>

namespace eval_math
{
    std::string evaluate(parser::TreeNode& root_node, std::unordered_map<std::string*, std::unique_ptr<variable::Variable>>& variables);
}