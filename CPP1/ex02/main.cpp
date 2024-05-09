#include <string>
#include <iostream>

#include <iostream>
#include <string>

int main() 
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;
    std::cout << "Original string: " << str << std::endl;
    std::cout << "String via pointer: " << *stringPTR << std::endl;
    std::cout << "String via reference: " << stringREF << std::endl;
    std::cout << "Address of original string: " << &str << std::endl;
    std::cout << "Address stored in pointer: " << stringPTR << std::endl;
    std::cout << "Address via reference: " << &stringREF << std::endl;
}
