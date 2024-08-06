#include "AForm.hpp"

AForm::AForm(const std::string &name, int gradeRequiredToSign, int gradeRequiredToExecute)
    : _name(name), _isSigned(false), _gradeRequiredToSign(gradeRequiredToSign), _gradeRequiredToExecute(gradeRequiredToExecute) {
    validateGrade(gradeRequiredToSign);
    validateGrade(gradeRequiredToExecute);
}

AForm::~AForm() {}

const std::string &AForm::getName() const {
    return _name;
}

bool AForm::isSigned() const {
    return _isSigned;
}

int AForm::getGradeRequiredToSign() const {
    return _gradeRequiredToSign;
}

int AForm::getGradeRequiredToExecute() const {
    return _gradeRequiredToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _gradeRequiredToSign) {
        throw GradeTooLowException();
    }
    _isSigned = true;
}

void AForm::validateGrade(int grade) {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed!";
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
    out << form.getName() << ", form status " << (form.isSigned() ? "signed" : "not signed")
        << ", grade required to sign " << form.getGradeRequiredToSign()
        << ", grade required to execute " << form.getGradeRequiredToExecute();
    return out;
}
