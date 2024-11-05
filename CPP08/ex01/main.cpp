#include "Span.hpp"
#include <iostream>
#include <vector>

int main() 
{
    /*test case in subject*/
    try 
    {
        Span sp = Span(5);
        sp.addNumber(2147483647);
        sp.addNumber(-2);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    /*edge case of having one numebr or no number*/
    // try 
    // {
    //     Span spSingle = Span(0);
    //     spSingle.addNumber(42);
    //     std::cout << "Shortest span : " << spSingle.shortestSpan() << std::endl;
    // } 
    // catch (const std::exception& e) 
    // {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }

    // try 
    // {
    //     Span spSingle = Span(-1);
    //     spSingle.addNumber(42);
    //     std::cout << "Longest span : " << spSingle.longestSpan() << std::endl;
    // } 
    // catch (const std::exception& e) 
    // {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }

    // /*test case with 10,000 size*/
    // try 
    // {
    //     Span spLarge = Span(10000);
    //     for (int i = 0; i < 10000; ++i) 
    //     {
    //         spLarge.addNumber(i * 2);  // Adding even numbers to ensure a pattern
    //     }

    //     std::cout << "Shortest span in 10,000 numbers: " << spLarge.shortestSpan() << std::endl;
    //     std::cout << "Longest span in 10,000 numbers: " << spLarge.longestSpan() << std::endl;
    // } 
    // catch (const std::exception& e) 
    // {
    //     std::cerr << "Exception in large test: " << e.what() << std::endl;
    // }

//     /*test case to add multiple number at same time*/
//    try {
//         Span sp5 = Span(15);
//         sp5.addNumber(12);

//         // Create a vector with numbers to add
//         int arr[] = {4, 0, 3423, 43, 456, 5787, -10, 800};
//         std::vector<int> nums(arr, arr + sizeof(arr)/sizeof(arr[0]));
//         // Use addMany with iterators
//         sp5.addMany(nums);

//         std::cout << "Shortest span: " << sp5.shortestSpan() << std::endl;
//         std::cout << "Longest span: " << sp5.longestSpan() << std::endl;
//     } 
//     catch (const std::exception& e) 
//     {
//         std::cerr << "Exception: " << e.what() << std::endl;
//     }
    

    return 0;
}
