#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <cmath>
#include <limits>

class BitcoinExchange
{
    private :
        std::map<std::string, float> _map;
        

    public :
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();
        void save_data();
        void process_input(char *av);
};

#endif