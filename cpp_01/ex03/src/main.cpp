/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:15:13 by ainthana          #+#    #+#             */
/*   Updated: 2026/02/02 10:46:52 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"
#include "../include/HumanA.hpp"
#include "../include/HumanB.hpp"

int	main(void)
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA Rydom("Rydom", club);
		Rydom.attack();
		club.setType("some other type of club");
		Rydom.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB Senshy("Senshy");
		Senshy.setWeapon(club);
		Senshy.attack();
		club.setType("some other type of club");
		Senshy.attack();
	}

	return (0);
}