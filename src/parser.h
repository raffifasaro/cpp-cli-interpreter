#pragma once

#include "lexer.h"

#include <iostream>

namespace parser
{
    struct TreeNode 
    {
        std::string element;

        std::unique_ptr<TreeNode> left;
        std::unique_ptr<TreeNode> right;
    };

    std::vector<parser::TreeNode> parse(std::vector<token::Token> token_input);
}

namespace parse_math 
{
    parser::TreeNode build_tree(std::vector<token::Token> token_input);
}