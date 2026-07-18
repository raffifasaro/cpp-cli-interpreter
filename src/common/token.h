#pragma once

#include <string_view>

namespace token 
{

    enum Category 
    {
        R_BRACKET,
        L_BRACKET,
        OPERATOR,
        NUMBER,
        IDENTIFIER,
        SEMICOLON
        // Support TODO:
        // LITERALS
    };

    struct Token 
    {
        Category category;
        std::string_view inner;
    };

}