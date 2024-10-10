#ifndef FragTrap_HPP
# define FragTrap_HPP

# include "ClapTrap.hpp"
# include <string>

class FragTrap : public ClapTrap
{
    public:
        FragTrap(); // default constrcutor
        FragTrap(const FragTrap& rhs); // copy constructor
        FragTrap(const std::string& name); // paremetarized constrcutor
        ~FragTrap();
        FragTrap& operator=(const FragTrap& rhs); // copy assignment operator

        /*FragTrap custom attack method*/
        void attack(const std::string& target);
        
        /*new method for FragTrap*/
        void highFivesGuys(void);
};

#endif
