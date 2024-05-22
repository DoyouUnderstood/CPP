#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap claptrap1("CL4P-TP");
    ScavTrap scavtrap1("SC4V-TP");

    claptrap1.attack("target");
    scavtrap1.attack("target");

    claptrap1.takeDamage(3);
    scavtrap1.takeDamage(3);

    claptrap1.beRepaired(5);
    scavtrap1.beRepaired(5);

    scavtrap1.guardGate();

    return 0;
}

