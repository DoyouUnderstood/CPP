#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 2);
        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("target");
        PresidentialPardonForm pardon("target");

        std::cout << bob << std::endl;
        std::cout << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;

        bob.signForm(shrubbery);
        bob.signForm(robotomy);
        bob.signForm(pardon);

        std::cout << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;

        bob.executeForm(shrubbery);
        bob.executeForm(robotomy);
        bob.executeForm(pardon);

    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
