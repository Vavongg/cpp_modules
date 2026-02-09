/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:15:16 by ainthana          #+#    #+#             */
/*   Updated: 2026/02/09 14:18:00 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {

	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {

	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {

	*this = copy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy) {

	if (this != &copy) {
		this->_type = copy._type;
	}

	return *this;
}

void	WrongAnimal::makeSound() const {

	std::cout << "* Make sound *" << std::endl;
}

std::string	WrongAnimal::getType() const {

	return _type;	
}