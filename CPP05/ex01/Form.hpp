#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
public:
    Form(const std::string &name, int gradeRequiredToSign, int gradeRequiredToExecute);
    ~Form();

    const std::string &getName() const;
    bool isSigned() const;
    int getGradeRequiredToSign() const;
    int getGradeRequiredToExecute() const;

    void beSigned(const Bureaucrat &bureaucrat);

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

private:
    const std::string _name;
    bool _isSigned;
    const int _gradeRequiredToSign;
    const int _gradeRequiredToExecute;

    void validateGrade(int grade);
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
