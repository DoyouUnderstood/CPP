#include "BitcoinExchange.hpp"
#include "InputValidator.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void processInputFile(const std::string& fileName, BitcoinExchange& exchange);
void processLine(const std::string& line, BitcoinExchange& exchange);

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    BitcoinExchange exchange;
    try {
        exchange.loadRates("cpp_09/data.csv");
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    processInputFile(argv[1], exchange);
    return 0;
}

void processInputFile(const std::string& fileName, BitcoinExchange& exchange) {
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        processLine(line, exchange);
    }
}

void processLine(const std::string& line, BitcoinExchange& exchange) {
    std::istringstream ss(line);
    std::string date;
    std::string valueStr;

    if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr)) {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }

    date = date.substr(0, date.find_last_not_of(' ') + 1);
    valueStr = valueStr.substr(valueStr.find_first_not_of(' '));

    double value;
    try {
        if (!InputValidator::isValidDate(date)) {
            throw std::runtime_error("Error: bad input => " + date);
        }
        if (!InputValidator::isValidValue(valueStr, value)) {
            throw std::runtime_error("Error: invalid value => " + valueStr);
        }

        double rate = exchange.getRateForDate(date);
        std::cout << date << " => " << value << " = " << value * rate << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
}
