#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    (void)other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    (void)other;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::addstr(std::string str, float value)
{
    _map.insert(std::make_pair(str, value));
}

void BitcoinExchange::print()
{
    float rate = _map["2018-09-13"];
    std::cout << rate << std::endl;
}