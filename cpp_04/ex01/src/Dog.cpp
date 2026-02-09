/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:49:22 by ainthana          #+#    #+#             */
/*   Updated: 2026/02/09 17:00:18 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog() : Animal() {

	_type = "Dog";
	_Brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog() {

	std::cout << "Dog destructor called" << std::endl;
	delete _Brain;
}

Dog::Dog(const Dog &copy) : Animal(copy) {

	_Brain = new Brain(*copy._Brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy) {

	std::cout << "Dog assigment operator called" << std::endl;
	if (this != &copy) {
		Animal::operator=(copy);
		delete _Brain;
		_Brain = new Brain(*copy._Brain);
	}
	
	return *this;
}

void	Dog::makeSound() const {

	std::cout << "* Woof Woof *" << std::endl;
}

Brain	*Dog::getBrain() const {

	return _Brain;
}