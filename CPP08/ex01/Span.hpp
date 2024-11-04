#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>
# include <algorithm>

class Span
{
    public:
        Span();
        Span (unsigned int n); // paremeterized constructor
        Span(const Span &rhs);
        Span &operator=(const Span &rhs);
        ~Span();

        /*member functions*/
        void addNumber(int num);
        int shortestSpan();
        int longestSpan();
        /*member fucntion to add multiple numbers*/
        void addMany(const std::vector<int>& newNums);

    private:
       std::vector<int> numVector;
       unsigned int maxSize; 

};

#endif