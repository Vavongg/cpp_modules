/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:14:30 by ainthana          #+#    #+#             */
/*   Updated: 2026/01/26 14:11:03 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie::Zombie() : _name("") {

}

Zombie::~Zombie() {
    std::cout << _name << " is destroyed." << std::endl;
}

void Zombie::setName(std::string name) {
    this->_name = name;
	std::cout << _name << " rises from the ground!" << std::endl;
}

void Zombie::announce(void) {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}