#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    BitcoinExchange btc;
    try {
        btc.loadDatabase("data.csv");
        btc.processInput(argv[1]);
    }
    catch (const BitcoinExchange::FileError& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    catch (const BitcoinExchange::DateError& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    catch (const BitcoinExchange::ValueError& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
