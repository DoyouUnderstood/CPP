#include "phonebook.hpp"
#include <iostream> 
#include <string>

#include "phonebook.hpp"

#include <iostream>
#include "phonebook.hpp"

void addContact(Phonebook& repertoire) {
    Contact contact;
    std::string line;
    
    std::cout << "Enter first name: ";
    std::getline(std::cin, line);
    contact.setName(line);
    
    std::cout << "Enter last name: ";
    std::getline(std::cin, line);
    contact.setLastname(line);
    
    std::cout << "Enter nickname: ";
    std::getline(std::cin, line);
    contact.setNickname(line);
    
    std::cout << "Enter phone number: ";
    std::getline(std::cin, line);
    contact.setNumber(line);
    
    std::cout << "Enter secret: ";
    std::getline(std::cin, line);
    contact.setSecret(line);
    
    repertoire.addContact(contact);
}

int main()
{
    Phonebook repertoire;
    std::string line;

    while (line != "EXIT")
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, line);
        if (line == "ADD")
            addContact(repertoire);
    }
    return (0);
}
