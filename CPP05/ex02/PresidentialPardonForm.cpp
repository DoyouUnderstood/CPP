#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (!isSigned()) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > getGradeRequiredToExecute()) {
        throw GradeTooLowException();
    }

    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
