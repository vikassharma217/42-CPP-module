#include "Zombie.hpp"

int	main(void)
{
	int number = 7;
	Zombie *horde = zombieHorde(number, "ZUMBAS");

	if (horde)
	{
		for (int i = 0; i < number; i++)
		{
			horde[i].announce();
		}
	}
	delete[] horde;
	return (0);
}