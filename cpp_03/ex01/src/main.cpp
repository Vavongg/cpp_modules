/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:49:58 by ainthana          #+#    #+#             */
/*   Updated: 2026/02/08 14:29:29 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

int	main(void) {

	ClapTrap	Clap;
	ScavTrap	Scav;

	Clap.attack("Kelyan");
	Clap.takeDamage(67);
	Clap.beRepaired(1000);

	Scav.attack("Yasser");
	Scav.takeDamage(76);
	Scav.beRepaired(2000);
	Scav.guardGate();
	
	return 0;
}