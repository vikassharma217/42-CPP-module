#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter 
{
public:
    // static method for conversion
    static void convert(const std::string &input);

    
private:
    /*move constructor and destructor to private to 
        prevent instantiation*/
    ScalarConverter();
    ScalarConverter(const ScalarConverter &rhs);
    ScalarConverter &operator=(const ScalarConverter &rhs);
    ~ScalarConverter();

public:
    /*nested helper class for conversion*/
    class ConverterUtils
    {
        public:
            int ftStoi (const std::string &input);
            float ftStof (const std::string &input);
            double ftStod (const std::string &input);
            char ftStoc (const std::string &input);
    };
};

#endif