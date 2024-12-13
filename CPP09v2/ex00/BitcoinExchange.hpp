#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <stdexcept>

class BitcoinExchange {
private:
    std::map<std::string, float> _database;

    // Date validation helpers
    bool isValidDate(const std::string& date) const;
    bool isValidDateFormat(const std::string& date) const;
    bool isLeapYear(int year) const;
    int getDaysInMonth(int year, int month) const;
    bool isValidDateValues(int year, int month, int day) const;
    
    // Value validation helpers
    bool isValidValue(const float value) const;
    bool parseValue(const std::string& str, float& value) const;
    
    // Database helpers
    std::string findClosestDate(const std::string& date) const;
    bool parseDatabaseLine(const std::string& line, std::string& date, float& value) const;
    bool parseInputLine(const std::string& line, std::string& date, float& value) const;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    ~BitcoinExchange();
    BitcoinExchange& operator=(const BitcoinExchange& other);

    void loadDatabase(const std::string& filename);
    void processInput(const std::string& filename);
    float getExchangeRate(const std::string& date) const;

    // Exception classes
    class FileError : public std::runtime_error {
        public:
            FileError(const std::string& msg) : std::runtime_error(msg) {}
    };
    
    class DateError : public std::runtime_error {
        public:
            DateError(const std::string& msg) : std::runtime_error(msg) {}
    };
    
    class ValueError : public std::runtime_error {
        public:
            ValueError(const std::string& msg) : std::runtime_error(msg) {}
    };
};

#endif
