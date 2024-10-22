#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    // Create an Intern
    Intern intern;
    
    // Create forms with valid names
    std::cout << "\n=== Testing valid forms ===" << std::endl;

    AForm* shrubberyForm = intern.makeForm("shrubbery creation", "Garden");
    if (shrubberyForm)
    {
        std::cout << *shrubberyForm << std::endl;
        delete shrubberyForm;  // Clean up the created form
    }

    AForm* robotomyForm = intern.makeForm("robotomy request", "Robot");
    if (robotomyForm)
    {
        std::cout << *robotomyForm << std::endl;
        delete robotomyForm;  // Clean up the created form
    }

    AForm* pardonForm = intern.makeForm("presidential pardon", "Bob");
    if (pardonForm)
    {
        std::cout << *pardonForm << std::endl;
        delete pardonForm;  // Clean up the created form
    }

    // Try creating a form with an invalid name
    std::cout << "\n=== Testing invalid form ===" << std::endl;

    AForm* invalidForm = intern.makeForm("invalid form name", "Nobody");
    if (!invalidForm)
    {
        std::cout << "Failed to create form: invalid form name" << std::endl;
    }

    return 0;
}
