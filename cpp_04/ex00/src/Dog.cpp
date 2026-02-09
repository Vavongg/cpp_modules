/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:49:22 by ainthana          #+#    #+#             */
/*   Updated: 2026/02/09 14:12:55 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog() : Animal() {

	_type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog() {

	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &copy) {

	*this = copy;
}

Dog &Dog::operator=(const Dog &copy) {

	if (this != &copy) {
		_type = copy._type;
	}

	return *this;
}

void	Dog::makeSound() const {

	std::cout << "* Woof Woof *" << std::endl;
}