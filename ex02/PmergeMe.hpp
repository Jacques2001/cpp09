#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <climits>

class PmergeMe
{
    private :
        std::vector<int> _vec;
        std::deque<int> _deq;
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
    public :
        PmergeMe();
        ~PmergeMe();
        void parse(char **av);
};

#endif