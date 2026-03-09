/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 22:19:11 by ainthana          #+#    #+#             */
/*   Updated: 2026/03/09 22:49:51 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

Base*	generate(void) {
		
	switch (std::rand() % 3) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}
	return 0;
}

void	identify(Base* ptr) {
	
	if (dynamic_cast<A*>(ptr)) {
		
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B*>(ptr)) {

		std::cout << "B" << std::endl;
	}
	else if (dynamic_cast<C*>(ptr)) {

		std::cout << "C" << std::endl;
	}
	else
		std::cout << "Unknown type" << std::endl;
}

void	identify(Base& ptr) {
	
	try {
		(void)dynamic_cast<A&>(ptr);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception &e) {
		
	}

	try {
		(void)dynamic_cast<B&>(ptr);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception &e) {
		
	}
	
	try {
		(void)dynamic_cast<C&>(ptr);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception &e) {
		
	}
}