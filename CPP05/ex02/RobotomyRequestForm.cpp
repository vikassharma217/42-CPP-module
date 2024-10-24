#include "RobotomyRequestForm.hpp"
#include <cstdlib> // for rand()
#include <ctime>   // for srand()
#include <iostream>

/*default constructor*/
RobotomyRequestForm::RobotomyRequestForm() : _target("Default")
{

}
/*parametrized constructor*/
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm",
	72, 45), _target(target)
{
	//std::cout << "Robotomy constructor." << std::endl;
	std::srand(std::time(0)); // Seed the random number generator
}

/*copy constructor*/
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs) : AForm(rhs),
	_target(rhs._target)
{
	// std::cout << "Robotomy copy constructor." << std::endl;
}

/*copy assignment operator*/
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		_target = rhs._target;
	}
	return (*this);
}

/*default destructor*/
RobotomyRequestForm::~RobotomyRequestForm()
{
	// std::cout << "Robotomy default destructor." << std::endl;
}

/*execute method for robotomy*/
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!isSigned())
		throw AForm::FormProceededException();

	if (executor.getGrade() > getGradeExecute())
		throw AForm::GradeTooLowException();

	std::cout << "\033[31m===>===>DRILLING===>\033[0m" << std::endl;

	// Randomly determine success or failure (50% chance)
	if (std::rand() % 2 == 0)
	{
		std::cout << _target << " has been robotomized succesfully!" << std::endl;
	}
	else
	{
		std::cout << _target << " has failed the Robotomy!" << std::endl;
	}
}
