#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Phonebook;

class Contact 
{
    public :
        Contact();
        ~Contact();
        void setName(std::string setname);
        void setLastName(std::string lastname);
        void setNickname(std::string nickname);
        void setNumber(std::string number);
        void setSecret(std::string secret);
        std::string getName() const;
        std::string getLastName() const;
        std::string getNickname() const;
        std::string getNumber() const;
        std::string getSecret() const;
        // void addContact(Phonebook& repertoire);
        bool isNameEmpty() const;

    private :
        std::string _name;
        std::string _lastName;
        std::string _Nickname;
        std::string _number;
        std::string _secret;
};


#endif