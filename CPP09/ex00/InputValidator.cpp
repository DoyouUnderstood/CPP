#include "InputValidator.hpp"
#include <sstream>
#include <vector>
#include <stdexcept>

bool InputValidator::isValidDate(const std::string& date) {
    std::istringstream ss(date);
    std::string yearStr, monthStr, dayStr;
    int year, month, day;

    if (std::getline(ss, yearStr, '-') && std::getline(ss, monthStr, '-') && std::getline(ss, dayStr)) {
        try {
            year = std::stoi(yearStr);
            month = std::stoi(monthStr);
            day = std::stoi(dayStr);

            if (month < 1 || month > 12 || day < 1 || day > getDaysInMonth(year, month)) {
                return false;
            }
            return true;
        } catch (...) {
            return false;
        }
    }
    return false;
}

bool InputValidator::isValidValue(const std::string& valueStr, double& value) {
    try {
        value = std::stod(valueStr);
        if (value < 0) {
            throw std::invalid_argument("not a positive number.");
        } else if (value > 1000) {
            throw std::out_of_range("too large a number.");
        }
        return true;
    } catch (const std::invalid_argument& e) {
        throw std::runtime_error("Error: " + std::string(e.what()));
    } catch (const std::out_of_range& e) {
        throw std::runtime_error("Error: " + std::string(e.what()));
    } catch (...) {
        return false;
    }
}

bool InputValidator::isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int InputValidator::getDaysInMonth(int year, int month) {
    static const std::vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return daysInMonth[month - 1];
}