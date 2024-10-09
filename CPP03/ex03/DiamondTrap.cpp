# include "DiamondTrap.hpp"
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

# include <iostream>

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
     std::cout << "DiamondTrap constructor has constructed "
                << _name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor has destructed "
            <<_name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "My name: " << _name 
                << " & my ClapTrap name: " << ClapTrap::_name << std::endl;
}