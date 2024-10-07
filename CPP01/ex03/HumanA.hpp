#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanA
{
  private:
	std::string name;
	Weapon &weapon;

  public:
	// constructor take human name and refer to weapon
	HumanA(std::string name, Weapon &weapon);

	void attack() const;
};

#endif