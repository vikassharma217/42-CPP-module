# include "Weapon.hpp"

Weapon::Weapon(std::string initType) : type(initType)
{  
}
const std::string &Weapon::getType() const
{
    return (type);
}

void Weapon::setType(const std::string &newType)
{
    type = newType;
}