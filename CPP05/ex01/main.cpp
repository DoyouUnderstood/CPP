#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 2);
        Form formA("FormA", 1, 10);
        Form formB("FormB", 3, 20);

        std::cout << bob << std::endl;
        std::cout << formA << std::endl;
        std::cout << formB << std::endl;

        bob.signForm(formA);
        bob.signForm(formB);

        std::cout << formA << std::endl;
        std::cout << formB << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat alice("Alice", 149);
        Form formC("FormC", 150, 150);

        std::cout << alice << std::endl;
        std::cout << formC << std::endl;

        alice.signForm(formC);

        std::cout << formC << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
