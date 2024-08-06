#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) {
    validateGrade(grade);
}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::incrementGrade() {
    validateGrade(_grade - 1);
    _grade--;
}

void Bureaucrat::decrementGrade() {
    validateGrade(_grade + 1);
    _grade++;
}

void Bureaucrat::validateGrade(int grade) {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b) {
    out << b.getName() << ", bureaucrat grade " << b.getGrade();
    return out;
}
