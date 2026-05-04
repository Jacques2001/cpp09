#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    (void)av;
    BitcoinExchange btc;
    std::string line;

    if (ac != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return 0;
    }
    try
    {
        btc.process_input(av[1]);
        btc.save_data();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    return 0;
}