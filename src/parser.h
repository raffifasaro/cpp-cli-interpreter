#pragma once

#include "lexer.h"

#include <iostream>

namespace parser
{
    struct treeNode 
    {
        std::string element;

        std::unique_ptr<treeNode> left;
        std::unique_ptr<treeNode> right;
    };

    std::vector<parser::treeNode> parse(std::vector<token::Token> token_input);
}

namespace parse_math 
{
    parser::treeNode build_tree(std::vector<token::Token> token_input);
}