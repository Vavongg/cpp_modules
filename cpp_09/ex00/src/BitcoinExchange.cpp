#include "../include/BitcoinExchange.hpp"

//canonical form

BitcoinExchange::BitcoinExchange() {

}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy) {

	_db = copy._db;
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &copy) {

	if (this != &copy)
		_db = copy._db;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {

}

//methods

void	BitcoinExchange::loadDatabase(std::string const &filename) {

	std::ifstream file(filename.c_str());

	if (!file.is_open())
		throw std::runtime_error("Could not open database file");
	
	std::string	line;
	std::getline(file, line);

	while (std::getline(file, line)) {
		
		std::stringstream	ss(line);
		std::string			date;
		float				price;

		std::getline(ss, date, ',');
		ss >> price;

		_db[date] = price;
	}
}

void	BitcoinExchange::processInput(std::string const &filename) {

}
