#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

void PmergeMe::parse(char **av)
{
    for (int i = 1; av[i]; i++)
    {
        char *end;
        long int value = std::strtol(av[i], &end, 10);
        if (value < 0)
            throw std::runtime_error("Error: negative value");
        if (value > INT_MAX)
            throw std::runtime_error("Error: greater than int max");
        if (*end)
            throw std::runtime_error("Error: format invalid");
        _vec.push_back(value);
        _deq.push_back(value);
    }
}