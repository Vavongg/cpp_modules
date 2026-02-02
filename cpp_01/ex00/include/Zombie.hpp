/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 11:57:26 by ainthana          #+#    #+#             */
/*   Updated: 2026/01/26 13:26:10 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Zombie_HPP
#define Zombie_HPP

#include <iostream>
class	Zombie {
	private:
		std::string	_name;
	
	public:
		Zombie(std::string name);
		~Zombie();
		void	announce(void);
};

Zombie	*newZombie(std::string	name);
void	randomChump(std::string	name);

#endif