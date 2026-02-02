/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:00:30 by ainthana          #+#    #+#             */
/*   Updated: 2026/01/23 12:58:08 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

PhoneBook::PhoneBook() {
	this->_index = 0;
	this->_count = 0;
}

PhoneBook::~PhoneBook() {

}

std::string PhoneBook::_formatString(std::string str) const {
	if (str.length() > 10) {
		return (str.substr(0, 9) + ".");
	}
	return (str);
}

void PhoneBook::addContact() {
	this->_contact[this->_index].fillContact();
	this->_index = (this->_index + 1) % 8;

	if (this->_count < 8)
		this->_count++;
}

void PhoneBook::searchContact() const {
	if (this->_count == 0) {
		std::cout << "L'annuaire est vide" << std::endl;
		return;
	}
	std::cout << "|" << std::setw(10) << "Index";
	std::cout << "|" << std::setw(10) << "First Name";
	std::cout << "|" << std::setw(10) << "Last Name";
	std::cout << "|" << std::setw(10) << "NickName";
	std::cout << "|" << std::endl;

	for (int i = 0; i < this->_count; i++) {
		std::cout << "|" << std::setw(10) << i;
		std::cout << "|" << std::setw(10) << _formatString(_contact[i].getFirstName());
		std::cout << "|" << std::setw(10) << _formatString(_contact[i].getLastName());
		std::cout << "|" << std::setw(10) << _formatString(_contact[i].getNickName());
		std::cout << "|" << std::endl;
	}
	std::cout << "Enter the contact index to see details: ";
	
	std::string input;
	std::getline(std::cin, input);

	if (input.empty() || input.length() > 1 || !std::isdigit(input[0])) {
		std::cout << "Index invalid" << std::endl;
		return;
	}

	int index = input[0] - '0';

	if (index >= 0 && index < this->_count) {
		this->_contact[index].display();
	} else {
		std::cout << "Error : Index hors limite" << std:: endl;
	}
}