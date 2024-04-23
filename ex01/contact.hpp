#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "phonebook.hpp"
#include <string>
#include <iostream>

class Phonebook;

class Contact
{
    public :
        Contact();
        ~Contact();
        void setName(std::string setname);
        void setLastname(std::string lastname);
        void setNickname(std::string nickname);
        void setNumber(std::string number);
        void setSecret(std::string secret);
        std::string getName(void);
        std::string getLastname(void);
        std::string getNickname(void);
        std::string getNumber(void);
        std::string getSecret(void);
        void addContact(Phonebook& repertoire);
        bool isNameEmpty() const;

    private :
        std::string _name;
        std::string _lastName;
        std::string _Nickname;
        std::string _number;
        std::string _secret;
};


#endif