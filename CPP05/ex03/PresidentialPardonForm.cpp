#include "PresidentialPardonForm.hpp"

/*default constructor*/
PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : 
    AForm("PresidentialPardonForm", 25, 5), 
    _target(target)
{
    // std::cout << "Presedential constructor." << std::endl;
}

/*copy cosntructor*/
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs) : 
    AForm(rhs), 
    _target(rhs._target)
{
    // std::cout << "Presedential copy constructor." << std::endl;
}

/*copy assignment operator*/
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        _target = rhs._target;
    }
    return *this;
}

/*default destructor*/
PresidentialPardonForm::~PresidentialPardonForm() 
{
    // std::cout << "Presidential destructor." << std::endl;
}

/*execute method for presidential form*/
void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (!isSigned())
        throw AForm::FormProceededException();

    if (executor.getGrade() > getGradeExecute())
        throw AForm::GradeTooLowException();

    std::cout << "\033[32m" << _target 
        << " has been pardoned by Zaphod Beeblebrox.\033[0m" << std::endl;
}