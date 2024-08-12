#include "iter.hpp"

void printInt(int& x) {
    std::cout << x << std::endl;
}

void increment(int& x) {
    x++;
}

void printString(std::string& str) {
    std::cout << str << std::endl;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    std::string strArray[] = {"Hello", "World", "ex++"};

    std::cout << "Original int array:" << std::endl;
    ::iter(intArray, 5, printInt);

    ::iter(intArray, 5, increment);

    std::cout << "Incremented int array:" << std::endl;
    ::iter(intArray, 5, printInt);

    std::cout << "String array:" << std::endl;
    ::iter(strArray, 3, printString);

    return 0;
}