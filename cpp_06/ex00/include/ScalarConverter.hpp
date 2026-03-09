/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 09:55:37 by ainthana          #+#    #+#             */
/*   Updated: 2026/03/09 10:55:49 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

#define BOLD_RED     "\033[1;31m"
#define BOLD_GREEN   "\033[1;32m"
#define BOLD_YELLOW  "\033[1;33m"
#define BOLD_BLUE    "\033[1;34m"
#define BOLD_MAGENTA "\033[1;35m"
#define BOLD_CYAN    "\033[1;36m"
#define BOLD_WHITE   "\033[1;37m"

class ScalarConverter {

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &copy);
		~ScalarConverter();

		static bool	isChar(std::string const &str);
		static bool isInt(std::string const &str);
		static bool	isFloat(std::string const &str);
		static bool	isDouble(std::string const &str);
		static bool isPseudoLiteral(std::string const &str);

		static void	printChar(double value);
		static void	printInt(double value);
		static void	printFloat(double value);
		static void	printDouble(double value);
	
	public:
		static void	convert(std::string const &literal);
};

#endif