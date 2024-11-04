#include "Array.hpp"
#include <iostream>


int	main(void)
{
	/*Test default constructor*/
	Array<int> a1;
	// std::cout << "Default array locaion: " << &a1 << std::endl;
	std::cout << "Array Size: " << a1.size() << std::endl;

	/*Test parameterized constructor*/ 
	Array<int> a2(10);
	for (unsigned int i = 0; i < a2.size(); ++i)
	{
		a2[i] = i * 2;
	}

	// std::cout << "Int array locaion: " << &a2 << std::endl;
	std::cout << "Integer array elements: ";
	for (unsigned int i = 0; i < a2.size(); ++i)
	{
		std::cout << a2[i] << " ";
	}
	std::cout << std::endl;

	/*Test copy constructor*/ 
	Array<int> a3 = a2;
	// std::cout << "Copied array locaion: " << &a3 << std::endl;
	std::cout << "Copied array elements: ";
	for (unsigned int i = 0; i < a3.size(); ++i)
	{
		std::cout << a3[i] << " ";
	}
	std::cout << std::endl;

	/*Test assignment operator*/ 
	Array<int> a4(5);
	a4 = a2;
	// std::cout << "Assigned array locaion: " << &a4 << std::endl;
	std::cout << "Assigned array elements: ";
	for (unsigned int i = 0; i < a4.size(); ++i)
	{
		std::cout << a4[i] << " ";
	}
	std::cout << std::endl;

	/* test range */
	try
	{
		std::cout << "Trying to access: " << a2[3] << std::endl;
	}
	catch (const std::out_of_range &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return (0);
}


/*function to print array*/
// template <typename T>
// void	printArray(T array, unsigned int size)
// {
// 	for (unsigned int i = 0; i < size; ++i)
// 	{
// 		std::cout << array[i] << " ";
// 	}
// 	std::cout << std::endl;
// }

// int	main(void)
// {
// 	/*Test default constructor*/
// 	Array<int> a1;
// 	// std::cout << "Default array locaion: " << &a1 << std::endl;
// 	std::cout << "Array Size: " << a1.size() << std::endl;

// 	/*Test parameterized constructor*/ 
// 	Array<int> a2(10);
// 	for (unsigned int i = 0; i < a2.size(); ++i)
// 	{
// 		a2[i] = i * 2;
// 	}

// 	// std::cout << "Int array locaion: " << &a2 << std::endl;
// 	std::cout << "Integer array elements: ";
// 	printArray(a2, 5);

// 	/*Test copy constructor*/ 
// 	Array<int> a3 = a2;
// 	// std::cout << "Copied array locaion: " << &a3 << std::endl;
// 	std::cout << "Copied array elements: ";
// 	printArray(a3, 10);

// 	/*Test assignment operator*/ 
// 	Array<int> a4(5);
// 	a4 = a2;
// 	// std::cout << "Assigned array locaion: " << &a4 << std::endl;
// 	std::cout << "Assigned array elements: ";
// 	printArray(a4, 10);

// 	/* test range */
// 	try
// 	{
// 		std::cout << "Trying to access: " << a2[3] << std::endl;
// 	}
// 	catch (const std::out_of_range &e)
// 	{
// 		std::cout << "Exception: " << e.what() << std::endl;
// 	}
// 	return (0);
// }

// int main ()
// {
// 	Array<std::string> s1(3);
// 	s1[0] = "Hello";
// 	s1[1] = "Array";
// 	s1[2] = "World";

// 	std::cout << "String content: " << std::endl;
// 	printArray(s1, 3);

// 	return (0);
// }