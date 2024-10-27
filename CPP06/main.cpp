# include "ScalarConverter.hpp"
# include <iostream>
# include <string>

int main (int argc, char **argv)
{
  if (argc != 2)
  {
    std::cerr << "Error: Invalid arguments." << std::endl;
    std::cerr << "./convert <INPUT>" << std::endl;
    return (1);
  }

  std::string input;
  input = argv[1];
  ScalarConverter::convert(input);
  
  return(0);
}