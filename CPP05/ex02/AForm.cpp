# include "AForm.hpp"
# include "Bureaucrat.hpp"

/*default constructor*/
AForm::AForm() :
    _name("Defautl"),
    _signed(false),
    _gradeSign(0),
    _gradeExecute(0)
{
    //std::cout << "AForm default constructor." << std::endl;
}

/*paremterized constructor*/
AForm::AForm(const std::string &name, int gradeSign, int gradeExecute) :
    _name(name),
    _signed(false),
    _gradeSign(gradeSign),
    _gradeExecute(gradeExecute)
{
    if (gradeSign < 1 || gradeExecute < 1)
        throw (GradeTooHighException());
    if (gradeSign > 150 || gradeExecute > 150)
        throw (GradeTooLowException());
}

/*copy constructor*/
AForm::AForm(const AForm &rhs) :
    _name(rhs._name),
    _signed(rhs._signed),
    _gradeSign(rhs._gradeSign),
    _gradeExecute(rhs._gradeExecute)
{
    // std::cout << "AForm copy consttructor." << std::endl;
}

/* Assignment operator */
AForm &AForm::operator=(const AForm &rhs)
{
    if (this != &rhs)
    {
        _signed = rhs._signed;
    }
    return (*this);
}

/*Default destructor*/
AForm::~AForm()
{
    // std::cout << "AForm destructor." << std::endl; 
}

/*getter*/
std::string AForm::getName() const
{
    return (_name);
}

bool AForm::isSigned() const
{
    return (_signed);
}

int AForm::getGradeSign() const
{
    return (_gradeSign);
}

int AForm::getGradeExecute() const
{
    return (_gradeExecute);
}

/*fucntion to signed the form depend upon passed bereaucrated grade */
void AForm::beSigned(const Bureaucrat& b)
{
    if (_signed)
    {
        // std::cout << "Form " << _name << " is already signed." << std::endl;
        return;
    }
    if (b.getGrade() > _gradeSign)
    {
        throw GradeTooLowException();
    }
    _signed = true;
}

/*exception handleing*/

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Form sign/execution Grade is too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Form sign/execution Grade is too low!");
}

const char *AForm::FormProceededException::what() const throw()
{
    return ("Form is not Proceeded!");
}


/*overload << operator*/

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
	out << "\033[34m"
		<< "Forms Info:: Name: " << f.getName() <<
			", Sign Grade: " << f.getGradeSign() <<
			", Execute Grade: " << f.getGradeExecute() <<
			", Sign status: " << (f.isSigned() ? "Yes" : "No") << "\033[0m";
	return (out);
}