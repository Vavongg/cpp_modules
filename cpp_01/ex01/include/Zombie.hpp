/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:14:23 by ainthana          #+#    #+#             */
/*   Updated: 2026/01/26 14:14:18 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Zombie_HPP
#define Zombie_HPP

#include <iostream>

class Zombie {
	private:
		std::string	_name;

	public:
		Zombie();
		~Zombie();
		void	setName(std::string name);
		void	announce(void);
};

Zombie*	zombieHorde(int n, std::string	name);

#endif