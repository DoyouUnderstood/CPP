#include "phonebook.hpp"

Contact::Contact() {
}

Contact::~Contact() {
}

std::string Contact::getFirstName() const {
    return first_name;
}

std::string Contact::getLastName() const {
    return last_name;
}

std::string Contact::getNickname() const {
    return nickname;
}

std::string Contact::getPhoneNumber() const {
    return phone_number;
}

std::string Contact::getSecret() const {
    return darkest_secret;
}
