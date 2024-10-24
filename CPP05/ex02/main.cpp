#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	try
	{
		// Bureaucrat creation
		Bureaucrat b1("B1", 1);
		Bureaucrat b2("B2", 149);

		// Shrubbery form
		ShrubberyCreationForm shrubbery("HOME");
		std::cout << std::endl;
		b2.signForm(shrubbery);
		b1.signForm(shrubbery);
		b1.executeForm(shrubbery);
		// Robotomytest
		RobotomyRequestForm robotomy("Robot");
		std::cout << std::endl;
		// Trying to sign and execute RobotomyRequestForm
		b2.signForm(robotomy);
		b1.signForm(robotomy);
		b1.executeForm(robotomy);
		// Presidentialtest
		PresidentialPardonForm pardon("USER");
		std::cout << std::endl;
		b2.signForm(pardon);
		b1.signForm(pardon);
		b1.executeForm(pardon);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return (0);
}

/*int main()
{
	try
	{
		// Edge Case 1: High-ranking bureaucrat should sign and execute everything successfully
		Bureaucrat b1("High Rank", 1);  // Grade 1, highest rank
		ShrubberyCreationForm shrubbery("Garden");
		RobotomyRequestForm robotomy("Robo");
		PresidentialPardonForm pardon("Bob");

		std::cout<<std::endl;
		std::cout << "High-Ranking Bureaucrat Signs and Executes Everything" <<std::endl;
		b1.signForm(shrubbery);
		b1.executeForm(shrubbery);  // Should create "Garden_shrubbery" file

		b1.signForm(robotomy);
		b1.executeForm(robotomy);   // Random chance of success or failure

		b1.signForm(pardon);
		b1.executeForm(pardon);     // Bob gets pardoned by the president

		// Edge Case 2: Low-ranking bureaucrat trying to sign or execute forms
			std::cout<<std::endl;
		Bureaucrat b2("Low Rank", 140);  // Grade 140,
			too low to sign or execute many forms
		ShrubberyCreationForm smallShrubbery("Tiny Garden");

		std::cout<<std::endl;
		std::cout << "Low-Ranking Bureaucrat Fails to Sign and Execute."<< std::endl;
		b2.signForm(smallShrubbery);    
			// Should fail to sign (requires grade 145)
		b2.executeForm(smallShrubbery); 
			// Should fail to execute because not signed

		// Edge Case 3: A form is signed but low-ranking bureaucrat fails to execute it
		Bureaucrat middleRanking("Middle Rank", 50);  // Grade 50,
			too low to execute high-level forms
		RobotomyRequestForm robotForm("Machine");

			std::cout<<std::endl;
		std::cout << "Middle-Ranking Bureaucrat Fails to Execute Robotomy" << std::endl;
		b1.signForm(robotForm);              // High-ranking signs it
		middleRanking.executeForm(robotForm);        
			// Middle-ranking fails to execute (requires grade 45)

		// Edge Case 4: Form is unsigned and execution is attempted
		PresidentialPardonForm unsignedPardon("Alice");

			std::cout<<std::endl;
		std::cout << "Attempt to Execute an Unsigned Form" << std::endl;
		b1.executeForm(unsignedPardon);      // Should fail as it is unsigned

	}

	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return (0);
}*/