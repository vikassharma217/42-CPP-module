#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap
{
    protected:
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;
    
    public:
        ClapTrap(); //default constrcuto
        ClapTrap(const std::string& name); // paremetarized constructor
        ClapTrap(const ClapTrap& rhs); // copy constructor
        ClapTrap& operator=(const ClapTrap& rhs); // copy assignment operator
        ~ClapTrap(); // default destructor

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif