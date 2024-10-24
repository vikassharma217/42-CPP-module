# include "Bureaucrat.hpp"
# include "AForm.hpp"

/* basic requirments*/
Bureaucrat::Bureaucrat()
{
    // std::cout << "Default constructor." << std::endl; 
}

/*constructor with init list as private member _name is const type*/
Bureaucrat::Bureaucrat(const std::string& name, int grade) : 
            _name(name),
            _grade(grade)
{
    // std::cout << "Constructor for " << name << std::endl;
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
}

/*copy constructor*/
Bureaucrat::Bureaucrat(const Bureaucrat &rhs) :
    _name(rhs._name),
    _grade(rhs._grade)
{
    // std::cout << "Copy constructor." << std::endl;
}

/*assignment operator*: 
    can not assogne const member _name    */
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
    // std::cout << "Assignment operator." << std::endl;
    if (this != &rhs)
        _grade = rhs._grade;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    // std::cout << "Destructor." << _name << std::endl;
}

/*getter method implementatiton*/
std::string Bureaucrat::getName() const
{
    return (_name);
}

int Bureaucrat::getGrade() const
{
    return (_grade);
}

/*membser function*/
/*increament the grade with validation that grade shud not be less than 1*/
void Bureaucrat::gradeIncreament()
{
    if (_grade -1 < 1)
        throw GradeTooHighException();
    _grade--;
}

/*decremeanent the grade with validation that grade shud not be more than 150*/
void Bureaucrat::gradeDecreament()
{
    if (_grade + 1 > 150)
        throw GradeTooLowException();
    _grade++;
}

/*exception handling methods*/
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Bureaucrat Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Bureaucrat Grade is too low!");
}

/*operator << overloading*/
std::ostream& operator<<(std::ostream & out, const Bureaucrat &b)
{
    out << b.getName() << ", bureaucrat  grade " << b.getGrade();
    return (out);
}


/*function to print the form signed status*/
void Bureaucrat::signForm(AForm &f)
{
    if (f.isSigned())  // Use the getter function to check if the form is signed
    {
        // std::cout << _name << " can't sign " << f.getName() << " because it's already signed." << std::endl;
        return;
    }

    try
    {
        f.beSigned(*this);  // Attempt to sign the form
        std::cout << _name << " signed " << f.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << _name << " couldn't sign " << f.getName()
                  << " because " << e.what() << std::endl;
    }
}

/*additional fucntion for executing form*/

void Bureaucrat::executeForm(AForm  &form)
{
    try 
    {
        form.execute(*this);  // Attempt to execute the form
        std::cout << _name << " executed " << form.getName() << std::endl;
    } 
    catch (const std::exception &e) 
    {
        std::cout << _name << " couldn't execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}