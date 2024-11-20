#include "PmergeMe.hpp"
#include <cstdlib>
#include <ctime> // for clock function
#include <deque>
#include <iostream>
#include <vector>

/*validate the input; must be digit, skip the first '-',
	check for emty input "" or " "*/
bool	isValidInput(const char *str)
{
	if (*str == '-')
		++str;
	if (!*str)
		return (false);
	while (*str)
	{
		if (!std::isdigit(*str))
			return (false);
		++str;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: Input cannot be empty." << std::endl;
		return (1);
	}

	std::vector<int> inputVec;
	std::deque<int> inputDeq;

	{
		for (int i = 1; i < argc; ++i)
		{
			if (!isValidInput(argv[i]))
			{
				std::cerr << "Error: Input should be digit only." << std::endl;
				return (1);
			}
			int num = std::atoi(argv[i]);
			if (num <= 0)
			{
				std::cerr << "Error: Input must be a positive integer." << std::endl;
				return (1);
			}
			inputVec.push_back(num);
			inputDeq.push_back(num);
		}
	}

	std::cout << "Before: ";
	for (int i = 1; i < argc; ++i)
	{
		std::cout << argv[i] << " ";
	}
	std::cout << std::endl;

	PmergeMe s1;

	// Sort vector
	clock_t start = clock();
	s1.sortInVector(inputVec);
	clock_t stop = clock();
	double vectorTime = static_cast<double>(stop - start) / CLOCKS_PER_SEC * 1e6;

	// Sort deque
	start = clock();
	s1.sortInDeque(inputDeq);
	stop = clock();
	double dequeTime = static_cast<double>(stop - start) / CLOCKS_PER_SEC * 1e6;

	/*print the sorted container*/
	std::cout << "After: ";
	for (std::vector<int>::iterator it = inputVec.begin(); it != inputVec.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	//  /*print the sorted container*/
	// std::cout << "After: ";
	// for (std::deque<int>::iterator it = inputDeq.begin(); it != inputDeq.end(); ++it)
	// {
	//     std::cout << *it << " ";
	// }
	// std::cout << std::endl;

	s1.printSortingTime("std::vector: ", vectorTime, inputVec.size());
	s1.printSortingTime("std::deque: ", dequeTime, inputDeq.size());
	return (0);
}