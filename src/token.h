#pragma once

#include <string_view>

namespace token 
{

    enum Category 
    {
        BRACKET,
        OPERATOR,
        NUMBER,
        IDENTIFIER
        // Support later
        // TYPE
        // SEMICOLON
        // LITERALS
    };

    struct Token 
    {
        Category category;
        std::string_view inner;
    };

}