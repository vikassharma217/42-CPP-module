#include "ScalarConverter.hpp"
#include <climits>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

/*constructor and destructors*/
ScalarConverter::ScalarConverter()
{
}
ScalarConverter::ScalarConverter(const ScalarConverter &rhs)
{
	(void)rhs;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
	(void)rhs;
	return (*this);
}
ScalarConverter::~ScalarConverter()
{
}

/*main covert function,  handel special cases for nan, inf etc.,*/
void ScalarConverter::convert(const std::string &input)
{
	ConverterUtils	utils;
	char			charValue;
	int				intValue;
	float			floatValue;
	double			doubleValue;

	/*instatialte util class for conversion utils*/
	/* Handle single character input directly and cast into decimal rep from ASCII table*/
	if (input.length() == 1 && std::isprint(input[0])
		&& !std::isdigit(input[0]))
	{
		charValue = input[0];
		intValue = static_cast<int>(charValue);
		floatValue = static_cast<float>(charValue);
		doubleValue = static_cast<double>(charValue);
		std::cout << "char: '" << charValue << "'" << std::endl;
		std::cout << "int: " << intValue << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
		std::cout << "double: " << doubleValue << std::endl;
		return ;
	}
	// Handle special cases for nan and infinity
	if (input == "nan" || input == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return ;
	}
	if (input == "-inf" || input == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return ;
	}
	if (input == "+inf" || input == "+inff" || input == "inf"
		|| input == "inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
		return ;
	}
	// Conversion for standard numeric input
	try
	{
		double doubleValue = utils.ftStod(input); // convert to double
		float floatValue = utils.ftStof(input);   // conver to flaot
		// Char and int conversion based on double conversion
		if (doubleValue >= INT_MIN && doubleValue <= INT_MAX)
		{
			intValue = static_cast<int>(doubleValue);
			if (intValue >= 32 && intValue <= 126)
			{
				std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;
			}
			else
			{
				std::cout << "char: Non displayable" << std::endl;
			}
			// Integer output
			std::cout << "int: " << intValue << std::endl;
		}
		else
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
		}
		// Float output
		std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
		// Double output
		std::cout << "double: " << std::fixed << std::setprecision(1) << doubleValue << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "char: impossible" << std::endl;
		std::cerr << "int: impossible" << std::endl;
		std::cerr << "float: impossible" << std::endl;
		std::cerr << "double: impossible" << std::endl;
	}
}

/*helper function for stoi ,stod & stof*/

int ScalarConverter::ConverterUtils::ftStoi(const std::string &input)
{
	int	value;

	std::istringstream iss(input);
	iss >> value;
	if (iss.fail() || !iss.eof() || value == INT_MAX || value == INT_MIN)
	{
		throw std::invalid_argument("impossible");
	}
	return (value);
}

float ScalarConverter::ConverterUtils::ftStof(const std::string &input)
{
	float	value;

	std::string modifiedInput = input;
	if (!modifiedInput.empty() && modifiedInput[modifiedInput.size()
		- 1] == 'f')
	{
		modifiedInput.resize(modifiedInput.size() - 1); // Remove the 'f'
	}
	std::istringstream iss(modifiedInput);
	iss >> value;
	if (iss.fail() || !iss.eof())
	{
		throw std::invalid_argument("impossible");
	}
	return (value);
}

double ScalarConverter::ConverterUtils::ftStod(const std::string &input)
{
	double	value;

	std::string modifiedInput = input;
	if (!modifiedInput.empty() && modifiedInput[modifiedInput.size()
		- 1] == 'f')
	{
		modifiedInput.resize(modifiedInput.size() - 1); // Remove the 'f'
	}
	std::istringstream iss(modifiedInput);
	iss >> value;
	if (iss.fail() || !iss.eof())
	{
		throw std::invalid_argument("impossible");
	}
	return (value);
}
