#include "error.h"
#include <format>

void print_input_error(std::string err_line, int pos, int length)
{
    std::string err_msg(err_line.length(), ' ');

    for (size_t i = pos; i < pos + length; i++)
    {
        err_msg[i] = '^';
    }
    err_msg.append("\n");
    err_msg.append(std::format("Input error at index {}", pos));
    
    err_line.append("\n");
    std::cout << err_line;

    err_msg.append("\n");
    std::cout << err_msg;
}