#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

// MutantStack class template inheriting from std::stack
// This class will allow iteration over the stack elements using iterators

template <typename T> class MutantStack : public std::stack<T>
{
  public:
	MutantStack();
	MutantStack(const MutantStack &other);
	MutantStack &operator=(const MutantStack &other);
	~MutantStack();

	// Type aliases for iterator types
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

	// Iterator functions
	iterator begin();
	iterator end();
	reverse_iterator rbegin();
	reverse_iterator rend();
};

# include "MutantStack.tpp"

#endif
