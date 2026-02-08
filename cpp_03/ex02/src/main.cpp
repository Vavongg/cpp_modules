/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:49:58 by ainthana          #+#    #+#             */
/*   Updated: 2026/02/08 14:29:09 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/ClapTrap.hpp"


int	main(void) {

	ClapTrap	Clap;
	ScavTrap	Scav;
	FragTrap	Frag;

	Clap.attack("Kelyan");
	Clap.takeDamage(67);
	Clap.beRepaired(1000);

	Scav.attack("Yasser");
	Scav.takeDamage(76);
	Scav.beRepaired(2000);
	Scav.guardGate();

	Frag.attack("Sheinez");
	Frag.takeDamage(42);
	Frag.beRepaired(50);
	Frag.highFivesGuys();
	
	return 0;
}