# include "Zombie.hpp"

int main()
{
    Zombie* zombieOne = newZombie("HEAPY");
    zombieOne->announce();
    delete zombieOne;

    randomChump("STACKY");
    return (0);
}