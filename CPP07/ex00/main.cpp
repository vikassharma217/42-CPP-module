# include "whatever.hpp"
# include <iostream>

int main( void ) 
{
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0;
}

// int main ()
// {
//     bool a = true;
//     bool b = false;

//     std::cout << "Befor swap :" << std::endl;
//     std::cout << "a: " <<a << "   " << "b: " <<  b << std::endl;
//     ::swap (a,b);
//     std::cout << "a: " <<a << "   " << "b: " <<  b << std::endl;

//     int c = 100;
//     int d = -24;

//     std::cout << "Befor swap :" << std::endl;
//     std::cout << "c: " << c << "   " << "d: " << d << std::endl;
//     std::cout << "Min: " << ::min(c,d) << std::endl;
//     std::cout << "Max: " << ::max(c,d) << std::endl;
//     ::swap (c,d);
//     std::cout << "After swap :" << std::endl;
//     std::cout << "c: " << c << "   " << "d: " <<  d << std::endl;
//     std::cout << "Min: " << ::min(c,d) << std::endl;
//     std::cout << "Max: " << ::max(c,d) << std::endl;

//     float e = 42.042f;
//     float f = 42.041f;

//     std::cout << "Befor swap :" << std::endl;
//     std::cout << "e: " << e << "   " << "f: " << f << std::endl;
//     std::cout << "Min: " << ::min(e,f) << std::endl;
//     std::cout << "Max: " << ::max(e,f) << std::endl;
//     ::swap (e,f);
//     std::cout << "After swap :" << std::endl;
//     std::cout << "e: " << e << "   " << "f: " <<  f << std::endl;
//     std::cout << "Min: " << ::min(e,f) << std::endl;
//     std::cout << "Max: " << ::max(e,f) << std::endl;

//     return (0);
// }