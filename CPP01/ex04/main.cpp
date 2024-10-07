#include "FileProcessor.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: Invalid arguments" << std::endl;
		std::cerr << "Correct args: ./replace [filName] [S1] [s2]" << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (s1.empty())
	{
		std::cerr << "Error: s1 can not be empty." << std::endl;
		return (1);
	}
	FileProcessor fileProcessor(filename, s1, s2);
	fileProcessor.processFile();
	return (0);
}
