#include "ClapTrap.hpp"

// Constructeur
ClapTrap::ClapTrap(const std::string& name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << this->name << " created with "
              << hitPoints << " hit points, "
              << energyPoints << " energy points, and "
              << attackDamage << " attack damage." << std::endl;
}

// Destructeur
ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << this->name << " destroyed." << std::endl;
}

// Fonction d'attaque
void ClapTrap::attack(const std::string& target) {
    if (this->hitPoints > 0 && this->energyPoints > 0) {
        this->energyPoints--;
        std::cout << "ClapTrap " << this->name << " attacks " << target
                  << ", causing " << this->attackDamage << " points of damage!" << std::endl;
    } else {
        std::cout << "ClapTrap " << this->name << " cannot attack, insufficient hit points or energy points." << std::endl;
    }
}

// Fonction de prise de dégâts
void ClapTrap::takeDamage(unsigned int amount) {
    this->hitPoints -= amount;
    if (this->hitPoints < 0) this->hitPoints = 0;
    std::cout << "ClapTrap " << this->name << " takes " << amount
              << " points of damage, remaining hit points: " << this->hitPoints << "." << std::endl;
}

// Fonction de réparation
void ClapTrap::beRepaired(unsigned int amount) {
    if (this->hitPoints > 0 && this->energyPoints > 0) {
        this->energyPoints--;
        this->hitPoints += amount;
        std::cout << "ClapTrap " << this->name << " repairs itself, recovering " << amount
                  << " hit points, remaining hit points: " << this->hitPoints << "." << std::endl;
    } else {
        std::cout << "ClapTrap " << this->name << " cannot repair, insufficient hit points or energy points." << std::endl;
    }
}

// Accesseurs (optionnels)
std::string ClapTrap::getName() const {
    return this->name;
}

int ClapTrap::getHitPoints() const {
    return this->hitPoints;
}

int ClapTrap::getEnergyPoints() const {
    return this->energyPoints;
}

int ClapTrap::getAttackDamage() const {
    return this->attackDamage;
}
