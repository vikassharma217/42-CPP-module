#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
  private:
	int _fixPtNumValue;
	static const int _fractionalBits = 8;

  public:
	// default constructor
	Fixed();

	// copy constructor
	Fixed(const Fixed &rhs);

	// copy assignment operator
	Fixed &operator=(const Fixed &rhs);

	// destructor
	~Fixed();

    // getter function for raw bits
    int getRawBits(void) const;

    //setter function for raw bits
    void setRawBits (int const raw);
};

#endif