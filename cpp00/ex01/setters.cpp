
#include "phonebook.hpp"

void Contact::setFirstName(const std::string& value) {
    first_name = value;
}

void Contact::setLastName(const std::string& value) {
    last_name = value;
}

void Contact::setNickname(const std::string& value) {
    nickname = value;
}

void Contact::setPhoneNumber(const std::string& value) {
    phone_number = value;
}

void Contact::setSecret(const std::string& value) {
    darkest_secret = value;
}
