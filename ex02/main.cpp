#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error: argument not valid" << std::endl;
        return 1;
    }
    try
    {
        PmergeMe sort;
        sort.parse_and_sort(av);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}