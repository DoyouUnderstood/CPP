#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <string>

class ShrubberyCreationForm : public AForm {
public:
    ShrubberyCreationForm(const std::string &target);
    ~ShrubberyCreationForm();

    void execute(Bureaucrat const &executor) const;

private:
    std::string _target;
};

#endif
