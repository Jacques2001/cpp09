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
    if (numbers.size() % 2 != 0)
    {
        last = numbers.back();
        numbers.pop_back();
        odd = true;
    }
    sort_vector(winners);
  
    // push le premier perdant et le reste des gagnants dans le vector main
    // je declare une pair de pend pour pouvoir savoir quel perdant va avec quel gagnant
    std::vector<int> main;
    std::vector<std::pair<int, int> > pend;
    for (std::vector<std::pair<int, int> >::iterator it = 
        pairs.begin(); it != pairs.end(); it++)
    {
        if (it->second == winners[0])
        {
            main.push_back(it->first);
            main.push_back(it->second);
            pairs.erase(it);
            break;
        }
    }

    // push tous les perdant dans le vector pend
    for (size_t i = 1; i < winners.size(); i++)
    {
        for (std::vector<std::pair<int, int> >::iterator it = 
            pairs.begin(); it != pairs.end(); it++)
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

    // suite Jacobsthal
    int i = 3;
    size_t inserted = 0;
    while (inserted < pend.size())
    {
        int x = std::min(Jacobsthal(i), static_cast<int>(pend.size() + 1));
        while (x > Jacobsthal(i - 1))
        {
            std::vector<int>::iterator it = 
            std::lower_bound(main.begin(), 
            std::find(main.begin(), main.end(), 
            pend[x - 2].second), pend[x - 2].first);
            main.insert(it, pend[x - 2].first);
            inserted++;
            x--;
        }
        i++;
    }
    
    // traitement du cas special
    if (odd == true)
    {
        std::vector<int>::iterator it = 
        std::lower_bound(main.begin(), main.end(), last);
        main.insert(it, last);
    }

    numbers = main;
}

void PmergeMe::sort_deque(std::deque<int> &numbers)
{
    std::deque<std::pair<int, int> > pairs;
    std::deque<int> winners;
    bool odd = false;
    int last = 0;

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
    if (numbers.size() % 2 != 0)
    {
        last = numbers.back();
        numbers.pop_back();
        odd = true;
    }
    sort_deque(winners);
  
    // push le premier perdant et le reste des gagnants dans le vector main
    // je declare une pair de pend pour pouvoir savoir quel perdant va avec quel gagnant
    std::deque<int> main;
    std::deque<std::pair<int, int> > pend;
    for (std::deque<std::pair<int, int> >::iterator it = 
        pairs.begin(); it != pairs.end(); it++)
    {
        if (it->second == winners[0])
        {
            main.push_back(it->first);
            main.push_back(it->second);
            pairs.erase(it);
            break;
        }
    }

    // push tous les perdant dans le vector pend
    for (size_t i = 1; i < winners.size(); i++)
    {
        for (std::deque<std::pair<int, int> >::iterator it = 
            pairs.begin(); it != pairs.end(); it++)
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

    // suite Jacobsthal
    int i = 3;
    size_t inserted = 0;
    while (inserted < pend.size())
    {
        int x = std::min(Jacobsthal(i), static_cast<int>(pend.size() + 1));
        while (x > Jacobsthal(i - 1))
        {
            std::deque<int>::iterator it = 
            std::lower_bound(main.begin(), 
            std::find(main.begin(), main.end(), 
            pend[x - 2].second), pend[x - 2].first);
            main.insert(it, pend[x - 2].first);
            inserted++;
            x--;
        }
        i++;
    }
    
    // traitement du cas special
    if (odd == true)
    {
        std::deque<int>::iterator it = 
        std::lower_bound(main.begin(), main.end(), last);
        main.insert(it, last);
    }

    numbers = main;
}

void PmergeMe::parse_and_sort(char **av)
{
    struct timeval start, end;

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
    gettimeofday(&start, NULL);
    sort_vector(v);
    gettimeofday(&end, NULL);
    print(v, "end");
    long usec = end.tv_usec - start.tv_usec;
    std::cout << "Time to process a range of " << v.size()
              << " elements with std::vector : " 
              << usec << " us" << std::endl;

    struct timeval begin, after;
    gettimeofday(&begin, NULL);
    sort_deque(d);
    gettimeofday(&after, NULL);
    long sec = after.tv_usec - begin.tv_usec;
    std::cout << "Time to process a range of " << v.size()
              << " elements with std::vector : " 
              << sec << " us" << std::endl;
}

