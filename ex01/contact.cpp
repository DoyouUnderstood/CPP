#include "phonebook.hpp"

Contact::Contact(void)
{

}

Contact::~Contact(void)
{

}

bool Contact::isNameEmpty() const 
{
    return _name.empty();
}
