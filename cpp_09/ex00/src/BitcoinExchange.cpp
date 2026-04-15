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

	std::ifstream file(filename.c_str());

	if (!file.is_open())
		throw std::runtime_error("Could not open database file");

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line)) {

		std::string		date;
		std::string		strPrice;
		float			price;
		size_t			pos;

		pos = line.find(" | ");
		if (pos == std::string::npos) {
			std::cerr << RED << "Error: bad input => " << line << RESET << "\n";
			continue;
		}

		date = line.substr(0, pos);

		if (!isValidDate(date)) {
    		std::cerr << RED << "Error: bad input => " << line << RESET << "\n";
    		continue;
		}

		strPrice = line.substr(pos + 3);

		std::stringstream ss(strPrice);

		if (!(ss >> price)) {
			std::cerr << RED << "Error: bad input => " << line << RESET << "\n";
			continue;
		}

		std::string remaining;
		ss >> remaining;
		if (!remaining.empty()) {
			std::cerr << RED << "Error: bad input => " << line << RESET << "\n";
			continue;
		}

		if (price < 0) {
			std::cerr << RED << "Error: not a positive number." << RESET << "\n";
			continue;
		}

		if (price > 1000) {
			std::cerr << RED << "Error: too large a number." << RESET << "\n";
			continue;
		}

		float	dbPrice = getPrice(date);

		if (dbPrice < 0)
			continue;

		std::cout << GREEN << date << " => " << price 
          << " = " << price * dbPrice << RESET << "\n";
	}
}

float	BitcoinExchange::getPrice(std::string const &date) const {

	std::map<std::string, float>::const_iterator it = _db.lower_bound(date);

	if (it == _db.begin() && it->first != date) {
		std::cerr << RED << "Error: date out of range" << RESET << "\n";
		return -1;
	}

	if (it == _db.end() || it->first != date) {
		--it;
	}

	return it->second;
}

bool BitcoinExchange::isValidDate(std::string const &date) const {
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;

    std::stringstream ss(date.substr(0, 4));
    int year;
    ss >> year;

    std::stringstream ss2(date.substr(5, 2));
    int month;
    ss2 >> month;

    std::stringstream ss3(date.substr(8, 2));
    int day;
    ss3 >> day;

    if (month < 1 || month > 12)
        return false;
    if (day < 1)
        return false;

    bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    int maxDay;
    switch (month) {
        case 2:
            maxDay = isLeap ? 29 : 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            maxDay = 30;
            break;
        default:
            maxDay = 31;
            break;
    }

    if (day > maxDay)
        return false;

    return true;
}
