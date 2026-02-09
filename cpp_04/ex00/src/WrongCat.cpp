/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:18:12 by ainthana          #+#    #+#             */
/*   Updated: 2026/02/09 14:23:56 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {

	_type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat() {

	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) {

	*this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &copy) {

	if (this != &copy) {
		_type = copy._type;
	}

	return *this;
}

void WrongCat::makeSound() const {

	std::cout << "* Meow Meow *" << std::endl;
}