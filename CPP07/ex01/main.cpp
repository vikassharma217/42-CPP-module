#include <iostream>
#include "iter.hpp"

/*testing function to print array element*/
template <typename T>
void printElement(const T &element) 
{
    std::cout << element << " ";
}

/*testing function to increament int type arr*/
template <typename T>
void incrementElement(T &element) 
{
    ++element;
}

int main() 
{
    int arr[] = {1, 2, 3, 4, 5};
    std::string strArr[] = {"Hello", "C++", "Templates"};

    std::cout << "Original int array: ";
    iter(arr, 5, printElement<int>);
    std::cout << "\nIncremented int array: ";
    iter(arr, 5, incrementElement<int>);
    iter(arr, 5, printElement<int>);
    std::cout << "\n";

    std::cout << "String array: ";
    iter(strArr, 3, printElement<std::string>);
    std::cout << "\n";

    return 0;
}
