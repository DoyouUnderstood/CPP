#include "ScalarConvert.hpp"

ScalarConvert::ScalarConvert() {}
ScalarConvert::~ScalarConvert() {}
ScalarConvert::ScalarConvert(const ScalarConvert&) {}
ScalarConvert& ScalarConvert::operator=(const ScalarConvert&) { return *this; }

void ScalarConvert::convert(const std::string& literal) {
    // Tentative de conversion en int
    try {
        int intValue = std::stoi(literal);
        std::cout << "int: " << intValue << std::endl;
    } catch (const std::invalid_argument&) {
        std::cout << "int: impossible" << std::endl;
    } catch (const std::out_of_range&) {
        std::cout << "int: impossible" << std::endl;
    }

    // Tentative de conversion en float
    try {
        float floatValue = std::stof(literal);
        std::cout << "float: " << floatValue << "f" << std::endl;
    } catch (const std::invalid_argument&) {
        std::cout << "float: impossible" << std::endl;
    } catch (const std::out_of_range&) {
        std::cout << "float: impossible" << std::endl;
    }

    // Tentative de conversion en double
    try {
        double doubleValue = std::stod(literal);
        std::cout << "double: " << doubleValue << std::endl;
    } catch (const std::invalid_argument&) {
        std::cout << "double: impossible" << std::endl;
    } catch (const std::out_of_range&) {
        std::cout << "double: impossible" << std::endl;
    }

    // Tentative de conversion en char
    if (literal.length() == 1 && isprint(literal[0]) && !isdigit(literal[0])) {
        char charValue = literal[0];
        std::cout << "char: '" << charValue << "'" << std::endl;
    } else {
        std::cout << "char: impossible" << std::endl;
    }
}
