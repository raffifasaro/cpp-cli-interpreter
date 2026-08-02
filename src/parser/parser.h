#pragma once

#include "lexer/lexer.h"
#include <optional>

#include <iostream>

namespace parser
{
    struct TreeNode 
    {
        token::Token element;

        std::unique_ptr<TreeNode> left;
        std::unique_ptr<TreeNode> right;
    };

    std::vector<parser::TreeNode> parse(std::vector<token::Token> token_input);
}

namespace parse_math 
{
    std::optional<parser::TreeNode> build_tree(std::vector<token::Token> token_input);
}