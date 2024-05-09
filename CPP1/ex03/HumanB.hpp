#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {
private:
    std::string name;
    Weapon *weapon; // Using a pointer to Weapon
    
public:
    HumanB(const std::string& name);
    ~HumanB(); // Destructor to clean up memory
    void setWeapon(const Weapon& weapon);
    void attack() const;
};

#endif
