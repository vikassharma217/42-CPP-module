#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

/* Default Constructor */
Intern::Intern()
{
    std::cout << "Intern created." << std::endl;
}

/* Copy Constructor */
Intern::Intern(const Intern &other)
{
    (void)other;
    std::cout << "Intern copied." << std::endl;
}

/* Assignment Operator */
Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    std::cout << "Intern assigned." << std::endl;
    return *this;
}

/* Destructor */
Intern::~Intern()
{
    std::cout << "Intern destroyed." << std::endl;
}

/* makeForm function */
AForm* Intern::makeForm(const std::string &formName, const std::string &target)
{
    AForm* forms[] = {
        new ShrubberyCreationForm(target),
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target)
    };

    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    for (int i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formNames[i] << std::endl;
            return forms[i];
        }
        delete forms[i];  // If not selected, delete to avoid memory leak
    }

    std::cout << "Error: Form name not found." << std::endl;
    return NULL;  // Return NULL as `nullptr` is not available in C++98
}
