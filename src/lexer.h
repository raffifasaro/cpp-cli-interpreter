#pragma once

#include <string>
#include <vector>

enum Token_cat {
    BRACKET,
    OPERATOR,
    VAR,
    NUMBER,
    CHAR,
    TYPE
};

struct token {
    Token_cat category;
    char token_char;
};

std::vector<token> tokenize_input(std::string input);