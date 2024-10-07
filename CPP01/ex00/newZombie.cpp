/*creat new zombie on heap by allocating memory with help of
  new keyword */

# include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
    Zombie* heapZombie;

    heapZombie = new Zombie(name);
    return (heapZombie);
}