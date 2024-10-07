# include "Harl.hpp"
# include <iostream>

int main (void)
{
    Harl harl;
    harl.complain("WARNING");
    std::cout << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;
    harl.complain("WOW");
    return (0);
}