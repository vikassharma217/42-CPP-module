#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream> // for std::find
# include <algorithm> // for iterator defination
# include <iterator>
# include <exception>
# include <stdexcept>

/*tempalte declaration*/
template <typename T>
typename T::iterator  easyfind(T& param1, int param2);

# include "easyfind.tpp"

#endif
