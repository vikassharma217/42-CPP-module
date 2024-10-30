# include <iostream>
# include "Array.hpp"


int main() 
{
    // Test default constructor
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;

    // Test parameterized constructor
    Array<int> intArray(5);
    for (unsigned int i = 0; i < intArray.size(); ++i) 
    {
        intArray[i] = i * 2;
    }

    std::cout << "Integer array elements: ";
    for (unsigned int i = 0; i < intArray.size(); ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    // Test copy constructor
    Array<int> copyArray = intArray;
    std::cout << "Copied array elements: ";
    for (unsigned int i = 0; i < copyArray.size(); ++i) {
        std::cout << copyArray[i] << " ";
    }
    std::cout << std::endl;

    // Test assignment operator
    Array<int> assignArray(3);
    assignArray = intArray;
    std::cout << "Assigned array elements: ";
    for (unsigned int i = 0; i < assignArray.size(); ++i) {
        std::cout << assignArray[i] << " ";
    }
    std::cout << std::endl;

    // Test out-of-bounds access
    try 
    {
        std::cout << "Accessing out-of-bounds: " << intArray[10] << std::endl;
    } 
    catch (const std::out_of_range& e) 
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
