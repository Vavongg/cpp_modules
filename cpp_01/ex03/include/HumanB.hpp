/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:15:02 by ainthana          #+#    #+#             */
/*   Updated: 2026/01/26 18:06:47 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "../include/Weapon.hpp"
class HumanB
{
    private:
        std::string name;
        Weapon *weapon;

    public:
        HumanB(std::string str);
        ~HumanB();
        void attack();
        void setWeapon(Weapon &weapon);
};

#endif