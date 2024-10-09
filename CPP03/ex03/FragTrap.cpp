# include "FragTrap.hpp"
# include <iostream>

FragTrap::FragTrap(const std::string& name) :ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap constructor has constructed "
                << _name << std::endl;
}

FragTrap::~FragTrap()
{
   std::cout << "FragTrap destructor has destructed "
            <<_name << std::endl;
}

/*function to attack, cost one energy point*/
 void FragTrap::attack(const std::string& target)
 {
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        _energyPoints--;
        std::cout << "FragTrap " <<_name << " attacks on " << target
                    << " & Damaged " << _attackDamage 
                    << " hitpoints." << std::endl;
    }
    else
        std::cout << "FragTrap" <<_name << " doesn't have enough energy/hit points" 
                    << std::endl;
 }

 /*SavTrap custome method*/

 void FragTrap::highFivesGuys(void)
 {
    std::cout << "FragTrap " << _name << " needs high five \U0001F64C" << std::endl;
 }