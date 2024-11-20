// BitcoinExchange.hpp

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>

// Function prototypes
bool	loadDatabase(const std::string &dbFilename, std::map<std::string,
			float> &priceData);
bool	validateProcessInput(const std::string &inputFile,
			const std::map<std::string, float> &priceData);
bool	isValidDate(const std::string &date);
bool	isQuantityPositive(float quantity);
bool	isQuantityInRange(float quantity);
float	getPriceForDate(const std::string &date, const std::map<std::string,
			float> &priceData);

#endif // BITCOINEXCHANGE_HPP
