#include "parse_math.h"

#include <iostream>

namespace parse_math
{

    struct treeNode
    {
        std::string_view element;

        std::unique_ptr<treeNode> left;
        std::unique_ptr<treeNode> right;
    };

    std::string parse_math(std::vector<token::Token> token_input) 
    {
        return "";
    }

    parse_math::treeNode build_tree(std::vector<token::Token> token_input)
    {
        parse_math::treeNode root;

        for (size_t i = 0; i < token_input.size(); i++)
        {
            token::Token current = token_input.at(i);

            if (current.inner == "(")
            {
                while (token_input.at(i).inner != ")" && i < token_input.size())
                {
                    i++;
                }
            }
            else if (current.inner == "*" || current.inner == "/")
            {
                root.element = current.inner;
                root.left = std::make_unique<parse_math::treeNode>(parse_math::build_tree({token_input.begin(), token_input.begin() + i}));
                root.right = std::make_unique<parse_math::treeNode>(parse_math::build_tree({token_input.begin() + i + 1, token_input.end()}));
            }
        }
        
        
        return root;
    }
}