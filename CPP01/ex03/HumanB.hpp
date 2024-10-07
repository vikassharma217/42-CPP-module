#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanB
{
  private:
	std::string name;
	Weapon *weapon;

  public:
	// constructor, takes only name , waepon is not mandetory
	HumanB(std::string name);

	// settor for weapon
	void setWeapon(Weapon &weapon);

	// function to display attack message
	void attack() const;
};

#endif