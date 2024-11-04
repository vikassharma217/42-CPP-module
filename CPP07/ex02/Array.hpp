#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>

template <typename T> 
class Array
{
  private:
	T *element;
	unsigned int _size;

  public:
	Array(); //default construtor
	Array(unsigned int n); // constructor with unsigned int
	Array(const Array &rhs); // copy constructor
	Array &operator=(const Array &rhs); // copy assignmenet operator
	~Array();

	T &operator[](unsigned int index);
	const T &operator[](unsigned int index) const;

	unsigned int size() const;
};


# include "Array.tpp"
#endif