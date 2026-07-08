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

bool is_right_bracket(char c)
{
    return c == ')' || c == '}' || c == ']';
}

bool is_left_bracket(char c)
{
    return c == '(' || c == '{' || c == '[';
}

bool is_operator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '=' || c == '%';
}

bool is_semicolon(char c)
{
    return c == ';';
}

void add_single_token(std::vector<token::Token>& tokens, const std::string& input, token::Category category, size_t start, int length) 
{
    token::Token token;
    token.category = category;
    token.inner = std::string_view(input.data() + start, length);
    tokens.push_back(token);
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

            if (is_right_bracket(current_char))
            {
                add_single_token(tokens, input, token::R_BRACKET, i, 1);
            } 
            else if (is_left_bracket(current_char))
            {
                add_single_token(tokens, input, token::L_BRACKET, i, 1);
            }
            else if (is_operator(current_char))
            {
                add_single_token(tokens, input, token::OPERATOR, i, 1);
            }
            else if (is_semicolon(current_char))
            {
                add_single_token(tokens, input, token::SEMICOLON, i, 1);
            }
            else if (is_digit(current_char))
            {
                size_t start = i;

                while (i < input.size() && is_digit(input.at(i)))
                {
                    ++i;
                }

                add_single_token(tokens, input, token::NUMBER, start, i - start);

                --i;
            }
            else if (is_letter(current_char))
            {
                size_t start = i;

                while (i < input.size() && is_letter(input.at(i)))
                {
                    ++i;
                }

                add_single_token(tokens, input, token::IDENTIFIER, start, i - start);

                --i;
            }
        }
        return tokens;
    }
}
