#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

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

bool BitcoinExchange::check_format(std::string input)
{
    if (input.size() < 14)
        return 1;
    for (size_t i = 0; i < 4; ++i)
        if (!std::isdigit(input[i]))
            return 1;
    if (input[4] != '-')
        return 1;
    if (!std::isdigit(input[5]) ||
        !std::isdigit(input[6]))
        return 1;
    if (input[7] != '-')
        return 1;
    if (!std::isdigit(input[8]) ||
        !std::isdigit(input[9]))
        return 1;
    if (input[10] != ' ' || input[11] != '|' || input[12] != ' ')
        return 1;
    for (size_t i = 13; i < input.size(); ++i)
    {
        char c = input[i];
        if (!std::isdigit(c) && c != '.' && c != '-' && c != '+')
            return 1;
    }
    return 0;
}

bool isInt(std::string input)
{
    const char *str = input.c_str();
    int i = 0;

    if (str[i] == '+' || str[i] == '-')
        i++;
    for (; str[i]; i++)
    {
        if (!std::isdigit(input[i]))
            return false;
    }
    return true;
}

bool isDouble(std::string input) 
{
    int i = 0;
    bool has_point = false;
    bool has_digit = false;

    if (input[i] == '+' || input[i] == '-')
        i++;
    for (; input[i]; i++)
    {
        if (input[i] == '.')
        {
            if (has_point)
                return false;
            has_point = true;
            continue;
        }
        else if (std::isdigit(input[i]))
        {
            has_digit = true;
            continue;
        }
        else
            return false;
    }
    return has_point && has_digit;
}

void BitcoinExchange::parse_input(std::string input)
{
    std::string date = input.substr(0, 10);
    if (check_format(input))
        throw std::runtime_error("Error: invalid format");
    int year = std::atoi(input.substr(0, 4).c_str());
    int month = std::atoi(input.substr(5, 2).c_str());
    int day = std::atoi(input.substr(8, 2).c_str());
    size_t pos = input.find('|');
    if (pos == std::string::npos)
        throw std::runtime_error("Error: '|' not found");
    if (!isInt(input.substr(pos + 2)) && !isDouble(input.substr(pos + 2)))
        throw std::runtime_error("Error: invalid format");
    double value = std::strtod(input.substr(pos + 1).c_str(), NULL);
    if (year < 2009 || year > 2026 || check_month_day(year, month, day) == 1)
        std::cerr << "Error: bad input => " << input << std::endl;
    else if (value < 0)
        std::cerr << "Error: not a positive number." << std::endl;
    else if (value > 1000)
        std::cerr << "Error: too large a number." << std::endl;
    else 
    {
        std::map<std::string, float>::iterator it = _map.find(date);
        if (it == _map.end())
        {
            it = _map.lower_bound(date);
            if (it == _map.begin())
            {
                std::cerr << "Error: no available data for date => " << date << std::endl;
                return;
            }
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
    if (line != "date | value")
        throw std::runtime_error("Error: first line format is wrong");
    while (getline(file, line))
    {
        if (line.empty())
            std::cout << std::endl;
        else if (line[0] == '#')
            std::cout << line << std::endl;
        else
        {
            try
            {
                parse_input(line);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
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
        std::string date = line.substr(0, 10);
        std::string bef_conv = line.substr(11);
        double value = std::strtod(bef_conv.c_str(), NULL);
        _map.insert(std::make_pair(date, value));
    }
}