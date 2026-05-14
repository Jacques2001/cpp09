#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    BitcoinExchange btc;
    std::string line;

    if (ac != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return 0;
    }
    try
    {
        btc.save_data();
        btc.process_input(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    } 
    return 0;
}