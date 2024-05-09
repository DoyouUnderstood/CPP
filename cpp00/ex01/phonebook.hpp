#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <stdio.h>



class Contact 
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
    public:
        Contact();
        ~Contact();
        std::string getFirstName()const ;
        std::string getLastName() const ;
        std::string getNickname() const ;
        std::string getPhoneNumber() const ;
        std::string getSecret() const ;
        void setFirstName(const std::string& value);
        void setLastName(const std::string& str);
        void setNickname(const std::string& str);
        void setPhoneNumber(const std::string& str);
        void setSecret(const std::string& str);

};

class Phonebook
{
    private:
        Contact contacts[8];
    public:
        Phonebook();
        ~Phonebook();
        void addContact();
        void searchContact();

};

#endif