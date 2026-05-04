#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <map>

class BitcoinExchange
{
    private :
        std::map<std::string, float> _map;
    public :
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();
        void addstr(std::string str, float value);
        void print();
};

#endif