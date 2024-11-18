#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

// Loads the database from data.csv
bool loadDatabase(const std::string& dbFilename, std::map<std::string, float>& priceData) 
{
    std::ifstream dataFile(dbFilename.c_str());
    if (!dataFile.is_open()) 
    {
        std::cerr << "Error: could not open file " << dbFilename << std::endl;
        return (false);
    }

    std::string line;
    while (std::getline(dataFile, line)) 
    {
        //std::cout << line; 
        std::stringstream ss(line);
        std::string date;
        float price;
        if (std::getline(ss, date, ',') && ss >> price)  // getline() delimited by ,
        {
            priceData[date] = price; // store the data in map[key] = value
        }
    }
    dataFile.close();
    return (true);
}

/*leap year either (divisible by 400) or (divisibile by 4 but not by 100) */
bool handleLeapYear(int year)
{
    bool isLeap = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    return (isLeap);
}

// Validates date format (YYYY-MM-DD) with basic string manipulation
bool isValidDate(const std::string& date) 
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') 
        return (false);
    int year, month, day;
    std::istringstream yearStream(date.substr(0, 4));
    std::istringstream monthStream(date.substr(5, 2));
    std::istringstream dayStream(date.substr(8, 2));

    if (!(yearStream >> year) || !(monthStream >> month) || !(dayStream >> day)) 
        return (false);
    // Basic range checking for month and day
    if (month < 1 || month > 12 || day < 1) 
        return (false);
    // max days in month 
    int daysMonthwise[] = {31,(handleLeapYear(year) ? 29 : 28), 31,30,31,30,31,31,30,31,30,31};
    return (day <= daysMonthwise[month - 1]);
}

// Checks if quantity is positive
bool isQuantityPositive(float quantity) 
{
    return (quantity > 0);
}

// Checks if quantity is within the range [0, 1000]
bool isQuantityInRange(float quantity) {

    return (quantity <= 1000);
}

// Finds the closest date for a given date in the database
float getPriceForDate(const std::string& date, const std::map<std::string, float>& priceData) 
{
    std::map<std::string, float>::const_iterator it = priceData.lower_bound(date);
    if (it == priceData.end() || it->first != date) 
    {
        if (it == priceData.begin()) 
        {
            return (-1.0f); // No valid date found
        }
        --it; // Use closest previous date
    }
    return it->second;
}

// Main function to validate, process input, and calculate the result
bool validateProcessInput(const std::string& inputFile, const std::map<std::string, float>& priceData) 
{
    std::ifstream file(inputFile.c_str());
    if (!file.is_open()) 
    {
        std::cerr << "Error: could not open file." << std::endl;
        return (false);
    }

    std::string line, date;
    float quantity;
    bool isFirstLine = true;
    while (std::getline(file, line)) 
    {
        // Check and skip the header line
        if (isFirstLine) 
        {
            if (line == "date | value") 
            {
                isFirstLine = false;
                continue;
            } 
            else 
            {
                std::cerr << "Error: bad input format => " << line << std::endl;
                return (false);
            }
        }

        std::stringstream ss(line);
        if (std::getline(ss, date, '|') && ss >> quantity) 
        {
             // Trim whitespace around date
            size_t start = date.find_first_not_of(" \n\r\t");
            size_t end = date.find_last_not_of(" \n\r\t");
            if (start == std::string::npos || end == std::string::npos) 
            {
                std::cerr << "Error: bad input => " << std::endl;
                continue;
            }
            date = date.substr(start, end - start + 1);

            // Validate the date format
            if (!isValidDate(date)) 
            {
                std::cerr << "Error: bad input => " << date << std::endl;
                continue;
            }

            // Check if quantity is positive and in range
            if (!isQuantityPositive(quantity)) 
            {
                std::cerr << "Error: not a positive number." << std::endl;
                continue;
            }
            if (!isQuantityInRange(quantity)) 
            {
                std::cerr << "Error: Max quantity is 1000." << std::endl;
                continue;
            }

            // Retrieve the price and print the result
            float price = getPriceForDate(date, priceData);
            if (price == -1.0f) 
            {
                std::cerr << "Error: no price available for date " << date << std::endl;
                continue;
            }
            std::cout << date << " => " << quantity << " = " << (quantity * price) << std::endl;
        } 
        else 
            std::cerr << "Error: bad input format => " << line << std::endl;
    }
    file.close();
    return (true);
}
