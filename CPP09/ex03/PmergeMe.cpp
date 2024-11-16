# include "PmergeMe.hpp"
# include <iostream>
# include <stdexcept>
# include <ctime>
# include <iomanip>

/*default constructor*/
PmergeMe::PmergeMe()
{
}

/*copy constructor*/
PmergeMe::PmergeMe(const PmergeMe& rhs)
{
    (void)rhs;
}

/*assignment operator*/
PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
    (void)rhs;
    return *this;
}

/*default destructor*/
PmergeMe::~PmergeMe()
{
}

/*print sorted vector and time to sort*/
void PmergeMe::printSortingTime(const std::string containerName, double time, int size) 
{
    std::cout << "Time to process a range of " << size 
              << " element with " << containerName << std::fixed
              << std::setprecision(5) << time << " us" << std::endl;
}