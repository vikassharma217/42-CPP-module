#include "Array.hpp"

// Default constructor
template <typename T> 
Array<T>::Array()
{
	element = NULL;
	_size = 0;
}

/* Parameterized constructor to allocate memory for n elements */
template <typename T> 
Array<T>::Array(unsigned int n)
{
	element = new T[n]();
	_size = n;
}

/* Copy constructor to create a deep copy of another Array */
template <typename T> 
Array<T>::Array(const Array &rhs)
{
	element = NULL;
	_size = rhs._size;
	if (_size > 0)
	{
		element = new T[_size];
		for (unsigned int i = 0; i < _size; ++i)
		{
			element[i] = rhs.element[i];
		}
	}
}

/* Copy assignment operator to assign one Array to another by 
	allocation new memory  */
template <typename T> 
Array<T> &Array<T>::operator=(const Array &rhs)
{
	if (this != &rhs)
	{                     
		delete[] element; // Clean up existing memory
		_size = rhs._size;
		if (_size > 0)
			element = new T[_size];
		else
			element = NULL;
		for (unsigned int i = 0; i < _size; ++i)
		{
			element[i] = rhs.element[i];
		}
	}
	return (*this);
}

// Destructor
template <typename T> 
Array<T>::~Array()
{
	delete[] element;
}

/* Non-const subscript operator with bounds checking */
template <typename T> 
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
	{
		throw std::out_of_range("Index out of range");
	}
	return (element[index]);
}

/* Const subscript operator with bounds checking */
template <typename T> 
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
	{
		throw std::out_of_range("Index out of range");
	}
	return (element[index]);
}

// Size member function
template <typename T> 
unsigned int Array<T>::size() const
{
	return (_size);
}
