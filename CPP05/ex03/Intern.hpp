#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
    Intern();
    ~Intern();

    AForm* makeForm(const std::string &formName, const std::string &target) const;

private:
    AForm* createShrubberyForm(const std::string &target) const;
    AForm* createRobotomyForm(const std::string &target) const;
    AForm* createPardonForm(const std::string &target) const;
};

#endif
