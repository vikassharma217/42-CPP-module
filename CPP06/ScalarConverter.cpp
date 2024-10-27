# include "ScalarConverter.hpp"
# include <iostream>
# include <string>
# include <sstream>
# include <iomanip>
# include <climits>
# include <limits>

ScalarConverter::ScalarConverter() 
{
}
ScalarConverter::ScalarConverter(const ScalarConverter &) 
{
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) 
{ 
    return *this; 
}
ScalarConverter::~ScalarConverter() 
{
}

void ScalarConverter::convert(const std::string &input)
{
    ConverterUtils utils;  //utils class for conversion method
    /*char conversion: call stoi to try to covert input in ASCII dec value
    throw invalid_argument if out of range , else convert to char using 
    static_cast*/
    try 
    {
        int intValue = utils.ftStoi(input);
        if (intValue < 32 || intValue > 126)
        {
            throw std::invalid_argument("Non displayable");
        }
        char charValue = static_cast<char>(intValue);
        std::cout << "char: '" << charValue << "'" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "char: " << e.what() << std::endl;
    }

    /*integer conversion: */
    try
    {
        int intValue = utils.ftStoi(input);
        std::cout << "int: " << intValue << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "int: " << e.what () << std::endl;
    }

    /*float conversion*/
    try
    {
        float floatValue;
        if (input == "nan" || input == "-inf" || input == "+inf" || input == "inf")
            floatValue = utils.ftStof(input);
        else
        {
            std::stringstream ss(input);
            ss >> floatValue;
            if (ss.fail() || !ss.eof())
                throw std::invalid_argument("impossible");
        }
        std::cout << std::fixed << std::setprecision(1) << "float: " << floatValue << "f" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "float:" <<e.what() << std::endl;
    }

        /*Double conversion: */
    try 
    {
        double doubleValue;
        if (input == "nan" || input == "-inf" || input == "+inf" || input == "inf") {
            doubleValue = utils.ftStod(input);
        } 
        else 
        {
            std::stringstream ss(input);
            ss >> doubleValue;
            if (ss.fail() || !ss.eof()) throw std::invalid_argument("impossible");
        }
        std::cout << std::fixed << std::setprecision(1) << "double: " << doubleValue << std::endl;
    } 
    catch (const std::exception &e) 
    {
        std::cerr << "double: " << e.what() << std::endl;
    }
}

/*helper function for stoi ,stod & stof*/

int ScalarConverter::ConverterUtils::ftStoi(const std::string &input)
{
    std::istringstream iss(input);
    int value;
    iss >> value;

    if (iss.fail() || !iss.eof() || value == INT_MAX || value == INT_MIN)
    {
        throw std::invalid_argument("impossible");
    }
    return (value);
}

float ScalarConverter::ConverterUtils::ftStof(const std::string &input) {
    if (input == "nan" || input == "-inf" || input == "+inf" || input == "inf") {
        return std::numeric_limits<float>::quiet_NaN();
    }
    std::istringstream iss(input);
    float value;
    iss >> value;
    if (iss.fail() || !iss.eof()) {
        throw std::invalid_argument("impossible");
    }
    return value;
}

double ScalarConverter::ConverterUtils::ftStod(const std::string &input) {
    if (input == "nan" || input == "-inf" || input == "+inf" || input == "inf") {
        return std::numeric_limits<double>::quiet_NaN();
    }
    std::istringstream iss(input);
    double value;
    iss >> value;
    if (iss.fail() || !iss.eof()) {
        throw std::invalid_argument("impossible");
    }
    return value;
}

char ScalarConverter::ConverterUtils::ftStoc(const std::string &input) {
    int intValue = ftStoi(input);
    if (intValue < 32 || intValue > 126) {
        throw std::invalid_argument("Non displayable");
    }
    return static_cast<char>(intValue);
}

