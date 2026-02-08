/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:48:32 by ainthana          #+#    #+#             */
/*   Updated: 2026/02/08 14:21:55 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {

	_name = "Rydom";
	_attackDamage = 30;
	_hitPoint = 100;
	_energyPoint = 100;
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::~FragTrap() {

	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) {
	
	*this = copy;
}

FragTrap &FragTrap::operator=(const FragTrap &copy) {

	if (this != &copy) {
		_name = copy._name;
		_attackDamage = copy._attackDamage;
		_hitPoint = copy._hitPoint;
		_energyPoint = copy._energyPoint;
	}
	return (*this);
}

void	FragTrap::highFivesGuys() {

	std::cout << "FragTrap : Do you want to give a high five?" << std::endl;
}