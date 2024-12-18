#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <stdexcept>

class BitcoinExchange {
private:
    std::map<std::string, double> exchangeRates;

public:
    void loadRates(const std::string& fileName);
    double getRateForDate(const std::string& date) const;
};

#endif