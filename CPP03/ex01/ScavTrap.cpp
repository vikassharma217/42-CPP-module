#include "ScavTrap.hpp"
#include <iostream>

/*default constructor*/
ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

/*copy constructor*/
ScavTrap::ScavTrap(const ScavTrap &rhs) : ClapTrap(rhs)
{
	*this = rhs;
	std::cout << "Scavtrap copy constructor called" << std::endl;
}

/*paremetarized constructor*/
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap constructor has constructed " << _name << std::endl;
}

/*default destructor*/
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor has destructed " << _name << std::endl;
}

/*copy assignment operato*/
ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	std::cout << "ScavTrap Assignation operator" << std::endl;
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
		_hitPoints = rhs._hitPoints;
		_energyPoints = rhs._energyPoints;
		_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

/*function to attack, cost one energy point*/
void ScavTrap::attack(const std::string &target)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		_energyPoints--;
		std::cout << "Scavtrap " << _name << " attacks on " << target << " & Damaged " << _attackDamage << " hitpoints." << std::endl;
	}
	else
		std::cout << "ScavTrap" << _name << " doesn't have enough energy/hit points" << std::endl;
}

/*SavTrap custome method*/
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in \U0001F6E1 Gatekeeper \U0001F6E1 mode." << std::endl;
}