/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 11:04:32 by ainthana          #+#    #+#             */
/*   Updated: 2026/03/09 11:24:32 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << BOLD_RED << "Usage: ./convert <literal>" << RESET << std::endl;
        std::cout << YELLOW << "Examples:" << RESET << std::endl;
        std::cout << "  ./ScalarConverter 'a'" << std::endl;
        std::cout << "  ./ScalarConverter 42" << std::endl;
        std::cout << "  ./ScalarConverter 42.0f" << std::endl;
        std::cout << "  ./ScalarConverter 42.0" << std::endl;
        std::cout << "  ./ScalarConverter nan" << std::endl;
        std::cout << "  ./ScalarConverter -inff" << std::endl;
        return 1;
    }

    std::cout << BOLD_CYAN << "\n╔════════════════════════════════════════╗" << RESET << std::endl;
    std::cout << BOLD_CYAN << "║      SCALAR CONVERTER                  ║" << RESET << std::endl;
    std::cout << BOLD_CYAN << "╚════════════════════════════════════════╝" << RESET << std::endl;

    std::cout << GREEN << "\nConversions:" << RESET << std::endl;
    
    ScalarConverter::convert(argv[1]);

    return 0;
}