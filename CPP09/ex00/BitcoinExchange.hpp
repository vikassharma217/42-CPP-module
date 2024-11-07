#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <string>

class BitcoinExchange
{
    public:
        BitcoinExchange();
        //BitcoinExchange (const BitcoinExchange &rhs);
        //BitcoinExchange &operator=(const BitcoinExchange &rhs);
        ~BitcoinExchange();

    private:
        // Conataine map to store date and price
        std::map<std::string, int> priceData;

    public:
        //method to read the form CSV file and popollate the map
        bool readData(const std::string& fileName);

        //method to retrive the price on given data
        int getPrice(const std::string& date) const;

        //print all data
        void printData() const;
};

#endif