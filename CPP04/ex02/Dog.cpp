#include "Dog.hpp"

Dog::Dog() : brain(new Brain()) {
    type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other), brain(new Brain(*other.brain)) {
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        AAnimal::operator=(other);
        *brain = *other.brain;
    }
    std::cout << "Dog assignment operator called" << std::endl;
    return *this;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof woof!" << std::endl;
}
