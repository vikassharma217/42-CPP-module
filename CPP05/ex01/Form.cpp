# include "Form.hpp"

/*default constructor*/
Form::Form():
    _name("Default"),
    _signed(false),
    _gradeSign(0),
    _gradeExecute(0)
{
    std::cout << "Default Form constructor." << std::endl;
}


/*cosntructor for initilyźing const variables*/
Form::Form(std::string name, int gradeSign, int gradeExecute): 
        _name(name),
        _signed(false),
        _gradeSign(gradeSign),
        _gradeExecute(gradeExecute)
{
    if (gradeSign < 1 || gradeExecute < 1)
        throw GradeTooHighException();
    if (gradeSign > 150 || gradeExecute > 150)
        throw GradeTooLowException();
}



/*copy constructor*/
Form::Form(const Form &rhs) :
    _name(rhs._name),
    _signed(rhs._signed),
    _gradeSign(rhs._gradeSign),
    _gradeExecute(rhs._gradeExecute)
{
    std::cout << "Form copy consttructor." << std::endl;
}

/*assignment operator onöy to copy non const variables*/
Form& Form::operator=(const Form &rhs)
{
    if (this != &rhs)
    {
        _signed = rhs._signed;
    }
    return (*this);
}

Form::~Form()
{
    std::cout << "Default Form destructor." << std::endl;
}

/*exception handeling*/
const char* Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low!");
}

/*getter functions*/
std::string Form::getName() const
{
    return (_name);
}

bool Form::isSigned() const
{
    return (_signed);
}

int Form::getGradeSign() const
{
    return (_gradeSign);
}

int Form::getGradeExecute() const
{
    return (_gradeExecute);
}

/*fucntion to signed the form depend upon passed bereaucrated grade */
void Form::beSigned(Bureaucrat b)
{
    if (b.getGrade() > _gradeSign)
        throw (GradeTooLowException());
    _signed = true;
}

/*function to print the form signed status*/
void Form::signForm(Bureaucrat b)
{
    try
    {
        beSigned(b);
        std::cout << b.getName() << " signed "<< _name << std::endl;     
    }
    catch(const std::exception& e)
    {
        std::cerr << b.getName() << "  couldn't sign "<< _name 
            << " beacause "<< e.what() << std::endl;
    }
    
}

/*overload << operator*/

std::ostream& operator<<(std::ostream &out, const Form &f)
{
    out << "Form: " <<f.getName() << std::endl 
        << "Sign Grade: " << f.getGradeSign() << std::endl
        << "Execute Grade: " << f.getGradeExecute() << std::endl 
        << "Sign status: "<< (f.isSigned() ? "Yes" : "No"); 
    return (out);
}