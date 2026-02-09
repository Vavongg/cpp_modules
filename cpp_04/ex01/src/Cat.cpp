/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:54:15 by ainthana          #+#    #+#             */
/*   Updated: 2026/02/09 17:02:45 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat() : Animal() {

	_type = "Cat";
	_Brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat() {

	std::cout << "Cat destructor called" << std::endl;
	delete _Brain;
}

Cat::Cat(const Cat &copy) : Animal(copy) {

	_Brain = new Brain(*copy._Brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copy) {

	if (this != &copy) {
		Animal::operator=(copy);
		delete _Brain;
		_Brain = new Brain(*copy._Brain);
	}

	return *this;
}

void Cat::makeSound() const {

	std::cout << "* Meow Meow *" << std::endl;
}

Brain	*Cat::getBrain() const {

	return _Brain;
}