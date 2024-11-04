#include "iter.hpp"
#include <iostream>

/*testing function to print array element*/
template <typename T> void printElement(const T &element)
{
	std::cout << element << " ";
}

/*testing function to multiply by 2 int type arr*/
template <typename T> void twosMultiple(T &element)
{
	element = element * 2;
}

int	main(void)
{
	int			arr[] = {1, 2, 3, 4, 5};
	const int	constarr[] = {2, 4, 6, 8, 10};
	std::string strArr[] = {"Hello", "World", "!"};
	
	std::cout << "Original int array: ";
	iter(arr, 5, printElement<int>);
	std::cout << std::endl;
	std::cout << "Multiply by two: ";
	iter(arr, 5, twosMultiple<int>);
	iter(arr, 5, printElement<int>);
	std::cout << std::endl;
	std::cout << "String array: ";
	iter(strArr, 3, printElement<std::string>);
	std::cout << std::endl;
	std::cout << "Const int array: ";
	iter(constarr, 3, printElement<int>);
	std::cout << std::endl;
	return (0);
}
