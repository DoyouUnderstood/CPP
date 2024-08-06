#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
public:
    AForm(const std::string &name, int gradeRequiredToSign, int gradeRequiredToExecute);
    virtual ~AForm();

    const std::string &getName() const;
    bool isSigned() const;
    int getGradeRequiredToSign() const;
    int getGradeRequiredToExecute() const;

    void beSigned(const Bureaucrat &bureaucrat);
    virtual void execute(Bureaucrat const &executor) const = 0; // Méthode virtuelle pure

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

    class FormNotSignedException : public std::exception {
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

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif
