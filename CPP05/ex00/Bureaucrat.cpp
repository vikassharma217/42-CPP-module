# include "Bureaucrat.hpp"

/* basic requirments*/
Bureaucrat::Bureaucrat()
{
    std::cout << "Default constructor." << std::endl; 
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs)
{
    std::cout << "Copy constructor." << std::endl;
    _name = rhs._name;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
    std::cout << "Assignment operator." << std::endl;
    if (this != rhs)
        _name = rhs._name;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor." << std::endl;
}

/*getter method implementatiton*/

