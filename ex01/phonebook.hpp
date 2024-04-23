#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include "contact.hpp"

class Phonebook {
public:
    Phonebook();
    ~Phonebook();
    void addContact(const Contact& contact);
    bool is_valid(int index) const;

private:
    Contact repertoire[8];
};

#endif
