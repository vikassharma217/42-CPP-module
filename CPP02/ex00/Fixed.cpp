# include "Fixed.hpp"

Fixed::Fixed()
{
    _fixPtNumValue = 0;
    std::cout << "Default constructor called" << std::endl; 
}

//copy constructor
Fixed::Fixed(const Fixed &rhs)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_fixPtNumValue = rhs.getRawBits();
}

/*copy assignment operator*/
Fixed &Fixed::operator = (const Fixed &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_fixPtNumValue = rhs.getRawBits();
    return *this;
}

// destructor
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits memeber fucntion called" << std::endl;
    return (this->_fixPtNumValue);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function" << std::endl;
    this->_fixPtNumValue = raw;
}

