#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

template <typename T>
void PmergeMe::print(const T &c, const std::string &input)
{
    if (input == "begin")
        std::cout << "Before: ";
    else if (input == "end")
        std::cout << "After:  ";
    for (size_t i = 0; i < c.size(); ++i)
        std::cout << c[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::sort_vector(std::vector<int> &numbers)
{
    std::vector<std::pair<int, int> > pairs;
    std::vector<int> winners;
    if (numbers.size() <= 1)
        return ;
    for (size_t i = 0; i < numbers.size() - 1; i += 2)
    {
        int nb1 = numbers[i];
        int nb2 = numbers[i + 1];
        if (nb2 < nb1)
            pairs.push_back(std::make_pair(nb2, nb1));
        else
            pairs.push_back(std::make_pair(nb1, nb2));
        winners.push_back(pairs.back().second);
    }
    // if (v.size() % 2 != 0)
    //     int last = v.back();
    sort_vector(winners);
    

    // push dans main
    // push le reste dans pend
    // inserer les pend dans main avec la suite de jacobsthal
    


    // derniere ligne
    numbers = main;
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
    // print(v, "begin");
    sort_vector(v);
}