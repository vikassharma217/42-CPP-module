# include "HumanB.hpp"

HumanB::HumanB(std::string humanName)
{
    name = humanName;
    weapon = NULL;
}

void HumanB::setWeapon(Weapon &humanBWeapon)
{
    weapon = &humanBWeapon;
}

void HumanB::attack() const
{
    if (weapon)
        std::cout << name << " attacks with " << weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon." << std::endl;
}

