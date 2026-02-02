/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:15:05 by ainthana          #+#    #+#             */
/*   Updated: 2026/01/26 18:07:20 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
class Weapon
{
  private:
	std::string type;

  public:
	Weapon(std::string type);
	~Weapon();
	const std::string &getType() const;
	void setType(const std::string &newType);
};

#endif