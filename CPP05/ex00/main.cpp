#include "Bureaucrat.hpp"
#include <iostream>

int	main(void)
{
	try
	{
		Bureaucrat a1("A1", 150); // calling constructor with parameter
		std::cout << a1 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	// /*test case for valid grade*/
	// try
	// {
	//     Bureaucrat b1 ("B1", 50); //calling constructor with initi
	//     std::cout << b1 << std::endl;
	//     Bureaucrat b2 ("B2", 1); //calling constructor with initi
	//     std::cout << b2 << std::endl;
	//     Bureaucrat b3 ("B3", 150); //calling constructor with initi
	//     std::cout << b3 << std::endl;
	//     Bureaucrat b4 ("B4", 0); //calling constructor with initi
	//     std::cout << b4 << std::endl;
	// }
	// catch (const std::exception& e)
	// {
	//     std::cerr << "Exception: " << e.what() << std::endl;
	// }
	//     /*test case for grade increment/decrement methods*/
	//    try
	//    {
	//         Bureaucrat c1("Test1", 149);
	//         std::cout << c1 << std::endl;
	//         c1.gradeDecreament();  // Valid, should reduce grade to 150
	//         std::cout << c1 << std::endl;
	//         Bureaucrat c2("Test2", 3);
	//         std::cout << c2 << std::endl;
	//         c2.gradeIncreament(); 
		// This should throw an exception (GradeTooHighException)
	//         std::cout << c2 << std::endl;
	//     }
	//     catch (const std::exception& e)
	//     {
	//         std::cerr << "Exception: " << e.what() << std::endl;
	//     }
	return (0);
}
