#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <deque>
# include <string>
# include <vector>

class PmergeMe
{
  public:
	PmergeMe();
	PmergeMe(const PmergeMe &rhs);
	PmergeMe &operator=(const PmergeMe &rhs);
	~PmergeMe();

	void sortInVector(std::vector<int> &inputVec);
	void sortInDeque(std::deque<int> &inputDeq);

	static void printSortingTime(const std::string containerName, double time,
		int size);
};

#endif