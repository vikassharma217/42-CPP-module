#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

class Harl
{
    private:
        //privat memeber functions
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);

    public:
        //public member functions
        void complain(std::string level);
};

#endif