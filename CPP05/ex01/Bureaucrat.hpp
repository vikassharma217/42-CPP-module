#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "Form.hpp"
# include <exception>
# include <iostream>
# include <string>

class Bureaucrat
{
  private:
	const std::string _name;
	int _grade;

  public:
	Bureaucrat(); // defaut constructor
	Bureaucrat(const std::string& name, int grade); // constructor with init list
	Bureaucrat(const Bureaucrat &rhs); // copy constructor
	Bureaucrat &operator=(const Bureaucrat &rhs);
	~Bureaucrat();

	/*getters*/
	std::string getName() const;
	int getGrade() const;

	/*member function to increament and decrement grade*/
	void gradeIncreament();
	void gradeDecreament();

	/*exception classes*/
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
	
	/*additional memeber function*/
	 void signForm(Form f);
	 //void executeForm(Form f);
};

/* overlaod insertion (<<) operator*/
std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

/*unit test*/
	void testBureaucratCreation();
    void testGradeIncreament();
    void testGradeDecrement();
    void testInvalidBureaucratCreation();

#endif