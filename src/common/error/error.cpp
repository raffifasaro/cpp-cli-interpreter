#include "error.h"
#include <format>

namespace error
{
    void print_input_error(std::string err_line, int pos, int length)
    {
        std::string err_msg(err_line.length(), ' ');

        for (size_t i = pos; i < pos + length; i++)
        {
            err_msg[i] = '^';
        }
        err_msg.append("\n");
        err_msg.append(std::format("Input error at index {}", pos));
        
        std::cout << err_line << "\n";

        std::cout << err_msg << "\n";
    }

    void print_variable_error(std::string v_name)
    {
        std::string err_msg{};
        err_msg.append(std::format("Variable {} not found", v_name));

        std::cout << err_msg << "\n";
    }
}