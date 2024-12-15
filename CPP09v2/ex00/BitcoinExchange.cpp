#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::isValidDate(std::string &date) const
{
    if (date.length() != 10)
        throw Error("bad input => " + date);

    if (date[4] != '-' || date[7] != '-')
        throw Error("bad input => " + date);

    for (int i = 0; i < 10; i++)
        if (i != 4 && i != 7 && !std::isdigit(date[i]))
            throw Error("bad input => " + date);

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12 || day < 1 || year < 1900)
        throw Error("bad input => " + date);

    // Mois avec 31 jours
    if ((month == 1 || month == 3 || month == 5 || month == 7 || 
         month == 8 || month == 10 || month == 12) && day > 31)
        throw Error("bad input => " + date);

    // Mois avec 30 jours
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        throw Error("bad input => " + date);

    // Février
    if (month == 2)
    {
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if ((isLeapYear && day > 29) || (!isLeapYear && day > 28))
            throw Error("bad input => " + date);
    }
}

void BitcoinExchange::isValidValue(const double value) const
{
    if (value < 0)
        throw Error("not a positive number.");
    if (value > 1000)
        throw Error("too large a number.");
}

double BitcoinExchange::findClosestRate(const std::string &date) const
{
    std::map<std::string, double>::const_iterator it = _btcDatabase.upper_bound(date);
    if (it == _btcDatabase.begin())
        throw Error("no data available for this date");
    --it;
    return it->second;
}

void BitcoinExchange::processExchange(const std::string &date, const double value) const
{
    try {
        double rate = findClosestRate(date);
        std::cout << date << " => " << value << " = " << value * rate << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void BitcoinExchange::parseLine(const std::string &line) const
{
    std::string date;
    std::string valueStr;
    double value;
    size_t separator = line.find(" | ");
    
    if (separator == std::string::npos)
        throw Error("bad input => " + line);
        
    date = line.substr(0, separator);
    valueStr = line.substr(separator + 3);
    
    try {
        value = std::atof(valueStr.c_str());
        isValidDate(date);
        isValidValue(value);
        processExchange(date, value);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw Error("could not open database file.");
    
    std::string line;
    std::getline(file, line); // Skip header line
    
    while (std::getline(file, line))
    {
        size_t separator = line.find(',');
        if (separator != std::string::npos)
        {
            std::string date = line.substr(0, separator);
            double value = std::atof(line.substr(separator + 1).c_str());
            _btcDatabase[date] = value;
        }
    }
    file.close();
}

void BitcoinExchange::processInput(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw Error("could not open file.");
    
    std::string line;
    std::getline(file, line); // Skip header line
    
    while (std::getline(file, line))
    {
        try {
            parseLine(line);
        }
        catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    file.close();
}