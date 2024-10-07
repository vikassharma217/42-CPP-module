/*cpp file to define the required functions*/

#include "Zombie.hpp"

Zombie::Zombie(std::string zombieName) : name(zombieName)
{
	std::cout << "Argggggh..." << name << " arrived!!!" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Noo... " << name << " is gone!!!" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}