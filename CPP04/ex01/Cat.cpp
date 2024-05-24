#include "Cat.hpp"

Cat::Cat() : brain(new Brain()) {
    type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
        *brain = *other.brain;
    }
    std::cout << "Cat assignment operator called" << std::endl;
    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}
