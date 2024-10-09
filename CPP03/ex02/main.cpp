# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <iostream>

int	main(void)
{
	/*ClapTrap oobject*/
	ClapTrap clap1("Clap_1");
	clap1.attack("Target_1");
	clap1.takeDamage(5);
	clap1.beRepaired(3);
	
	std::cout<<std::endl<<std::endl;

	/*FragTrap object*/
	FragTrap frag1("Frag_1");
	frag1.attack("Target_2");
	frag1.takeDamage(4);
	frag1.beRepaired(5);

	frag1.highFivesGuys();

	return (0);
}
