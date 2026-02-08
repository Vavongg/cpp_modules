/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:15:46 by ainthana          #+#    #+#             */
/*   Updated: 2026/02/08 13:41:36 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {

	_name = "Alexis";
	_attackDamage = 20;
	_hitPoint = 100;
	_energyPoint = 50;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) {

	*this = copy;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy) {

	if (this != &copy) {
		_name = copy._name;
		_attackDamage = copy._attackDamage;
		_hitPoint = copy._hitPoint;
		_energyPoint = copy._energyPoint;
	}
	return (*this);
}

void ScavTrap::attack(const std::string &target) {

	if (_energyPoint <= 0) {
		std::cout << "ScavTrap :" << _name << " has 0 energy point, he cannot attack the target." << std::endl;
		return ;
	}
	
	std::cout << "Scavtrap: " << _name << " attacks " << target << " causing " << _attackDamage << " point of damage!" << std::endl;
	_energyPoint -= 1;
}

void ScavTrap::guardGate(){

	std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}
