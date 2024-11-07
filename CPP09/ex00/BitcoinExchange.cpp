# include "BitcoinExchange.hpp"
# include <iostream>
# include <map>
# include <string>
# include <fstream>
# include <sstream>

/*default things*/
BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){}

bool BitcoinExchange::readData(const std::string& fileName)
{
    std::ifstream file(fileName);
    if (!file.is_open())
    {
        std::cerr << "Error: file can not be opned." <<std::endl;
        return (false);
    }
    std::string line, date;
    int price;
    while (std::getline(file, line))
    {   
        std::stringstream ss(line);
        if (std::getline(ss, date, ',') && ss >> price)
        {
            priceData[date] = price;
        }
    }
    file.close();
    return (true);
}

/*implemetation of getPrice function*/
int BitcoinExchange::getPrice(const std::string& date)const
{
    auto it = priceData.find(date);
    if (it != priceData.end())
    {
        return (it->second);
    }
    else
    {
        std::cerr << "Date not found: " << date << std::endl;
        return (-1);
    }
}

/*implementation of print data*/
void BitcoinExchange::printData() const
{
    for (const auto& entry : priceData)
    {
        std::cout << "Data: " << entry.first << ", Price: " << entry.second << std::endl;
    }
}