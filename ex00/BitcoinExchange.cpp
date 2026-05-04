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

void parse_date(std::string date)
{
    // int year = std::atoi(date.substr(0, date.find('-')).c_str());
    int month = std::atoi(date.substr(date.find('-'), date.find('-')).c_str());
    std::cout << month << std::endl;
}

void BitcoinExchange::process_input(char *av)
{
    std::string line;
    std::ifstream file(av);

    if (!file.is_open())
        throw std::runtime_error("Error: file not found");
    getline(file, line);
    while (getline(file, line))
    {
        if (line.empty())
            throw std::runtime_error("Error: line empty");
        parse_date(line.substr(0, 10));
    }
}

void BitcoinExchange::save_data()
{
    std::string line;
    std::ifstream file("data.csv");
    if (!file.is_open())
        throw std::runtime_error("Error: data not found");
    getline(file, line);
    while (getline(file, line))
    {
        if (line.empty())
            throw std::runtime_error("Error: line empty");
        std::string date = line.substr(0, 10);
        std::string bef_conv = line.substr(11);
        double value = std::strtod(bef_conv.c_str(), NULL);
        _map.insert(std::make_pair(date, value));
    }
}