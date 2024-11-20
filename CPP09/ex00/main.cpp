#include "BitcoinExchange.hpp"
#include <iostream>
#include <map>

int	main(int argc, char *argv[])
{
	// Check for correct argument count
	if (argc != 2)
	{
		std::cerr << "Error: input file is missing." << std::endl;
		return (1);
	}

	// Load the database
	std::map<std::string, float> priceData;
	if (!loadDatabase("data.csv", priceData))
	{
		std::cerr << "Error: failed to load data.csv" << std::endl;
		return (1);
	}

	// Process the input file
	std::string inputFile = argv[1];
	if (!validateProcessInput(inputFile, priceData))
	{
		std::cerr << "Error: failed to process " << inputFile << "." << std::endl;
		return (1);
	}

	return (0);
}