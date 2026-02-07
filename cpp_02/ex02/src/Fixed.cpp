/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:04:53 by ainthana          #+#    #+#             */
/*   Updated: 2026/02/07 18:07:01 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed() {

	std::cout  << "Default constructor called" << std::endl;
}

Fixed::~Fixed(){

	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) {
	
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int n) {

	std::cout << "Int constructor called" << std::endl;
	this->_value = n << _bits;
}

Fixed::Fixed(const float f) {

	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(f * (1 << _bits));
}

Fixed &Fixed::operator=(const Fixed &copy) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy) {
        this->_value = copy._value;
    }
    return *this;
}

Fixed Fixed::operator+(const Fixed &copy) const {

    return Fixed(this->toFloat() + copy.toFloat());
}

Fixed Fixed::operator-(const Fixed &copy) const {

	return Fixed(this->toFloat() - copy.toFloat());
}

Fixed Fixed::operator*(const Fixed &copy) const {

	return Fixed(this->toFloat() * copy.toFloat());
}

Fixed Fixed::operator/(const Fixed &copy) const{

	return Fixed(this->toFloat() / copy.toFloat());
}

int	Fixed::toInt() const {

	return (this->_value >> _bits);
}

float Fixed::toFloat() const {

	return ((float)this->_value / (1 << _bits));
}

bool Fixed::operator<(const Fixed &copy) const {

	return (this->_value < copy._value);
}

bool Fixed::operator>(const Fixed &copy) const {

	return (this->_value > copy._value);
}

bool Fixed::operator!=(const Fixed &copy) const {

	return (this->_value != copy._value);
}

bool Fixed::operator<=(const Fixed &copy) const {

	return (this->_value <= copy._value)
}

bool Fixed::operator>=(const Fixed &copy) const {

	return (this->_value >= copy._value);
}

bool Fixed::operator==(const Fixed &copy) const {

	return (this->_value == copy._value);
}

void	Fixed::setRawBits(int const raw) {

	std::cout << "setRaw function called" << std::endl;
	_value = raw;
}

int		Fixed::getRawBits(void) const {

	std::cout << "getRaw function called" << std::endl;
	return (_value);
}

std::ostream &operator<<(std::ostream &o, Fixed const &i) {

	o << i.toFloat();
	return o;
}