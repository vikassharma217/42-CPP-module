#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

/* Default Constructor */
Intern::Intern()
{
	// std::cout << "Intern created." << std::endl;
}

/* Copy Constructor */
Intern::Intern(const Intern &rhs)
{
	(void)rhs;
	// std::cout << "Intern copied." << std::endl;
}

/* Assignment Operator */
Intern &Intern::operator=(const Intern &rhs)
{
	// std::cout << "Intern assigned." << std::endl;
	(void)rhs;
	return (*this);
}

/* Destructor */
Intern::~Intern()
{
	// std::cout << "Intern destroyed." << std::endl;
}

/* makeForm function */

AForm *Intern::makeForm(std::string formName, std::string target)
{
	std::string forms[3] = {
		"shrubbery creation", 
		"robotomy request",
		"presidential pardon"};

	int result = -1;
	for (int i = 0; i < 3; i++)
	{
		if (formName.compare(forms[i]) == 0)
		{
			result = i;
			break ;
		}
	}

	switch (result)
	{
	case 0:
        std::cout << "Inter creates " << formName << std::endl;
		return (new ShrubberyCreationForm(target));
	case 1:
        std::cout << "Inter creates " << formName << std::endl;
		return (new RobotomyRequestForm(target));
	case 2:
        std::cout << "Inter creates " << formName << std::endl;
		return (new PresidentialPardonForm(target));
	default:
		throw std::runtime_error("Error: Invalid Form");
	}
}