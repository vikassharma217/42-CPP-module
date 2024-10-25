#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include "iostream"

class ScalarConverter
{
    /*moved constructor.... in  private to prevent instatite the class*/
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &rhs);
        ScalarConverter &operator=(const ScalarConverter &rhs);
        ~ScalarConverter();

    public:
        /*method to conver*/
        static void convert(std::string input);
        static void outputChar;
        
};

#endif