/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:14:34 by ainthana          #+#    #+#             */
/*   Updated: 2026/01/26 14:05:42 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie*	zombieHorde(int n, std::string	name) {

	Zombie* horde = new Zombie[n];

	for (int i = 0; i < n; i++) {
		horde[i].setName(name);
	}
	
	return (horde);
}