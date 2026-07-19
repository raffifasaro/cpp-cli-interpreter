#pragma once

#include "parser/parser.h"
#include "common/variable.h"

#include <unordered_map>
#include <optional>

namespace eval_math
{
    std::optional<double> evaluate(parser::TreeNode& root_node, std::unordered_map<std::string, std::unique_ptr<variable::Variable>>& variables);
}