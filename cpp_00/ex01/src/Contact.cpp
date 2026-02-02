/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:00:43 by ainthana          #+#    #+#             */
/*   Updated: 2026/01/23 12:56:27 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"

Contact::Contact() {

}

Contact::~Contact() {

}

void Contact::fillContact() {
	_firstName = "";
	while (_firstName.empty()) {
		std::cout << "Enter first name : ";
		std::getline(std::cin, _firstName);
		if (std::cin.eof())
			return;
	}
	_lastName = "";
	while (_lastName.empty()) {
		std::cout << "Enter last name : ";
		std::getline(std::cin, _lastName);
		if (std::cin.eof())
			return;
	}
	_nickName = "";
	while (_nickName.empty()) {
		std::cout << "Enter nickname : ";
		std::getline(std::cin, _nickName);
		if (std::cin.eof())
			return;
	}
	_phoneNumber = "";
    while (true) {
        std::cout << "Enter phone number : ";
        if (!std::getline(std::cin, _phoneNumber) || std::cin.eof())
            return;

        if (_phoneNumber.empty())
            continue;

        bool isAllDigits = true;
        for (size_t i = 0; i < _phoneNumber.length(); i++) {
            if (!std::isdigit(_phoneNumber[i])) {
                isAllDigits = false;
                break;
            }
        }

        if (isAllDigits)
            break;
        else
            std::cout << "Error: phone number must contain only digits." << std::endl;
    }
	_darkestSecret = "";
	while (_darkestSecret.empty()) {
		std::cout << "Enter darkest secret : ";
		std::getline(std::cin, _darkestSecret);
		if (std::cin.eof())
			return;
	}
	return;
}

std::string Contact::getFirstName() const {
	return (_firstName);
}

std::string Contact::getLastName() const {
	return (_lastName);
}

std::string Contact::getNickName() const {
	return (_nickName);
}

std::string Contact::getPhoneNumber() const {
	return (_phoneNumber);
}

std::string Contact::getDarkestSecret() const {
	return (_darkestSecret);
}

void	Contact::display() const{
	std::cout << "First Name: " << _firstName << std::endl;
	std::cout << "Last Name: " << _lastName << std::endl;
	std::cout << "NickName: " << _nickName << std::endl;
	std::cout << "Phone Number: " << _phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << _darkestSecret << std::endl;
	return;
}
