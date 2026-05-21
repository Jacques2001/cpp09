#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}

bool has_token(char c)
{
    if (c == '+' || c == '-' || c == '/' ||
        c == '*')
        return true;
    return false;
}


void RPN::parse_and_execute(std::string input)
{
    if (input.empty())
        throw (std::runtime_error("Error"));
    for (int i = 0; input[i]; i++)
    {
        if (!std::isdigit(input[i]) && !has_token(input[i]) &&
            input[i] != ' ')
            throw (std::runtime_error("Error"));
    }
    std::stringstream ss(input);
    std::string token;
    while (ss >> token) 
    {
        if (token >= "0" && token <= "9" && token.size() == 1)
            _stk.push(std::atoi(token.c_str()));
        else if (token == "-" || token == "*" ||
            token == "/" || token == "+")
        {
            if (_stk.size() < 2)
                throw std::runtime_error("Error");
            int first = _stk.top();
            _stk.pop();
            int second = _stk.top();
            _stk.pop();
            if (token == "-")
                _stk.push(second - first);
            else if (token == "+")
                _stk.push(second + first);
            else if (token == "*")
                _stk.push(second * first);
            else if (token == "/")
            {
                if (first == 0)
                    throw std::runtime_error("Error");
                _stk.push(second / first);
            }
        }
        else
            throw std::runtime_error("Error");
    }
    if (_stk.size() == 1)
        std::cout << _stk.top() << std::endl;
    else
        throw std::runtime_error("Error");
}