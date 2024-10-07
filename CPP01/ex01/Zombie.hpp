#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <sstream>
# include <string>

class Zombie
{
  private:
	std::string name;

  public:
	// constructor to initi stuff
	Zombie();

	// destructor for dellocation and debug
	~Zombie();

	// setter fucntion to set zombie names
	void setName(std::string zombieName);

	void announce(void);
};

Zombie	*zombieHorde(int N, std::string name);

#endif