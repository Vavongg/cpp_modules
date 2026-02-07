/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:16:09 by ainthana          #+#    #+#             */
/*   Updated: 2026/02/07 16:58:20 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    private:
        int                 _value;
        static const int    _bits = 8;

    public:
        Fixed();
        Fixed(const Fixed &copy);
        Fixed &operator=(const Fixed &copy);
        ~Fixed();

        Fixed(const int n);
        Fixed(const float f);

        int     getRawBits(void) const;
        void    setRawBits(int const raw);

        float   toFloat(void) const;
        int     toInt(void) const;
};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif