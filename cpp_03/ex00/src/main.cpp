/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:49:58 by ainthana          #+#    #+#             */
/*   Updated: 2026/02/08 14:29:41 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

int	main(void) {

	ClapTrap	Clap;

	Clap.attack("Kelyan");
	Clap.takeDamage(67);
	Clap.beRepaired(1000);

	return 0;
}