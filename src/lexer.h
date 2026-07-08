#pragma once

#include "token.h"

#include <string>
#include <vector>

bool is_digit(char c);
bool is_letter(char c);
bool is_operator(char c);
bool is_right_bracket(char c);
bool is_left_bracket(char c);
bool is_semicolon(char c);

void add_single_token(std::vector<token::Token>& tokens, std::string& input, token::Category category, size_t start, int length);

namespace lexer 
{
    std::vector<token::Token> tokenize(const std::string& input);
}
