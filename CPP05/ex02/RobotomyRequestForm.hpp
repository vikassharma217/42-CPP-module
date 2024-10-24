#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib> // For rand()

class RobotomyRequestForm : public AForm
{
private:
    std::string _target;

public:

    RobotomyRequestForm(); // default construtotr
    RobotomyRequestForm(const std::string &target); // Parametrized Constructor
    RobotomyRequestForm(const RobotomyRequestForm &rhs); // Copy Constructor
    RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs); // Assignment Operator
    ~RobotomyRequestForm(); // Destructor

    // Execute the form
    void execute(Bureaucrat const &executor) const;
};

#endif
