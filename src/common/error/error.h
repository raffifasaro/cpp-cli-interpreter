#pragma once

#include <string>
#include <iostream>

namespace error
{
    void print_input_error(int pos, int length);
    void print_variable_error(std::string v_name);
}