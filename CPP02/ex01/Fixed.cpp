# include "Fixed.hpp"

/*default constructor*/
Fixed::Fixed()
{
    _fixedPointValue = 0;
    std::cout << "Default constructor called" << std::endl;
}

/*constructor to take int*/
Fixed::Fixed(const int number)
{
    std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = number << _fractionalBits;
}

/*constrcutor to take float*/
Fixed::Fixed (const float number)
{
    std::cout << "Float constructor called" << std::endl;
    float value = number * (1 << _fractionalBits);
    _fixedPointValue = roundf(value);
}

/*copy constrcutor*/
Fixed::Fixed(const Fixed &rhs)
{
    std::cout << "Copy constructor called"<< std::endl;
    *this = rhs;
}

/*copy assignment operator*/
Fixed &Fixed::operator = (const Fixed &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->_fixedPointValue = rhs._fixedPointValue;
    }
    return *this;
}

/*destructor*/
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

/*function to convert fixed-point value to float*/
float Fixed::toFloat(void) const
{
    int value = 1 << _fractionalBits;
    float result = (float)_fixedPointValue / value;
    return (result);
    
}

/*function to convert fixe-point value to int*/
int Fixed::toInt(void) const
{
    int result = _fixedPointValue >> _fractionalBits;
    return (result);
}

/*getter fucntion to get the raw fixed-point value*/
int Fixed::getRawBits(void) const
{
    return (_fixedPointValue);
}

/*setter fucntion to set the raw fixed-point value*/
void Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
}

/* Overload << operator for output
 Print the float representation of the fixed-point value */
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

