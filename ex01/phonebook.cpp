#include "phonebook.hpp"

Contact::Contact(void)
{

}

Contact::~Contact(void)
{

}

#include "phonebook.hpp"

Phonebook::Phonebook() 
{

}

Phonebook::~Phonebook() 
{

}


void Phonebook::addContact(const Contact& contact) {
    for (int i = 0; i < 8; ++i) {
        repertoire[i] = contact;
        std::cout << "Contact added successfully!" << std::endl;
        return;
    }
    std::cout << "Unable to add contact: Phonebook is full." << std::endl;
}
