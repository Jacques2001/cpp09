#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

template <typename T>
void PmergeMe::print(T c, std::string input)
{
    if (input == "begin")
        std::cout << "Before: ";
    else if (input == "end")
        std::cout << "After:  ";
    for (int i = 0; c[i]; i++)
        std::cout << c[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::sort_vector()
{
    std::vector<std::pair<int, int> > p;
    for (int i = 0; v[i]; i += 2)
    {
        int nb1 = v[i];
        int nb2 = v[i + 1];
        if (nb2 < nb1)
            p.push_back
    }
}

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
        v.push_back(value);
        d.push_back(value);
    }
    print(v, "begin");
    sort_vector();
}