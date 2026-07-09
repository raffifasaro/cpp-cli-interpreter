#include "parser.h"

#include <iostream>

namespace parser 
{
    std::vector<parser::TreeNode> parse(std::vector<token::Token> token_input)
    {
        std::vector<parser::TreeNode> trees{};

        std::vector<token::Token> sub_tokens{};

        for (size_t i = 0; i < token_input.size(); i++)
        {
            sub_tokens.push_back(token_input.at(i));

            if (token_input.at(i).category == token::SEMICOLON)
            {
                sub_tokens.pop_back();
                trees.push_back(parse_math::build_tree(sub_tokens));
                sub_tokens.clear();
            }
            else if (i == token_input.size() - 1)
            {
                trees.push_back(parse_math::build_tree(sub_tokens));
                sub_tokens.clear();
            }
        }
        return trees;
    }
}

void build_node(parser::TreeNode& root, std::string_view root_element, std::vector<token::Token>& token_input, int pos)
{
    root.element = root_element;
    root.left = std::make_unique<parser::TreeNode>(parse_math::build_tree({token_input.begin(), token_input.begin() + pos}));
    root.right = std::make_unique<parser::TreeNode>(parse_math::build_tree({token_input.begin() + pos + 1, token_input.end()}));
}

struct LastOp
{
    std::string_view* element;
    size_t pos;
};

namespace parse_math 
{
    parser::TreeNode build_tree(std::vector<token::Token> token_input)
    {
        parser::TreeNode root;

        if (token_input.front().category == token::L_BRACKET && token_input.back().category == token::R_BRACKET)
        {
            int b_scope = 0;
            bool wraps = true;

            std::vector<token::Token> b_removed = {token_input.begin() + 1, token_input.end() - 1};

            for (auto &&token : b_removed)
            {
                if (token.category == token::L_BRACKET) b_scope++;
                if (token.category == token::R_BRACKET) b_scope--;

                if (b_scope < 0) 
                { 
                    wraps = false; 
                    break; 
                }
            }

            if (wraps && b_scope == 0)
            {
                token_input.erase(token_input.begin());
                token_input.pop_back();
            } 
        }
        
        int scope = 0;
        LastOp last_operator{};

        for (size_t i = 0; i < token_input.size(); i++)
        {
            token::Token& current = token_input.at(i);

            if (current.category == token::L_BRACKET) scope++;
            
            if (current.category == token::R_BRACKET) scope--;

            if (scope == 0 && current.category == token::OPERATOR)
            {
                last_operator = {&current.inner, i};
            }
            
            if (scope == 0 && (current.inner == "+" || current.inner == "-"))
            {
                build_node(root, current.inner, token_input, i);
                return root;
            }
        }

        if (last_operator.element != nullptr)
        {
            build_node(root, *last_operator.element, token_input, last_operator.pos);
            return root;
        }
        root.element = token_input.back().inner;
        return root;
    }
}