#pragma once

#include <string>
#include <string_view>
#include <vector>

namespace token {

    enum Category {
        BRACKET,
        OPERATOR,
        VAR,
        NUMBER,
        CHAR,
        TYPE
    };

    struct Token {
        Category category;
        std::string_view inner;
    };

    std::vector<Token> tokenize(std::string input);

}
