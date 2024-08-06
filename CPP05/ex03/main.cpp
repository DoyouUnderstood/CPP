#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
    Intern someRandomIntern;
    AForm* form;

    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form) {
        std::cout << *form << std::endl;
        delete form;
    }

    form = someRandomIntern.makeForm("shrubbery creation", "home");
    if (form) {
        std::cout << *form << std::endl;
        delete form;
    }

    form = someRandomIntern.makeForm("presidential pardon", "Marvin");
    if (form) {
        std::cout << *form << std::endl;
        delete form;
    }

    form = someRandomIntern.makeForm("unknown form", "nobody");
    if (form) {
        delete form;
    }

    return 0;
}
