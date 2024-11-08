# include "RPN.hpp"
# include <iostream>
# include <stack>
# include <sstream>
# include <string>

int main (int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: Invalid arguments." << std::endl;
        return (1);
    }
    std::string input = argv[1];
    if (!isValidInput(input))
    {
        return (1);
    }
    float result = excuteRPN(input);
    std::cout << "Result: " << result << std::endl;
    return (0);
}