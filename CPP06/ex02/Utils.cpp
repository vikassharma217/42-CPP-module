#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Utils.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

// /*seed generator for rand based on current time*/
// void	seedRand(void)
// {
// 	std::srand(std::time(0));
// }

/*randomly instatialte A,B or C as Base pointer*/
Base	*generate(void)
{
	int	randChoice;

	randChoice = std::rand() % 3;
	if (randChoice == 0)
		return (new A());
	else if (randChoice == 1)
		return (new B());
	else
		return (new C());
}

/*prints the actual type of object pointed by P: A,B or C*/
void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

/*prints the actula type of object pointed by p without using pointer*/
void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch (const std::exception &e)
	{
		//std::cerr << "Error: " << e.what() << std::endl;
	}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
	}
	catch (const std::exception &e)
	{
		//std::cerr << "Error: " << e.what() << std::endl;
	}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
	}
	catch (const std::exception &e)
	{
		//std::cerr << "Error: " << e.what() << std::endl;
	}
}
