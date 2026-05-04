#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    (void)av;
    BitcoinExchange btc;
    std::string line;

    if (ac != 2)
    {
        std::cout << "Argument not valid : ./btc <file>" << std::endl;
        return 0;
    }
    std::ifstream file("data.csv");
    if (!file.is_open())
    {
        std::cout << "File not opened" << std::endl;
        return 0;
    }
    while (getline(file, line))
    {
        float value = static_cast<float>(line[line.size() - 1]);
        line = line.substr(0, 10);
        btc.addstr(line, value);
    }
    btc.print();
    
    return 0;
}