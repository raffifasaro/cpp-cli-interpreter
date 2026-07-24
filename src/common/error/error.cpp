#include "error.h"
#include <format>

namespace error
{
    void print_input_error(int pos, int length)
    {
        int pos_aligned = pos + 4;

        std::string err_msg(pos_aligned + length, ' ');

        for (size_t i = pos_aligned; i < pos_aligned + length; i++)
        {
            err_msg[i] = '^';
        }
        err_msg.append("\n");
        err_msg.append(std::format("Input error at index {}", pos));

        std::cout << err_msg << "\n";
    }

    void print_variable_error(std::string v_name)
    {
        std::string err_msg{};
        err_msg.append(std::format("Variable {} not found", v_name));

        std::cout << err_msg << "\n";
    }
}