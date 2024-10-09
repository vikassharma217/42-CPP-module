#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

class ScavTrap : public virtual ClapTrap
{
    public:
        ScavTrap(const std::string& name);
        ~ScavTrap();

        /*ScavTrap custom attack method*/
        void attack(const std::string& target);
        
        /*new method for ScavTrap*/
        void guardGate();
};

#endif
