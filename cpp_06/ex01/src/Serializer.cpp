/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:08:51 by ainthana          #+#    #+#             */
/*   Updated: 2026/03/09 15:20:00 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"

//canonical form

Serializer::Serializer() {
	
}

Serializer::Serializer(const Serializer &copy) {
	
	(void)copy;
}

Serializer	&Serializer::operator=(const Serializer &copy) {

	(void)copy;
	return *this;
}

Serializer::~Serializer() {
	
}

//methods

uintptr_t	Serializer::serialize(Data* ptr) {
	
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*		Serializer::deserialize(uintptr_t raw) {

	return reinterpret_cast<Data*>(raw);
}