#include "phonebook.hpp"

std::string Contact::getName(void) const
{
    return this->_name;
}

std::string Contact::getLastName(void) const
{
    return this->_lastName;
}
std::string Contact::getNumber(void) const
{
    return this->_number;
}
std::string Contact::getSecret(void) const
{
    return this->_secret;
}
std::string Contact::getNickname(void) const
{
    return this->_Nickname;
}