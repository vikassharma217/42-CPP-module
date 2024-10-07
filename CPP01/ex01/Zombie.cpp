#include "Zombie.hpp"

Zombie::Zombie() : name("")
{
}

Zombie::~Zombie()
{
}

void Zombie::setName(std::string zombieName)
{
	name = zombieName;
}

void Zombie::announce(void)
{
	std::cout << name << ": Moar BraiiiiiiinnnzzzZ..." << std::endl;
}