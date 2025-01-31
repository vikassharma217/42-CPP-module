# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include <iostream>

int	main(void)
{
	/*ClapTrap oobject*/
	ClapTrap clap1("Clap_1");
	clap1.attack("Target_1");
	clap1.takeDamage(5);
	clap1.beRepaired(3);
	
	std::cout<<std::endl<<std::endl;

	/*ScavTrap object*/
	ScavTrap scav1("Scav_1");
	scav1.attack("Target_2");
	scav1.takeDamage(4);
	scav1.beRepaired(5);

	scav1.guardGate();

	return (0);
}