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

void RPN::parse(std::string input)
{
    if (input.empty())
        throw (std::runtime_error("Error: empty"));
    for (int i = 0; input[i]; i++)
    {
        if (!std::isdigit(input[i]) && !has_token(input[i]) &&
            input[i] != ' ')
            throw (std::runtime_error("Error: invalid input"));
    }
    std::stringstream ss(input);
    std::string token;
    while (ss >> token) 
        _stk.push(token);
}

void RPN::execute()
{

}