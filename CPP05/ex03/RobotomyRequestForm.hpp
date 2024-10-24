#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib> // For rand()

class RobotomyRequestForm : public AForm
{
private:
    std::string _target;

public:
    // Constructor
    RobotomyRequestForm(const std::string &target);
    
    // Copy Constructor
    RobotomyRequestForm(const RobotomyRequestForm &rhs);
    
    // Assignment Operator
    RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
    
    // Destructor
    ~RobotomyRequestForm();

    // Execute the form
    void execute(Bureaucrat const &executor) const;
};

#endif
