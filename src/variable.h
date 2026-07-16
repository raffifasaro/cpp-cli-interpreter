#include "token.h"

#include <string>

namespace variable
{
    struct Variable
    {
        std::string name;
        std::string value;
        token::Category category;
    };
}