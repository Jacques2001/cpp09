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

int Jacobsthal(int n)
{
    // base case
    if (n == 0)
        return 0;

    // base case
    if (n == 1)
        return 1;

    // recursive step.
    return Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2);
}

void PmergeMe::sort_vector(std::vector<int> &numbers)
{
    std::vector<std::pair<int, int> > pairs;
    std::vector<int> winners;
    bool odd = false;
    int last = 0;
    (void)last;

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
    if (v.size() % 2 != 0)
    {
        last = v.back();
        v.pop_back();
        odd = true;
    }
    sort_vector(winners);
  
    std::vector<int> main;
    std::vector<std::pair<int, int> > pend;
    for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
    {
        if (it->second == winners[0])
        {
            main.push_back(it->first);
            main.push_back(it->second);
            pairs.erase(it);
            break;
        }
    }

    for (size_t i = 1; i < winners.size(); i++)
    {
        for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
        {
            if (it->second == winners[i])
            {
                main.push_back(it->second);
                pend.push_back(std::make_pair(it->first, it->second));
                pairs.erase(it);
                break;
            }
        }
    }
    int i = 3;
    while (!pend.empty())
    {
        int x = Jacobsthal(i);
        while (x != Jacobsthal(i - 1))
        {
            // j'ai trouve le lower bound, il faut maintenant que compare tout ce qui se trouve avant ce lower bound
            std::lower_bound(main.begin(), std::find(main.begin(), main.end(), pend[x].second), pend[x].first);
            x--;
        }
        i++;
    }
    
    if (odd == true)
    {
        //inserer la derniere valeur dans le main
    }
    
    // for (size_t i = 0; i < pend.size() && ; i++)
    // {

    // }
    // inserer les pend dans main avec la suite de jacobsthal
    


    // derniere ligne
    // numbers = main;
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