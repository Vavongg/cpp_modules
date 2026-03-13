/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 17:24:26 by ainthana          #+#    #+#             */
/*   Updated: 2026/03/13 12:20:52 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename F>
void	iter(T *array, size_t length, F func) {
	
	for (size_t i = 0; i < length; i++) {
		func(array[i]);
	}
}

#endif