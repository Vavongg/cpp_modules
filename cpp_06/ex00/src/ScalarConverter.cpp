/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 10:06:21 by ainthana          #+#    #+#             */
/*   Updated: 2026/03/09 11:37:37 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"
#include <cstdlib>
#include <climits>
#include <limits>
#include <cmath>
#include <iomanip>

//canonical form

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
	(void)copy;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &copy) {
	(void)copy;
	return *this;
}

ScalarConverter::~ScalarConverter() {
}

//checker

bool ScalarConverter::isChar(std::string const &str) {
	return (str.length() == 3 && str[0] == '\'' && str[2] == '\'');
}

bool ScalarConverter::isInt(std::string const &str) {
	if (str.empty())
		return false;
	
	size_t i = 0;

	if (str[i] == '+' || str[i] == '-')
		i++;
	
	if (i >= str.length())
		return false;
	
	while (i < str.length()) {
		if (!std::isdigit(str[i]))
			return false;
		i++;
	}

	return true;
}

bool ScalarConverter::isFloat(std::string const &str) {
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return true;

	if (str.empty() || str[str.length() - 1] != 'f')
		return false;

	if (str.find('.') == std::string::npos)
		return false;

	std::string num = str.substr(0, str.length() - 1);
	size_t i = 0;

	if (num[i] == '+' || num[i] == '-')
		i++;
	
	bool hasDot = false;
	bool hasDigit = false;

	while (i < num.length()) {
		if (num[i] == '.') {
			if (hasDot)
				return false;
			hasDot = true;
		}
		else if (std::isdigit(num[i])) {
			hasDigit = true;
		}
		else {
			return false;
		}
		i++;
	}

	return hasDigit && hasDot;
}

bool ScalarConverter::isDouble(std::string const &str) {
	if (str == "-inf" || str == "+inf" || str == "nan")
		return true;

	if (str.empty() || str[str.length() - 1] == 'f')
		return false;

	if (str.find('.') == std::string::npos)
		return false;
	
	size_t i = 0;

	if (str[i] == '+' || str[i] == '-')
		i++;

	bool hasDot = false;
	bool hasDigit = false;

	while (i < str.length()) {
		if (str[i] == '.') {
			if (hasDot)
				return false;
			hasDot = true;
		}
		else if (std::isdigit(str[i])) {
			hasDigit = true;
		}
		else {
			return false;
		}
		i++;
	}

	return hasDigit && hasDot;
}

bool ScalarConverter::isPseudoLiteral(std::string const &str) {
	return (str == "-inff" || str == "+inff" || str == "-inf" 
		|| str == "+inf" || str == "nanf" || str == "nan");
}

//print

void ScalarConverter::printChar(double value) {
	if (std::isnan(value) || std::isinf(value)) {
		std::cout << "char: impossible" << std::endl;
		return;
	}

	if (value < 0 || value > 127) {
		std::cout << "char: impossible" << std::endl;
		return;
	}

	int charValue = static_cast<int>(value);

	if (charValue < 32 || charValue > 126) {
		std::cout << "char: Non displayable" << std::endl;
	}
	else {
		std::cout << "char: '" << static_cast<char>(charValue) << "'" << std::endl;
	}
}

void ScalarConverter::printInt(double value) {
	if (std::isnan(value) || std::isinf(value)) {
		std::cout << "int: impossible" << std::endl;
		return;
	}

	if (value < INT_MIN || value > INT_MAX) {
		std::cout << "int: impossible" << std::endl;
		return;
	}

	std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value) {
	float floatValue = static_cast<float>(value);

	std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
}

void ScalarConverter::printDouble(double value) {
	std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}

//convert

void ScalarConverter::convert(std::string const &literal) {
	double value = 0.0;

	if (isChar(literal)) {
		value = static_cast<double>(literal[1]);
	}
	else if (isInt(literal)) {
		char *endptr;
		value = std::strtod(literal.c_str(), &endptr);
		
		if (*endptr != '\0') {
			std::cout << "Error: Invalid literal" << std::endl;
			return;
		}
	}
	else if (isFloat(literal)) {
		if (literal == "nanf") {
			value = std::numeric_limits<double>::quiet_NaN();
		}
		else if (literal == "+inff" || literal == "inff") {
			value = std::numeric_limits<double>::infinity();
		}
		else if (literal == "-inff") {
			value = -std::numeric_limits<double>::infinity();
		}
		else {
			char *endptr;
			value = std::strtod(literal.c_str(), &endptr);
			
			if (*endptr != 'f' || *(endptr + 1) != '\0') {
				std::cout << "Error: Invalid literal" << std::endl;
				return;
			}
		}
	}
	else if (isDouble(literal)) {
		if (literal == "nan") {
			value = std::numeric_limits<double>::quiet_NaN();
		}
		else if (literal == "+inf" || literal == "inf") {
			value = std::numeric_limits<double>::infinity();
		}
		else if (literal == "-inf") {
			value = -std::numeric_limits<double>::infinity();
		}
		else {
			char *endptr;
			value = std::strtod(literal.c_str(), &endptr);
			
			if (*endptr != '\0') {
				std::cout << "Error: Invalid literal" << std::endl;
				return;
			}
		}
	}
	else {
		std::cout << "Error: Invalid literal" << std::endl;
		return;
	}

	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}