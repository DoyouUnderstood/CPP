#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name) : name(name), weapon(nullptr) {}

HumanB::~HumanB() {
    delete weapon;
}

void HumanB::setWeapon(const Weapon& weapon) {
    if (this->weapon != nullptr) {
        delete this->weapon;
    }
    this->weapon = new Weapon(weapon);
}

void HumanB::attack() const {
    if (weapon != nullptr) {
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    } else {
        std::cout << name << " attacks unarmed" << std::endl;
    }
}
