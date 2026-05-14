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
        bool isLeapYear(int year);
        bool check_month_day(int year, int month, int day);
        bool check_format(std::string input);
        void parse_input(std::string input);

    public :
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();
        void save_data();
        void process_input(char *av);
};

#endif