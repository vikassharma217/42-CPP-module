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
void PmergeMe::printResult(const std::string& label, const std::vector<int>& vec, 
                    double time, int size) 
{
    std::cout << label << ": ";
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) 
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of " << size 
              << " element with std::vector: " << std::fixed
              << std::setprecision(5) << time << " us" << std::endl;
}

/*print sorted deque and time to sort*/
void PmergeMe::printResult(const std::string& label, const std::deque<int>& deq, 
                    double time, int size) 
{
    std::cout << label << ": ";
    for (std::deque<int>::const_iterator it = deq.begin(); it != deq.end(); ++it) 
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of " << size 
              << " element with std::deque: " << std::fixed
              << std::setprecision(5) << time << " us" << std::endl;
}