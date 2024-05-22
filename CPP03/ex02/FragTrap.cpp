#include "FragTrap.hpp"

// Constructeur
FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap " << this->name << " created with "
              << hitPoints << " hit points, "
              << energyPoints << " energy points, and "
              << attackDamage << " attack damage." << std::endl;
}

// Destructeur
FragTrap::~FragTrap() {
    std::cout << "FragTrap " << this->name << " destroyed." << std::endl;
}

// Fonction spéciale de FragTrap
void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << this->name << " requests a high five!" << std::endl;
}
