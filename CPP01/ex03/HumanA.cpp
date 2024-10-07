# include "HumanA.hpp"

HumanA::HumanA(std::string humanName, Weapon &weapon) : name(humanName), weapon(weapon)
{
}

void HumanA::attack() const
{
    std::cout << name << " attacks with " << weapon.getType() << std::endl; 
}