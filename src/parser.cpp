#include "parser.h"

#include <iostream>

namespace parser 
{
    std::vector<parser::treeNode> parse(std::vector<token::Token> token_input)
    {
        std::vector<parser::treeNode> trees{};

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

namespace parse_math 
{
    parser::treeNode build_tree(std::vector<token::Token> token_input)
    {
        parser::treeNode root;

        if (token_input.front().inner == "(" && token_input.back().inner == ")")
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

        for (size_t i = 0; i < token_input.size(); i++)
        {
            token::Token current = token_input.at(i);

            if (current.category == token::L_BRACKET) scope++;
            
            if (current.category == token::R_BRACKET) scope--;

            if (scope == 0 && (current.inner == "+" || current.inner == "-"))
            {
                root.element = current.inner;
                root.left = std::make_unique<parser::treeNode>(parse_math::build_tree({token_input.begin(), token_input.begin() + i}));
                root.right = std::make_unique<parser::treeNode>(parse_math::build_tree({token_input.begin() + i + 1, token_input.end()}));
                return root;
            }
        }

        for (size_t i = 0; i < token_input.size(); i++)
        {
            token::Token current = token_input.at(i);

            if (current.category == token::L_BRACKET) scope++;
            
            if (current.category == token::R_BRACKET) scope--;
            
            if (scope == 0 && (current.inner == "*" || current.inner == "/" || current.inner == "%"))
            {
                root.element = current.inner;
                root.left = std::make_unique<parser::treeNode>(parse_math::build_tree({token_input.begin(), token_input.begin() + i}));
                root.right = std::make_unique<parser::treeNode>(parse_math::build_tree({token_input.begin() + i + 1, token_input.end()}));
                return root;
            }
        }
        root.element = token_input.back().inner;
        return root;
    }
}