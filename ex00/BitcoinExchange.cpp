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

bool BitcoinExchange::isLeapYear(int year)
{
    if (year % 4 == 0)
        return 1;
    return 0;
}

bool BitcoinExchange::check_month_day(int year, int month, int day)
{
    if (month < 1 || month > 12)
        return 1;
    else if (day < 1)
        return 1;
    else if ((month == 1 || month == 3 || month == 5 || month == 7 ||
        month == 8 || month == 10 || month == 12) && day > 31)
        return 1;
    else if ((month == 4 || month == 6 || month == 9 || month == 11) &&
            day > 30)
        return 1;
    else if (month == 2 && !isLeapYear(year) && day > 28)
        return 1;
    else if (month == 2 && isLeapYear(year) && day > 29)
        return 1;
    else
        return 0;
}

void BitcoinExchange::parse_input(std::string input)
{
    std::string date = input.substr(0, 10);
    int year = std::atoi(input.substr(0, input.find('-')).c_str());
    int month = std::atoi(input.substr(input.find('-') + 1).c_str());
    int day = std::atoi(input.substr(input.rfind('-') + 1).c_str());
    double value = std::strtod(input.substr(input.find('|') + 1).c_str(), NULL);
    if (year < 2009 || year > 2026 || check_month_day(year, month, day) == 1)
        std::cout << "Error: bad input => " << input.substr(0, 10) << std::endl;
    else if (value < 0)
        std::cout << "Error: not a positive number." << std::endl;
    else if (value > 1000)
        std::cout << "Error: too large a number." << std::endl;
    else 
    {
        std::map<std::string, float>::iterator it = _map.find(date);       
        if (it == _map.end())
        {
            it = _map.lower_bound(date);
            --it;
        }
        std::cout << input.substr(0, 10) << " => " << value << " = ";
        std::cout << value * it->second << std::endl;
    }
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
        parse_input(line);
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