/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:19:42 by ainthana          #+#    #+#             */
/*   Updated: 2026/02/08 13:34:32 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Houssen"), _hitPoint(10), _energyPoint(10), _attackDamage(0) {

	std::cout << "ClapTrap constructor called" << std::endl;
}


ClapTrap::~ClapTrap() {

	std::cout << "Claptrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {

	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy) {

	if (this != &copy) {
		this->_attackDamage = copy._attackDamage;
		this->_energyPoint = copy._energyPoint;
		this->_hitPoint = copy._hitPoint;
		this->_name = copy._name;
	}
	return *this;
}

void ClapTrap::attack(const std::string &target){

	if (_energyPoint <= 0) {
		std::cout << "ClapTrap :" << _name << " has 0 energy point, he cannot attack the target." << std::endl;
		return ;
	}
	
	std::cout << "Claptrap: " << _name << " attacks " << target << " causing " << _attackDamage << " point of damage!" << std::endl;
	_energyPoint -= 1;
}

void ClapTrap::takeDamage(unsigned int amount){

	std::cout << "ClapTrap: " << _name << " is taking " << amount << " damage." << std::endl;
	_hitPoint -= amount;

	if (amount > (unsigned int)_hitPoint)
		_hitPoint = 0;
}

void ClapTrap::beRepaired(unsigned int amount){

	if (_energyPoint <= 0) {
		std::cout << "ClapTrap: " << _name << " has 0 energy point, he cannot heal itself." << std::endl;
		return ;
	}

	std::cout << "ClapTrap: " << _name << " regains " << amount << " hit point with golden apple." << std::endl;
	_hitPoint += amount;
}