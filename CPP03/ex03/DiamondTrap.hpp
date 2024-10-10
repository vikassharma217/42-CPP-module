#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string _name;

    public:
        DiamondTrap(); //default constructor
        DiamondTrap(const DiamondTrap& rhs); // copy constructor     
        DiamondTrap(const std::string& name); // paremetrized constrcuotr
        ~DiamondTrap();
        DiamondTrap& operator=(const DiamondTrap& rhs);

        //using ScavTrap::attack;
        void attack(const std::string& target);
        /*custome member function for DiamondTrap*/
        void whoAmI();
};

#endif