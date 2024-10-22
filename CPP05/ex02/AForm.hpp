#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _signed;
        const int _gradeSign;
        const int _gradeExecute;

    public:
        AForm ();
        AForm (const std::string &name, int gradeSign, int gradeExecute); // init constructor
        AForm (const AForm &rhs);
        AForm &operator=(const AForm &rhs);
        virtual ~AForm(); // abstract class

    /*getter method*/
        std::string getName() const;
        bool isSigned() const;
        int getGradeSign() const;
        int getGradeExecute() const;

    /*member function*/
        void beSigned(const Bureaucrat &b);

    /*pure virtual function for derived class*/
        virtual void execute( Bureaucrat const & executor) const = 0;

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
    /*exception class to check if form is signed and executed*/
        class FormProceededException : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

#endif