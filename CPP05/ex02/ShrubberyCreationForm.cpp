# include "ShrubberyCreationForm.hpp"
# include <fstream>
# include <string>

/*default constructor*/
ShrubberyCreationForm::ShrubberyCreationForm() : _target("Default")
{
}

/*parametrized constructor*/
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : 
        AForm("ShrubberyCreationForm", 145, 137), 
        _target(target) 
{
    // std::cout << "Schrubbery constructor." << std::endl;
}

/*copy constructor*/
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs) : 
    AForm(rhs), 
    _target(rhs._target) 
{
    // std::cout << "Scrubbery copy constructor." << std::endl;
}

/*copy assignment operator*/
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
    // std::cout << "Scrubbery assignment operator." << std::endl;
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        _target = rhs._target;
    }
    return *this;
}

/*Default desturctor*/
ShrubberyCreationForm::~ShrubberyCreationForm() 
{
    // std::cout << "Schrubbery destructor" << std::endl;
}

/*execute function*/
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!isSigned())
        throw AForm::FormProceededException();
    if (executor.getGrade() > getGradeExecute())
        throw AForm::GradeTooLowException();

    std::ofstream file((_target + "_shrubbery").c_str());
    if (file.is_open())
    {
        file << "   #   " << std::endl
             << "  ###  " << std::endl
             << " ##### " << std::endl
             << "   #   " << std::endl
             << "   #   " << std::endl
             << "ASCII trees" << std::endl 
             << "   🌳   " << std::endl
             << "  🌲🌲  " << std::endl
             << " 🌲🌲🌲 " << std::endl
             << "   🟫   " << std::endl
             << "   🟫   " << std::endl
             << "# emoji tree #" << std::endl;
        file.close();
    }
    else
    {
        std::cerr << "Error: File can not be opened." << std::endl;
    }
}
