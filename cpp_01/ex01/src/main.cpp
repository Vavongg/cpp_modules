/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:14:27 by ainthana          #+#    #+#             */
/*   Updated: 2026/01/26 14:08:05 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int	main() {

	int n = 5;
	Zombie*	horde = zombieHorde(n, "Soldier");

	for (int i = 0; i < n; i++) {
		horde[i].announce();
	}

	delete[] horde;
	return (0);
}