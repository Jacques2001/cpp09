#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <iomanip>
#include <stack>
#include <sstream>

class RPN
{
    private :
        std::stack<std::string> _stk;
    public :
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();
        void parse(std::string input);
        void execute();
};


#endif