#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) const {
    std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (Intern::*formCreators[3])(const std::string &target) const = {
        &Intern::createShrubberyForm,
        &Intern::createRobotomyForm,
        &Intern::createPardonForm
    };

    for (int i = 0; i < 3; i++) {
        if (formNames[i] == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*formCreators[i])(target);
        }
    }

    std::cerr << "Error: Form name \"" << formName << "\" is not recognized." << std::endl;
    return NULL;
}

AForm* Intern::createShrubberyForm(const std::string &target) const {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string &target) const {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPardonForm(const std::string &target) const {
    return new PresidentialPardonForm(target);
}
