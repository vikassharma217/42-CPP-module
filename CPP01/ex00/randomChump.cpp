/*crete a zombie on stack*/

#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie stackZombie(name);
	stackZombie.announce();
}
