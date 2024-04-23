#include "phonebook.hpp"
#include <iostream> 
#include <string>
#include "contact.hpp"

int main()
{
    Phonebook repertoire;
    std::string line;

    while (line != "EXIT")
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, line);
        if (line == "ADD")
        {
            Contact contact;
            contact.addContact(repertoire);
        }
    }
    return (0);
}
