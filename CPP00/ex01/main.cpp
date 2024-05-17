#include "PhoneBook.hpp"
#include <iostream>
#include <string>

void addContact(PhoneBook &phoneBook) {
    Contact contact;
    std::string input;

    std::cout << "Enter first name: ";
    std::getline(std::cin, input);
    contact.setFirstName(input);

    std::cout << "Enter last name: ";
    std::getline(std::cin, input);
    contact.setLastName(input);

    std::cout << "Enter nickname: ";
    std::getline(std::cin, input);
    contact.setNickname(input);

    std::cout << "Enter phone number: ";
    std::getline(std::cin, input);
    contact.setPhoneNumber(input);

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, input);
    contact.setDarkestSecret(input);

    phoneBook.addContact(contact);
}

void searchContact(const PhoneBook &phoneBook) {
    phoneBook.displayContacts();
    std::cout << "Enter index of the contact to display: ";
    std::string input;
    std::getline(std::cin, input);
    try {
        int index = std::stoi(input);
        phoneBook.displayContactDetails(index);
    } catch (std::exception &e) {
        std::cerr << "Invalid index!" << std::endl;
    }
}

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD") {
            addContact(phoneBook);
        } else if (command == "SEARCH") {
            searchContact(phoneBook);
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Unknown command!" << std::endl;
        }
    }

    return 0;
}
