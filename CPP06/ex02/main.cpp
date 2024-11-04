#include "Utils.hpp"
#include <cstdlib> // for rand()
#include <ctime>
#include <iostream>

int	main(void)
{
	std::srand(static_cast<unsigned int>(std::time(0)));

	Base *o1 = generate();
	std::cout << "Identify by pointer: " << std::endl;
	identify(o1);

	std::cout << "Identify by reference: " << std::endl;
	identify(*o1);

	delete o1;
 
	return (0);
}