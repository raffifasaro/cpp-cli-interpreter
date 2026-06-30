#include "lexer.h"

#include <unordered_set>


bool is_letter(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

bool is_bracket(char c)
{
    return c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']';
}

bool is_operator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '=' || c == '%';
}

namespace lexer 
{

    std::vector<token::Token> tokenize(const std::string& input)
    {
        std::vector<token::Token> tokens;

        for (size_t i = 0; i < input.size(); i++)
        {
            char current_char = input.at(i);
            token::Token token;

            if (is_bracket(current_char))
            {
                token.category = token::BRACKET;
                token.inner = std::string_view(input.data() + i, 1);
                tokens.push_back(token);
            } 
            else if (is_digit(current_char))
            {
                size_t start = i;

                while (i < input.size() && is_digit(input.at(i)))
                {
                    ++i;
                }

                token.category = token::NUMBER;
                token.inner = std::string_view(input.data() + start, i - start);
                tokens.push_back(token);

                --i;
            }
            else if (is_letter(current_char))
            {
                size_t start = i;

                while (i < input.size() && is_letter(input.at(i)))
                {
                    ++i;
                }

                token.category = token::IDENTIFIER;
                token.inner = std::string_view(input.data() + start, i - start);
                tokens.push_back(token);

                --i;
            }
            else if (is_operator(current_char))
            {
                token.category = token::OPERATOR;
                token.inner = std::string_view(input.data() + i, 1);
                tokens.push_back(token);
            }
        }
        return tokens;
    }
}
