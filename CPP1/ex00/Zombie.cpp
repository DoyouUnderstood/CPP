#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
    _name = name;
}

Zombie::~Zombie() {
    std::cout << _name << " is destroyed." << std::endl;
}

void Zombie::announce(void) {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* newZombie(std::string name) {
    Zombie* newZ = new Zombie(name);
    return newZ;
}

void randomChump(std::string name) {
    Zombie tempZombie(name);
    tempZombie.announce();
}
