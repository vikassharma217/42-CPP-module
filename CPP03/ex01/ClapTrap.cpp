# include "ClapTrap.hpp"
# include <iostream>

ClapTrap::ClapTrap(const std::string& name)
{
    _name = name;
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
    std::cout << "ClapTrap constructor has constructed "
                << _name << std::endl;
}

ClapTrap::~ClapTrap()
{
   std::cout << "ClapTrap destructor has destructed "
            <<_name << std::endl;
}

/*function to attack, cost one energy point*/
 void ClapTrap::attack(const std::string& target)
 {
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        _energyPoints--;
        std::cout << _name << " attacks on " << target
                    << " & Damaged " << _attackDamage 
                    << " hitpoints." << std::endl;
    }
    else
        std::cout << _name << " doesn't have enough energy/hit points" 
                    << std::endl;
 }

/*function to take damage of given amount*/
void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints > 0)
    {
        _hitPoints -= amount;
         std::cout << _name << " takes " << amount
                    << " damage." << std::endl;
    }
    else
        std::cout << _name << " is already dead !!" << std::endl;

    //std::cout << _name << "Total Hit point: " << _hitPoints << std::endl;
}

/*function to repair with given amount, cost one energy point*/
void ClapTrap::beRepaired(unsigned int amount)
{
    if ( _hitPoints > 0 && _energyPoints > 0)
    {
        _hitPoints += amount;
        _energyPoints--;
        std::cout << "ClapTrap " << _name << " got repaird by " << amount 
            << " points." << std::endl;
    }
    else
    {
        std::cout << _name << " doesnt have enough energy/hit point." << std::endl; 
    }
    //std::cout << _name << "Total Hit point: " << _hitPoints << std::endl;
}