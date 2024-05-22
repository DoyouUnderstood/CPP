#include "ScavTrap.hpp"

// Constructeur
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap " << this->name << " created with "
              << hitPoints << " hit points, "
              << energyPoints << " energy points, and "
              << attackDamage << " attack damage." << std::endl;
}

// Destructeur
ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << this->name << " destroyed." << std::endl;
}

// Surcharger la fonction d'attaque
void ScavTrap::attack(const std::string& target) {
    if (this->hitPoints > 0 && this->energyPoints > 0) {
        this->energyPoints--;
        std::cout << "ScavTrap " << this->name << " viciously attacks " << target
                  << ", causing " << this->attackDamage << " points of damage!" << std::endl;
    } else {
        std::cout << "ScavTrap " << this->name << " cannot attack, insufficient hit points or energy points." << std::endl;
    }
}

// Fonction spécifique à ScavTrap
void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}
