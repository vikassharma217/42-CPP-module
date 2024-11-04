#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

// MutantStack class template inheriting from std::stack
// This class will allow iteration over the stack elements using iterators

template <typename T>
class MutantStack : public std::stack<T> {
public:
    // Type aliases for iterator types (valid in C++98)
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

    // Constructor
    MutantStack();

    // Copy constructor
    MutantStack(const MutantStack& other);

    // Assignment operator
    MutantStack& operator=(const MutantStack& other);

    // Destructor
    ~MutantStack();

    // Iterator functions
    iterator begin();
    iterator end();

    const_iterator begin() const;
    const_iterator end() const;

    reverse_iterator rbegin();
    reverse_iterator rend();

    const_reverse_iterator rbegin() const;
    const_reverse_iterator rend() const;
};

# include "MutantStack.tpp"

#endif // MUTANTSTACK_HPP
