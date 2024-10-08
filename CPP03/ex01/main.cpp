#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap ct1("Clap1");
	ClapTrap ct2("Clap2");
	ct1.attack("Target1");
	ct1.takeDamage(2);
	ct1.beRepaired(1);
	ct1.attack("Target2");
	ct2.attack("Target1");
	ct2.attack("Target1");
	ct2.attack("Target1");
	ct2.attack("Target1");
	ct2.attack("Target1");
	ct2.attack("Target1");
	ct2.attack("Target1");
	ct2.attack("Target1");
	ct2.attack("Target1");
	ct2.attack("Target1");
	ct2.attack("Target2");
	ct2.takeDamage(3);
	ct2.beRepaired(2);
	ct2.takeDamage(5);
	ct2.takeDamage(3);
	ct2.attack("Target2");

	return (0);
}