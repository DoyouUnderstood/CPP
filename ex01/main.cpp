#include "phonebook.hpp"
#include <iostream> 
#include <string>
#include "contact.hpp"
#include <cstdio>
#include "phonebook.hpp"
#include <iostream>
#include <string>

#include <iostream>

int main() {
    Phonebook myPhoneBook;
    std::string command;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD") {
            myPhoneBook.addContact();
        } else if (command == "SEARCH") {
            myPhoneBook.searchContacts();
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Unknown command." << std::endl;
        }
    }

    return 0;
}

