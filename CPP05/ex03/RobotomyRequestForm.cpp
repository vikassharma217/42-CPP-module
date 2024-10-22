#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>  // for rand()
#include <ctime>    // for srand()

/*default constructor*/
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : 
    AForm("RobotomyRequestForm", 72, 45), 
    _target(target)
{
    // std::cout << "Robotomy constructor." << std::endl;
    std::srand(std::time(0));  // Seed the random number generator
}

/*copy constructor*/
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : 
    AForm(other), 
    _target(other._target)
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
    return *this;
}

/*default destructor*/
RobotomyRequestForm::~RobotomyRequestForm() 
{
    // std::cout << "Robotomy default destructor." << std::endl;
}

/*execute method for robotomy*/
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    // Check if form is signed
    if (!isSigned())
        throw AForm::FormProceededException();

    // Check if executor has the grade to execute
    if (executor.getGrade() > getGradeExecute())
        throw AForm::GradeTooLowException();

    // Simulate robotomy
    std::cout << "===>===>DRILLING===>*" << std::endl;
    
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
