#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: argument not valid" << std::endl;
        return 1;
    }
    try
    {
        std::string input(av[1]);
        RPN pol;
        pol.parse_and_execute(input);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}