/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:04:53 by ainthana          #+#    #+#             */
/*   Updated: 2026/02/08 11:48:28 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed() : _value(0) {

	std::cout  << "Default constructor called" << std::endl;
}

Fixed::~Fixed(){

	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) {
	
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy) {
        this->_value = copy.getRawBits();
    }
    return *this;
}

void	Fixed::setRawBits(int const raw) {

	std::cout << "setRaw function called" << std::endl;
	_value = raw;
}

int		Fixed::getRawBits(void) const {

	std::cout << "getRaw function called" << std::endl;
	return (_value);
}