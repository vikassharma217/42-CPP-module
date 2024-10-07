#include "Fixed.hpp"
#include <iostream>

int main() {
    Fixed a;               // Default constructor
    Fixed const b(10);      // Integer constructor
    Fixed const c(42.42f);  // Float constructor
    Fixed const d(b);       // Copy constructor

    a = Fixed(1234.4321f);  // Assign float constructor result to `a`

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    return 0;
}
