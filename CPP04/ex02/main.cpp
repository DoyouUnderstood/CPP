#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    delete j;
    delete i;

    AAnimal* animals[10];
    for (int i = 0; i < 5; ++i) {
        animals[i] = new Dog();
    }
    for (int i = 5; i < 10; ++i) {
        animals[i] = new Cat();
    }
    for (int i = 0; i < 10; ++i) {
        delete animals[i];
    }

    return 0;
}
