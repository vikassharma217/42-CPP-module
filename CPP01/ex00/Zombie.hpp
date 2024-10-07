/*header file to declare class and protoypye util functions*/

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
  private:
	std::string name;

  public:
	// consturctor to initilize zombie name
	Zombie(std::string zombieName);

	// destructor to destory heap allocation and debug message
	~Zombie();

	void announce(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif