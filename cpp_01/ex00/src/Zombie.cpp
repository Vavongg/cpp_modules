/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 11:58:02 by ainthana          #+#    #+#             */
/*   Updated: 2026/01/26 13:33:38 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie::Zombie(std::string	name) : _name(name) {

	std::cout << name << " is here" << std::endl;
}

Zombie::~Zombie() {
	
    std::cout << _name << ": is destroyed" << std::endl;
}

void	Zombie::announce() {

	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}