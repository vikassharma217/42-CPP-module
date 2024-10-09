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
        /*Constructor and destrcutor*/
        DiamondTrap(const std::string& name);
        ~DiamondTrap();

        //using ScavTrap::attack;
        void attack(const std::string& target);
        /*custome member function for DiamondTrap*/
        void whoAmI();
};

#endif