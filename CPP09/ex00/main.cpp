# include "BitcoinExchange.hpp"
# include <iostream>
# include <map>
# include <string>
# include <fstream>
# include <sstream>

int main ()
{
    BitcoinExchange ex1;
    if (ex1.readData("data.csv"))
    {
        std::cout << "Date: 2012-09-26: Price: " << ex1.getPrice("2012-09-26") << std::endl;
    }
    return (0);
}