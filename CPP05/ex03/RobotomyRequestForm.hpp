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
    RobotomyRequestForm(const RobotomyRequestForm &other);
    
    // Assignment Operator
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
    
    // Destructor
    ~RobotomyRequestForm();

    // Execute the form
    void execute(Bureaucrat const &executor) const;
};

#endif
