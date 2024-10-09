#ifndef FragTrap_HPP
# define FragTrap_HPP

# include "ClapTrap.hpp"
# include <string>

class FragTrap : public virtual ClapTrap
{
    public:
        FragTrap(const std::string& name);
        ~FragTrap();

        /*FragTrap custom attack method*/
        void attack(const std::string& target);
        
        /*new method for FragTrap*/
        void highFivesGuys(void);
};

#endif
