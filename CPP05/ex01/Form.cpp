#include "Form.hpp"

Form::Form(const std::string &name, int gradeRequiredToSign, int gradeRequiredToExecute)
    : _name(name), _isSigned(false), _gradeRequiredToSign(gradeRequiredToSign), _gradeRequiredToExecute(gradeRequiredToExecute) {
    validateGrade(gradeRequiredToSign);
    validateGrade(gradeRequiredToExecute);
}

Form::~Form() {}

const std::string &Form::getName() const {
    return _name;
}

bool Form::isSigned() const {
    return _isSigned;
}

int Form::getGradeRequiredToSign() const {
    return _gradeRequiredToSign;
}

int Form::getGradeRequiredToExecute() const {
    return _gradeRequiredToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _gradeRequiredToSign) {
        throw GradeTooLowException();
    }
    _isSigned = true;
}

void Form::validateGrade(int grade) {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
    out << form.getName() << ", form status ";
    if (form.isSigned()) {
        out << "signed";
    } else {
        out << "not signed";
    }
    out << ", grade required to sign " << form.getGradeRequiredToSign()
        << ", grade required to execute " << form.getGradeRequiredToExecute();
    return out;
}
