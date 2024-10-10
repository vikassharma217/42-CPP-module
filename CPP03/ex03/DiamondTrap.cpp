#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap copy constructor called." << std::endl;
}

/*copy constructor*/
DiamondTrap::DiamondTrap(const DiamondTrap &rhs) : ClapTrap(rhs), ScavTrap(rhs),
	FragTrap(rhs)
{
	*this = rhs;
	std::cout << "DiamondTrap copy constructor called." << std::endl;
}

/*paremetrized constructor*/
DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name
	+ "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap constructor has constructed " << _name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor has destructed " << _name << std::endl;
}

// Copy Assignment Operator
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap copy assignment operator called  " << std::endl;
	if (this != &other)
	{                           
		ClapTrap::operator=(other); 
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return (*this);
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "My name: " << _name << " & my ClapTrap name: " << ClapTrap::_name << std::endl;
}