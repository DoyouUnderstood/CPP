#ifndef INPUTVALIDATOR_HPP
#define INPUTVALIDATOR_HPP

#include <string>

class InputValidator {
public:
    static bool isValidDate(const std::string& date);
    static bool isValidValue(const std::string& valueStr, double& value);

private:
    static bool isLeapYear(int year);
    static int getDaysInMonth(int year, int month);
};

#endif