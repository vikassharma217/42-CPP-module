# include "Bureaucrat.hpp"
# include <iostream>

int main ()
{
    /*test case for valid grade*/
    try
    {
        Bureaucrat b1 ("B1", 50); //calling constructor with initi
        std::cout << b1 << std::endl;

        //Bureaucrat b2 ("B2", 0); //calling constructor with initi
        //std::cout << b2 << std::endl;

        Bureaucrat b3 ("B3", 1); //calling constructor with initi
        std::cout << b3 << std::endl;

        Bureaucrat b4 ("B4", 150); //calling constructor with initi
        std::cout << b4 << std::endl;

        Bureaucrat b5 ("B5", 149); //calling constructor with initi
        std::cout << b5 << std::endl;

        
    }
    
    /*test case for grade increment/decrement methods*/

    /*test case for invalid grade*/

    /*more mixed test cases*/
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return (0);
}