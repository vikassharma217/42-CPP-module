#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

class Fixed
{
  private:
	int _fixedValue; 
	static const int _fracBits = 8;

  public:
	Fixed();
	Fixed(const int number);
	Fixed(const float number);
	Fixed(const Fixed &rhs);            // Copy constructor
	Fixed &operator=(const Fixed &rhs); // Copy assignment(=) operator
	~Fixed();

	// Conversion functions
	float toFloat(void) const;
	int toInt(void) const;

	// Comparison operators
	bool operator>(const Fixed &rhs) const;
	bool operator<(const Fixed &rhs) const;
	bool operator>=(const Fixed &rhs) const;
	bool operator<=(const Fixed &rhs) const;
	bool operator==(const Fixed &rhs) const;
	bool operator!=(const Fixed &rhs) const;

	// Arithmetic operators
	Fixed operator+(const Fixed &rhs) const;
	Fixed operator-(const Fixed &rhs) const;
	Fixed operator*(const Fixed &rhs) const;
	Fixed operator/(const Fixed &rhs) const;

	// Increment and Decrement operators
	Fixed operator++();    // Pre-increment
	Fixed operator++(int); // Post-increment
	Fixed operator--();    // Pre-decrement
	Fixed operator--(int); // Post-decrement

	// Static min/max functions
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);

	// Getter and Setter for raw bits
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

// Overload << operator for output
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
