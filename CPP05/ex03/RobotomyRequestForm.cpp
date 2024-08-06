#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (!isSigned()) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > getGradeRequiredToExecute()) {
        throw GradeTooLowException();
    }

    std::cout << "Drilling noises..." << std::endl;
    if (rand() % 2) {
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "The robotomy failed!" << std::endl;
    }
}