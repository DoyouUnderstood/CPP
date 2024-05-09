#include "phonebook.hpp"


Phonebook::Phonebook() 
{

}

Phonebook::~Phonebook() 
{

}

std::string getValidInput(const std::string& prompt) 
{
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);

    while (input.empty()) {
        std::cout << "This field cannot be empty. Please enter a value.\n";
        std::cout << prompt;
        std::getline(std::cin, input);
    }

    return input;
}


void Phonebook::addContact() 
{
    if (currentContactCount >= 8) {
        for (int i = 1; i < 8; i++) {
            contacts[i - 1] = contacts[i];
        }
        currentContactCount = 7;
    }

    Contact newContact;
    
    newContact.setName(getValidInput("Enter first name: "));
    newContact.setLastName(getValidInput("Enter last name: "));
    newContact.setNickname(getValidInput("Enter nickname: "));
    newContact.setNumber(getValidInput("Enter phone number: "));
    newContact.setSecret(getValidInput("Enter darkest secret: "));

    contacts[currentContactCount++] = newContact;
}

std::string formatField(const std::string& field)
{
    if (field.length() > 10) {
        return field.substr(0, 9) + ".";
    }
    return field;
}

void displayContactDetails(const Contact& contact)
{
    std::cout << "First Name: " << contact.getName() << "\n"
              << "Last Name: " << contact.getLastName() << "\n"
              << "Nickname: " << contact.getNickname() << "\n"
              << "Phone Number: " << contact.getNumber() << "\n"
              << "Darkest Secret: " << contact.getSecret() << std::endl;
    std::cin.ignore(INT_MAX, '\n');
}

#include <iomanip>

void Phonebook::searchContacts() const 
{
    std::cout << "List of contacts:\n";
    std::cout << std::setw(10) << std::right << "Index" << " | "
              << std::setw(10) << "First Name" << " | "
              << std::setw(10) << "Last Name" << " | "
              << std::setw(10) << "Nickname" << std::endl;

    for (int i = 1; i < currentContactCount; ++i) {
        std::cout << std::setw(10) << i << " | "
                  << std::setw(10) << formatField(contacts[i].getName()) << " | "
                  << std::setw(10) << formatField(contacts[i].getLastName()) << " | "
                  << std::setw(10) << formatField(contacts[i].getNickname()) << std::endl;
    }

    int index;
    std::cout << "Enter the index of the contact to display, or 0 to exit: ";
    std::cin >> index;
    if (index > 0 && index <= currentContactCount) {
        displayContactDetails(contacts[index]);
    } else if (index != 0) {
        std::cout << "Invalid index. Please try again.\n";
    }
}

