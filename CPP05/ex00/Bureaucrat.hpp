#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>
# include <string>

class Bureaucrat
{
  private:
	const std::string _name;
	int _grade;

  public:
	Bureaucrat();                                   
	Bureaucrat(const std::string &name, int grade); 
	Bureaucrat(const Bureaucrat &rhs);              
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
};

/* overlaod insertion (<<) operator*/
std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif