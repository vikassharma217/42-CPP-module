#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>
# include <string>

bool isValidInput(const std::string input);
bool excuteRPN(const std::string& input, float& result);

#endif