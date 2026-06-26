#pragma once

#include <string>
#include <string_view>
#include <vector>

bool is_digit(char c);
bool is_letter(char c);
bool is_operator(char c);
bool is_bracket(char c);

namespace token {

    enum Category {
        BRACKET,
        OPERATOR,
        NUMBER,
        IDENTIFIER
        // Support later
        // TYPE
        // SEMICOLON
        // LITERALS
    };

    struct Token {
        Category category;
        std::string_view inner;
    };

    std::vector<Token> tokenize(const std::string& input);

}
