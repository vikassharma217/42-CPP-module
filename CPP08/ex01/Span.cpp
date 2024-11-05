# include "Span.hpp"
# include <limits>
# include <iostream>

/*default constructor*/
Span::Span() : maxSize(0)
{
}

/*parameterized constructor*/
Span::Span(unsigned int n) : maxSize(n)
{ 
    if (static_cast<int>(n) < 0)
    {
        throw std::invalid_argument("Error: span size cannot be negative.");
    }
    //std::cout << "Vector constructed with size: " << maxSize << std::endl;
}

/*copy constructor*/
Span::Span(const Span& rhs) :
    numVector(rhs.numVector),
    maxSize(rhs.maxSize)
{
}

/*copy assignment operator*/
Span& Span::operator=(const Span& rhs)
{
    if (this != &rhs)
    {
        numVector = rhs.numVector;
        maxSize = rhs.maxSize;
    }
    return (*this);
}

/*default destructor*/
Span::~Span()
{
}

/*member func to add single number to Span*/
void Span::addNumber(int num)
{
    if (numVector.size() >= maxSize)
    {
        throw (std::runtime_error("Error: cannot add more number."));
    }
    numVector.push_back(num); // push num to the end of vector
}

/*memebr func to add multiple number to Span*/
void Span::addMany(const std::vector<int>& newNum)
{
    if (numVector.size() + newNum.size() >= maxSize)
    {
        throw (std::runtime_error("Error: cannot add more numbers."));
    }
    //insert newNum vector (from begine to end) at the postion (end of numVector)
    numVector.insert(numVector.end(), newNum.begin(), newNum.end());
}

/*func to return the lonest span, we need to return the diffrence between 
    largest to smallest number*/

long Span::longestSpan()
{
    if (numVector.size() < 2)
    {
        throw (std::runtime_error("Error: no span can found."));
    }
    int smallestNum = *std::min_element(numVector.begin(), numVector.end());
    int largestNum = *std::max_element(numVector.begin(), numVector.end());
    return (static_cast<long>(largestNum) - static_cast<long>(smallestNum));
} 

/*func to return the shortest span between any two numbers, we need to return the 
    smallest diffrence between any two numbers */
long Span::shortestSpan()
{
    if (numVector.size() < 2)
    {
        throw std::runtime_error("Error: no span can found.");
    }
    std::vector<int> sortedVec = numVector;
    std::sort(sortedVec.begin(), sortedVec.end());
    long minDiff = std::numeric_limits<long>::max();
    for (size_t i = 1; i < sortedVec.size(); ++i)
    {
        long diff = static_cast<long>(sortedVec[i]) - static_cast<long>(sortedVec[i - 1]);
        minDiff = std::min(minDiff, diff);
    }
    return (minDiff);
}