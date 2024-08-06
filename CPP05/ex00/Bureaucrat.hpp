#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat {
public:
    Bureaucrat(const std::string &name, int grade);
    ~Bureaucrat();

    const std::string &getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

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
    int _grade;

    void validateGrade(int grade);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif
