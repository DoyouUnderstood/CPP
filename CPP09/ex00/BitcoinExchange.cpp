#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

void BitcoinExchange::loadRates(const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open file.");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date;
        std::string rateStr;

        if (!std::getline(ss, date, ',') || !std::getline(ss, rateStr)) {
            continue;
        }

        try {
            double rate = std::stod(rateStr);
            exchangeRates[date] = rate;
        } catch (...) {
            continue;
        }
    }
}

double BitcoinExchange::getRateForDate(const std::string& date) const {
    auto it = exchangeRates.lower_bound(date);
    if (it == exchangeRates.end() || it->first > date) {
        if (it == exchangeRates.begin()) {
            throw std::runtime_error("Error: no valid rate for date.");
        }
        --it;
    }
    return it->second;
}