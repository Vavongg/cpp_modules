/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:54:15 by ainthana          #+#    #+#             */
/*   Updated: 2026/02/09 14:24:05 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat() : Animal() {

	_type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat() {

	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &copy) {

	*this = copy;
}

Cat &Cat::operator=(const Cat &copy) {

	if (this != &copy) {
		_type = copy._type;
	}

	return *this;
}

void Cat::makeSound() const {

	std::cout << "* Meow Meow *" << std::endl;
}