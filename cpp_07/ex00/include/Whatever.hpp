/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 17:03:31 by ainthana          #+#    #+#             */
/*   Updated: 2026/03/11 17:19:25 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void	swap(T &a, T &b) {
	
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T const	&min(T const &a, T const &b) {
	
	return (a < b) ? a : b;
}

template <typename T>
T const	&max(T const &a, T const &b) {
	
	return (a > b) ? a : b;
}

#endif