#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// int	main(void)
// {
// 	Intern	someRandomIntern;
// 	AForm	*rrf;

// 	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
// 	delete	rrf;
// 	return (0);
// }

int main()
{
	try
	{
		Intern i1;
		Bureaucrat b1("B1", 1);
		Bureaucrat b2 ("B2", 150);

		AForm* shrubberyForm = i1.makeForm("shrubbery creation", "Home");
		if (shrubberyForm)
		{
			std::cout << *shrubberyForm << std::endl;
			b1.signForm(*shrubberyForm);
			b1.executeForm(*shrubberyForm);
			delete shrubberyForm;
		}

		AForm* robotomyForm = i1.makeForm("robotomy request", "Robot");
		if (robotomyForm)
		{
			std::cout << *robotomyForm << std::endl;
			delete robotomyForm;
		}

		AForm* pardonForm = i1.makeForm("presidential pardon", "Joe");
		if (pardonForm)
		{
			std::cout << *pardonForm << std::endl;
			delete pardonForm;
		}
		AForm* invalidForm = i1.makeForm("invalid", "wow");
		if (invalidForm)
		{
			std::cout << *invalidForm << std::endl;
			delete invalidForm;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    return (0);
}