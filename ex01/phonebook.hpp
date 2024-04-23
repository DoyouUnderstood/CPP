#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>

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
        void addContact(void);

    private :
        std::string _name;
        std::string _lastName;
        std::string _Nickname;
        std::string _number;
        std::string _secret;
};

class Phonebook {
public:
    Phonebook();
    ~Phonebook();
    void addContact(const Contact& contact);
private:
    Contact repertoire[8];
};

#endif