#include "PmergeMe.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <stdexcept>

/*default constructor*/
PmergeMe::PmergeMe()
{
}

/*copy constructor*/
PmergeMe::PmergeMe(const PmergeMe &rhs)
{
	(void)rhs;
}

/*assignment operator*/
PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	(void)rhs;
	return (*this);
}

/*default destructor*/
PmergeMe::~PmergeMe()
{
}

/*print sorted vector and time to sort*/
void PmergeMe::printSortingTime(const std::string containerName, double time,
	int size)
{
	std::cout << "Time to process a range of " << size << " element with " << containerName << std::fixed << std::setprecision(5) << time << " us" << std::endl;
}

/*helper function: merge and sort for vector*/
void	mergeNSortVector(std::vector<int> &inputVec,
		const std::vector<int> &leftVec, const std::vector<int> &rightVec)
{
	size_t	i = 0, j = 0, k;

	i = 0, j = 0, k = 0;
	while (i < leftVec.size() && j < rightVec.size())
	{
		if (leftVec[i] <= rightVec[j])
		{
			inputVec[k++] = leftVec[i++];
		}
		else
		{
			inputVec[k++] = rightVec[j++];
		}
	}
	while (i < leftVec.size())
	{
		inputVec[k++] = leftVec[i++];
	}
	while (j < rightVec.size())
	{
		inputVec[k++] = rightVec[j++];
	}
}

/*Implemnent Merge-Insertion sort for vector*/
void PmergeMe::sortInVector(std::vector<int> &inputVec)
{
	size_t	mid;

	if (inputVec.size() <= 1) // Base case: Single element or empty array
		return ;
	mid = inputVec.size() / 2;
	std::vector<int> leftVec(inputVec.begin(), inputVec.begin() + mid);
	std::vector<int> rightVec(inputVec.begin() + mid, inputVec.end());
	sortInVector(leftVec);  // Recursively sort left half
	sortInVector(rightVec); // Recursively sort right half
	mergeNSortVector(inputVec, leftVec, rightVec); // Merge sorted halves
}

/*helper function: merge and sort for deque*/
void	mergeNSortDeque(std::deque<int> &inputDeq,
		const std::deque<int> &leftDeq, const std::deque<int> &rightDeq)
{
	size_t	i = 0, j = 0, k;

	i = 0, j = 0, k = 0;
	while (i < leftDeq.size() && j < rightDeq.size())
	{
		if (leftDeq[i] <= rightDeq[j])
		{
			inputDeq[k++] = leftDeq[i++];
		}
		else
		{
			inputDeq[k++] = rightDeq[j++];
		}
	}
	while (i < leftDeq.size())
	{
		inputDeq[k++] = leftDeq[i++];
	}
	while (j < rightDeq.size())
	{
		inputDeq[k++] = rightDeq[j++];
	}
}

/*Implementation of Merge-Insertion sort for deque*/
void PmergeMe::sortInDeque(std::deque<int> &inputDeq)
{
	if (inputDeq.size() <= 1) // Base case: Single element or empty array
		return ;

	size_t mid = inputDeq.size() / 2;
	std::deque<int> leftDeq(inputDeq.begin(), inputDeq.begin() + mid);
	std::deque<int> rightDeq(inputDeq.begin() + mid, inputDeq.end());

	sortInDeque(leftDeq);  // Recursively sort left half
	sortInDeque(rightDeq); // Recursively sort right half

	mergeNSortDeque(inputDeq, leftDeq, rightDeq); // Merge sorted halves
}