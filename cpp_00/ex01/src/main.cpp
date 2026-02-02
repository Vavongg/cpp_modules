/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 10:58:24 by ainthana          #+#    #+#             */
/*   Updated: 2026/01/23 12:37:27 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

int	main() {
	PhoneBook	repertory;
	std::string	cmd;

	while(true) {
		std::cout << "Enter a command : [ADD], [SEARCH] or [EXIT]: ";
		if (!std::getline(std::cin, cmd))
			break;
		if (cmd == "ADD") {
			repertory.addContact();
		} else if (cmd == "SEARCH") {
			repertory.searchContact();
		} else if (cmd == "EXIT") {
			break;
		} else {
			std::cout << "Invalid command !" << std::endl;
		}
	}
	return (0);
}
