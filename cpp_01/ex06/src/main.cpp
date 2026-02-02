/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:15:36 by ainthana          #+#    #+#             */
/*   Updated: 2026/02/02 11:52:55 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

int	main(int ac, char **av) {
	
	if (ac != 2) {
		
		std:: cout << "Usage : ./HarlFilter <FILTER>" << std::endl;
		return (0);
	}

	Harl	harl;

	harl.complain(av[1]);

	return (0);
}