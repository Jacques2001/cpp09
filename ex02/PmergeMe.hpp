#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <climits>
#include <sstream>
#include <ctime>
#include <sys/time.h>

class PmergeMe
{
    private :
        std::vector<int> v;
        std::deque<int> d;
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        template <typename T>
        void print(const T &c, const std::string &input);
        void sort_vector(std::vector<int> &numbers);
        void sort_deque(std::deque<int> &numbers);
    public :
        PmergeMe();
        ~PmergeMe();
        void parse_and_sort(char **av);
};

#endif