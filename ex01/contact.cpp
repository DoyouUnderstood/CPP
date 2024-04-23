#include "phonebook.hpp"

Contact::Contact(void)
{

}

Contact::~Contact(void)
{

}

void Contact::addContact(Phonebook& repertoire) 
{
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

bool Contact::isNameEmpty() const 
{
    return _name.empty();
}
