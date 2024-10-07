#include "Fixed.hpp"
#include <iostream>

int main(void)
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;

    return (0);
}

/*int main (void)
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << "intial value of a: " << a << std::endl;
    std::cout << "intial value of b: " << b << std::endl;

    std::cout << "Max: " << Fixed::max(a, b) << std::endl;

    a = Fixed(42.12f); //assigning new float value to a
    std::cout << "New value of a: " << a << std::endl;

    Fixed c(10);
    Fixed d(0);

    std::cout << "Division C/D = " << c/d << std::endl;

    Fixed x (42.24f);
    Fixed y (12.12f);

    Fixed &largNum =  Fixed::max(x, y);
    const Fixed &largeNum1 = Fixed::max(x, y);

    largNum.setRawBits(100);
    //largeNum1.setRawBits(100);

    std::cout << "Large num:  " << largNum << std::endl;
    std::cout << "Large num1: " << largeNum1 << std::endl;


    return (0);
}*/
