#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8;

    public:
        // default constrcutor
        Fixed();

        // copy constructor that take an int
        Fixed(const int number);

        //copy constrcutor that taked a float
        Fixed(const float number);

        //copy constructor
        Fixed (const Fixed &rhs);

        // copy assignment operator
        Fixed &operator = (const Fixed &rhs);

        ~Fixed();

        // member function
        float toFloat(void) const;
        int toInt(void) const;

        // getter and setter fucntions
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

// Overload << operator for output
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif