#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& rhs);
        PmergeMe& operator=(const PmergeMe& rhs);
        ~PmergeMe();

        void sortInVector(std::vector<int>& inputVec);
        void sortInDeque(std::deque<int>& inputDeq);

        static void printResult(const std::string& label, const std::vector<int>& vec, 
                                double time, int size);
        static void printResult(const std::string& label, const std::deque<int>& vec, 
                                double time, int size);

    private:
        void mergeNSortVector(std::vector<int>& inputVec, const std::vector<int>& leftVec, const std::vector<int>& rightVec);
        void mergeNSortDeque(std::deque<int>& inputDeq, const std::deque<int>& leftDeq, const std::deque<int>& rightDeq);
};

#endif