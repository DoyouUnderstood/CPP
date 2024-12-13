#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _database = other._database;
    }
    return *this;
}

bool BitcoinExchange::isLeapYear(int year) const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int BitcoinExchange::getDaysInMonth(int year, int month) const {
    static const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (month == 2 && isLeapYear(year))
        return 29;
    return daysInMonth[month];
}

bool BitcoinExchange::isValidDateFormat(const std::string& date) const {
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    for (size_t i = 0; i < date.length(); ++i) {
        if (i != 4 && i != 7 && !isdigit(date[i]))
            return false;
    }
    return true;
}

bool BitcoinExchange::isValidDateValues(int year, int month, int day) const {
    if (year < 2009 || year > 2024)  // Bitcoin n'existait pas avant 2009
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > getDaysInMonth(year, month))
        return false;
    return true;
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (!isValidDateFormat(date))
        return false;

    int year, month, day;
    std::istringstream iss(date);
    char dash;
    iss >> year >> dash >> month >> dash >> day;

    return isValidDateValues(year, month, day);
}

bool BitcoinExchange::parseValue(const std::string& str, float& value) const {
    char* end;
    value = strtof(str.c_str(), &end);
    return *end == '\0';
}

bool BitcoinExchange::isValidValue(const float value) const {
    return value >= 0 && value <= 1000;
}

std::string BitcoinExchange::findClosestDate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = _database.upper_bound(date);
    if (it == _database.begin())
        return it->first;
    --it;
    return it->first;
}

bool BitcoinExchange::parseDatabaseLine(const std::string& line, std::string& date, float& value) const {
    size_t comma = line.find(',');
    if (comma == std::string::npos)
        return false;

    date = line.substr(0, comma);
    return parseValue(line.substr(comma + 1), value);
}

bool BitcoinExchange::parseInputLine(const std::string& line, std::string& date, float& value) const {
    size_t separator = line.find(" | ");
    if (separator == std::string::npos)
        return false;

    date = line.substr(0, separator);
    return parseValue(line.substr(separator + 3), value);
}

void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw FileError("Error: could not open database file.");

    std::string line;
    std::getline(file, line); // Skip header

    while (std::getline(file, line)) {
        std::string date;
        float value;
        
        if (!parseDatabaseLine(line, date, value) || !isValidDate(date))
            continue;
            
        _database[date] = value;
    }
    
    if (_database.empty())
        throw FileError("Error: database is empty.");
}

float BitcoinExchange::getExchangeRate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = _database.find(date);
    if (it != _database.end())
        return it->second;
    return _database.find(findClosestDate(date))->second;
}

void BitcoinExchange::processInput(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw FileError("Error: could not open file.");

    std::string line;
    std::getline(file, line); // Skip header

    while (std::getline(file, line)) {
        std::string date;
        float value;

        if (!parseInputLine(line, date, value)) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (!isValidDate(date)) {
            std::cout << "Error: invalid date => " << date << std::endl;
            continue;
        }

        if (!isValidValue(value)) {
            if (value < 0)
                std::cout << "Error: not a positive number." << std::endl;
            else
                std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        float rate = getExchangeRate(date);
        std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
    }
}
