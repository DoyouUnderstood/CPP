#include "phonebook.hpp"

Phonebook::Phonebook() 
{

}

Phonebook::~Phonebook() 
{

}

bool Phonebook::is_valid(int index) const 
{
    return repertoire[index].isNameEmpty();
}



void Phonebook::addContact(const Contact& contact) {
    for (int i = 0; i < 8; ++i) 
    {
        if (is_valid(i)) 
        {
            repertoire[i] = contact;
            std::cout << "Contact added successfully!" << std::endl;
            return;
        }
    }
    std::cout << "No space available to add contact. Phonebook is full." << std::endl;
}
