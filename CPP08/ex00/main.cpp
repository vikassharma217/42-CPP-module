#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>


template <typename T>
void fillContainer(T& t1, int startValue)
{
    for (size_t i = 0; i <= 10; ++i)
    {
        t1.push_back(startValue++);
    }
}

int main() 
{
    /*testing for vector*/
    std::vector<int> myVec;
    fillContainer(myVec, 1);
    try 
    {
        std::vector<int>::iterator result = easyfind(myVec, 5);
        std::cout << "Value 5 found in vector at position: " 
                  << std::distance(myVec.begin(), result) << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Exception in vector: " << e.what() << std::endl;
    }

    /*testing for list*/
    std::list<int> myList;
    fillContainer(myList, 100);
    try
    {
        std::list<int>::iterator result = easyfind(myList, 8);
        std::cout << "Value 8 found in list at position: " 
                  << std::distance(myList.begin(), result) << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Exception in list: " << e.what() << std::endl;
    }

    /*testing for deque*/
    std::deque<int> myDeque;
    fillContainer(myDeque, 50);  
    try 
    {
        std::deque<int>::iterator result = easyfind(myDeque, 11);
        std::cout << "Value 11 found in deque at position: " 
                  << std::distance(myDeque.begin(), result) << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Exception in deque: " << e.what() << std::endl;
    }

    return 0;
}
