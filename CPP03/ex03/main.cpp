# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include "DiamondTrap.hpp"
# include <iostream>

int	main(void)
{
	DiamondTrap diamond1("Diamond_1");

	diamond1.attack("Target_1");
	diamond1.whoAmI();

	return (0);
}
