/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:57:01 by ainthana          #+#    #+#             */
/*   Updated: 2026/03/09 15:05:32 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct	Data {
	int			value;
	std::string name;

	Data(int v, std::string s)
		: value(v), name(s) {
			
	}
	
	Data() : value(0), name("default") {
	
	}
};

#endif