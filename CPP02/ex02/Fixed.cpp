#include "Fixed.hpp"

// Default constructor
Fixed::Fixed()
{
	_fixedValue = 0;
}

/*Integer constructor, shift the int to fit into the
	fixed point value format */
Fixed::Fixed(const int number)
{
	_fixedValue = number << _fracBits; // Convert int to fixed-point
}

/* Float constructor, convert the float into fixed point format */
Fixed::Fixed(const float number)
{
	_fixedValue = roundf(number * (1 << _fracBits));
}

// Copy constructor
Fixed::Fixed(const Fixed &rhs)
{
	*this = rhs;
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &rhs)
{
	if (this != &rhs)
		_fixedValue = rhs._fixedValue;
	return (*this);
}

// Destructor
Fixed::~Fixed()
{
}

// Convert to int
int Fixed::toInt(void) const
{
	int result = _fixedValue >> _fracBits;
	return (result);
}

// Convert to float
float Fixed::toFloat(void) const
{
	float result = (float)_fixedValue / (1 << _fracBits);
	return (result);
}

/*===============Comparision operators=============================*/
bool Fixed::operator>(const Fixed &rhs) const
{
	bool result = _fixedValue > rhs._fixedValue;
	return (result);
}

bool Fixed::operator<(const Fixed &rhs) const
{
	bool result = _fixedValue < rhs._fixedValue;
	return (result);
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	bool result = _fixedValue >= rhs._fixedValue;
	return (result);
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	bool result = _fixedValue <= rhs._fixedValue;
	return (result);
}

bool Fixed::operator==(const Fixed &rhs) const
{
	bool result = _fixedValue == rhs._fixedValue;
	return (result);
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	bool result = _fixedValue != rhs._fixedValue;
	return (result);
}

/*===============Arithmatic operator================================*/

Fixed Fixed::operator+(const Fixed &rhs) const
{
	Fixed result;
	int value = _fixedValue + rhs._fixedValue;
	result.setRawBits(value);
	return (result);
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	Fixed result;
	int value = _fixedValue - rhs._fixedValue;
	result.setRawBits(value);
	return (result);
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	Fixed result;
	int value = (_fixedValue * rhs._fixedValue) >> _fracBits;
	result.setRawBits(value);
	return (result);
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	if (rhs.getRawBits() == 0)
	{
		std::cerr << "Error: Division by 0 will crash the programme." << std::endl;
		return (*this);
	}
	Fixed result;
	int value = (_fixedValue << _fracBits) / rhs._fixedValue;
	result.setRawBits(value);
	return (result);
}

/*===================Increment and Decrement operators===============*/

Fixed Fixed::operator++()
{
	_fixedValue++;
	return (*this);
}

/* Post-increment operator */
Fixed Fixed::operator++(int)
{
	Fixed	temp;

	temp = *this;
	_fixedValue++;
	return (temp);
}

Fixed Fixed::operator--()
{
	_fixedValue--;
	return (*this);
}

/* Post-decrement operator */
Fixed Fixed::operator--(int)
{
	Fixed	temp;

	temp = *this;
	_fixedValue--;
	return (temp);
}

/*============min/max fucntions====================*/

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

// Static const max function
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

// Getter for raw bits
int Fixed::getRawBits(void) const
{
	return (_fixedValue);
}

// Setter for raw bits
void Fixed::setRawBits(int const raw)
{
	_fixedValue = raw;
}

/* Overload << operator for output
 Print the float representation of the fixed-point value */
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
