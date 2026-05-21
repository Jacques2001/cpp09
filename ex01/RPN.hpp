#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <iomanip>
#include <stack>
#include <sstream>
#include <algorithm>

class RPN
{
    private :
        std::stack<int> _stk;
    public :
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();
        void parse_and_execute(std::string input);
};


#endif