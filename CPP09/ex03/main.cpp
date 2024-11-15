#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>

// Function to validate input (ensure numeric and positive)
bool isValidInput(const char* str) 
{
    while (*str) 
    {
        if (!std::isdigit(*str)) 
        {
            return false; 
        }
        ++str;
    }
    return true;
}

int main(int argc, char** argv) 
{
    if (argc < 2) 
    {
        std::cerr << "Error: Input cannot be empty." << std::endl;
        return 1;
    }

    std::vector<int> inputVec;
    std::deque<int> inputDeq;

    try 
    {
        for (int i = 1; i < argc; ++i) 
        {
            if (!isValidInput(argv[i])) 
            {
                std::cerr << "Error: Input should be digit only." << std::endl;
                return 1;
            }
            int num = std::atoi(argv[i]);
            if (num <= 0)
            {
                std::cerr << "Error: Input must be a positive integer." << std::endl;
                return 1;
            }
            inputVec.push_back(num);
            inputDeq.push_back(num);
        }
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Error: Invalid input - " << e.what() << std::endl;
        return 1;
    }

    std::cout << "Before: ";
    for (int i = 1; i < argc; ++i) 
    {
        std::cout << argv[i] << " ";
    }
    std::cout << std::endl;

    PmergeMe sorter;

    // Sort vector
    clock_t start = clock();
    sorter.sortInVector(inputVec);
    clock_t end = clock();
    double vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

    // Sort deque
    start = clock();
    sorter.sortInDeque(inputDeq);
    end = clock();
    double dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

  sorter.printResult("After (vector)", inputVec, vectorTime, inputVec.size());
sorter.printResult("After (deque)", inputDeq, dequeTime, inputDeq.size());
    return 0;
}
