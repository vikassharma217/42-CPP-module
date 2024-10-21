#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>


class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _signed;
        const int _gradeSign;
        const int _gradeExecute;

    public:
        Form();
        Form (const Form &rhs); //copy constructor
        Form (std::string name, int gradeSign, int gradeExecute); 
        Form &operator=(const Form &rhs);
        ~Form();

    /*exception class*/
    class GradeTooHighException : public std::exception
	{
		public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
		const char *what() const throw();
	};

    /*getter for attributes*/
    std::string getName() const;
    bool isSigned() const; // sign status on form
    int getGradeSign() const;
    int getGradeExecute() const;

    /*member function to sign the form*/
    void beSigned(Bureaucrat& b);

};

/*overload insertion << operator*/
std::ostream &operator<<(std::ostream &out, const Form &f);

#endif