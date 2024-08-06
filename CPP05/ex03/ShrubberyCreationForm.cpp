#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (!isSigned()) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > getGradeRequiredToExecute()) {
        throw GradeTooLowException();
    }

    std::ofstream ofs((_target + "_shrubbery").c_str()); // Conversion en const char*
    if (!ofs) {
        throw std::ios_base::failure("Failed to open file");
    }
    ofs << "       _-_       \n"
           "    /~~   ~~\\    \n"
           " /~~         ~~\\ \n"
           "{               }\n"
           " \\  _-     -_  / \n"
           "   ~  \\\\ //  ~   \n"
           "_- -   | | _- _  \n"
           "  _ -  | |   -_  \n"
           "      // \\\\      \n";
}
