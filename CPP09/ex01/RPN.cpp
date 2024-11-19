# include "RPN.hpp"
# include <iostream>
# include <sstream>
# include <stack>
# include <string>
# include <cctype>

bool isValidInput(const std::string input) 
{
    std::istringstream tokens(input);
    std::string tok;
    int numCount = 0;
    int operatorCount = 0;

    while (tokens >> tok) 
    {
        // Check if the token is a single-digit number
        if (tok.size() == 1 && std::isdigit(tok[0])) 
            numCount++;
        // Check if the token is a valid operator
        else if (tok == "+" || tok == "-" || tok == "*" || tok == "/") 
        {
            operatorCount++;
            // Ensure there are enough operands for this operator
            if (numCount < 2) 
            {
                std::cerr << "Error: Not enough operands for operator '" << tok << "'." << std::endl;
                return (false);
            }
            numCount--;  // Using an operator reduces operands by 1
        } 
        else 
        {
            // pritn error for invalid token
            std::cerr << "Error: Invalid token '" << tok << "' in expression." << std::endl;
            return (false);
        }
    }
    // there shud be only one number present in the end
    if (numCount != 1 || operatorCount < 1) 
    {
        std::cerr << "Error: Invalid RPN format." << std::endl;
        return (false);
    }
    return (true);
}


bool excuteRPN(const std::string& input, float& result)
{
    std::stack<float> rpnStack;
    std::istringstream tokens(input);
    std::string tok;

    while (tokens >> tok)
    {
        if (std::isdigit(tok[0]))
            rpnStack.push(tok[0] - '0');
        else
        {
            float num1 = rpnStack.top();
            rpnStack.pop();
            float num2 = rpnStack.top();
            rpnStack.pop();
            if (tok == "+")
                rpnStack.push(num2 + num1);
            else if (tok == "-")
                rpnStack.push(num2 - num1);
            else if (tok == "*")
                rpnStack.push(num2 * num1);
            else if (tok == "/")
            {
                if (num1 == 0)
                {
                    std::cerr << "Error: Division by zero." << std::endl;
                    return (false);
                }
                rpnStack.push(num2 / num1);
            }
        }
    }
    result = rpnStack.top();
    return (true);
}


