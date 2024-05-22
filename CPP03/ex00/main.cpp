#include "ClapTrap.hpp"

int main() 
{
    ClapTrap claptrap1("CL4P-TR$P");
    ClapTrap claptrap2("FR4G-TR$P");

    claptrap1.attack("FR4G-TR$P");
    claptrap2.takeDamage(0);

    claptrap2.attack("CL4P-TR$P");
    claptrap1.takeDamage(0);

    claptrap1.beRepaired(5);
    claptrap2.beRepaired(5);

    return 0;
}
