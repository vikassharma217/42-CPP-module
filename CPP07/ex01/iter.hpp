#ifndef ITER_HPP
# define ITER_HPP

template <typename T, typename F> 
void iter(T *array, int len, F function)
{
	for (int i = 0; i < len; ++i)
	{
		function(array[i]);
	}
}

#endif