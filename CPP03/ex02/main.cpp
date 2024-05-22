#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    ClapTrap claptrap1("CL4P-TP");
    ScavTrap scavtrap1("SC4V-TP");
    FragTrap fragtrap1("FR4G-TP");

    claptrap1.attack("target");
    scavtrap1.attack("target");
    fragtrap1.attack("target");

    claptrap1.takeDamage(3);
    scavtrap1.takeDamage(3);
    fragtrap1.takeDamage(3);

    claptrap1.beRepaired(5);
    scavtrap1.beRepaired(5);
    fragtrap1.beRepaired(5);

    scavtrap1.guardGate();
    fragtrap1.highFivesGuys();

    return 0;
}
