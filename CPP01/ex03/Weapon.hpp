#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
  private:
	std::string type;

  public:
	// constructor to init weapon type
	Weapon(std::string initType);

	// getter function that return a const refrence to type string
	const std::string &getType() const;

	// setter member function to set new type for weapon 
	void setType(const std::string &newType);
};

#endif