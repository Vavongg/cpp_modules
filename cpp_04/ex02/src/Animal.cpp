/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:42:48 by ainthana          #+#    #+#             */
/*   Updated: 2026/02/09 18:03:59 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

Animal::Animal() {

	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal() {

	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &copy) {

	std::cout << "Animal copy constructor called" << std::endl;
	*this = copy;
}

Animal &Animal::operator=(const Animal &copy) {

	if (this != &copy) {
		this->_type = copy._type;
	}

	return *this;
}

std::string	Animal::getType() const {

	return _type;	
}