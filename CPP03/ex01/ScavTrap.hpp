#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap(); // default constructor
        ScavTrap(const ScavTrap& rhs); // copy constructor
        ScavTrap(const std::string& name); // paremetarized constructor
        ~ScavTrap(); // default destructor
        ScavTrap& operator=(const ScavTrap& rhs); // copy assignment operator

        /*ScavTrap custom attack method*/
        void attack(const std::string& target);
        
        /*new method for ScavTrap*/
        void guardGate();
};

#endif
