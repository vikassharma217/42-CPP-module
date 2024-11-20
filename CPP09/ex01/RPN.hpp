#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <stack>
# include <string>

bool	isValidInput(const std::string input);
bool	excuteRPN(const std::string &input, float &result);

#endif