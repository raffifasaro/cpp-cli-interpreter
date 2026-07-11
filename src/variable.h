#include "token.h"

#include <string>

namespace variable
{
    struct Variable
    {
        std::string name;
        token::Token value;
    };
}