#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include "contact.hpp"
#include <limits>

#define INT_MAX 2147483647

class Phonebook 
{
private:
    Contact contacts[8];
    int currentContactCount;

public:
    Phonebook();
    ~Phonebook();
    void addContact();
    void searchContacts() const;
};

#endif
