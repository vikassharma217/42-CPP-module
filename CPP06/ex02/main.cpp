#include "Utils.hpp"
#include <iostream>

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));

    Base* obj = generate();
    std::cout << "Identify by pointer: ";
    identify(obj);

    std::cout << "Identify by reference: ";
    identify(*obj);

    delete obj; // Clean up the dynamically allocated object
    return 0;
}
