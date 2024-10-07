/*to creat a zombie horde*/

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*horde;

	if (N <= 0)
	{
		std::cout << "Invalid number of Zombies." << std::endl;
		return (NULL);
	}
	horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		horde[i].setName(name);
	}
	return (horde);
}
