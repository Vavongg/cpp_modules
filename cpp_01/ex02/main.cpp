/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:14:53 by ainthana          #+#    #+#             */
/*   Updated: 2026/01/26 14:25:59 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main() {

	std::string str = "HI THIS IS BRAIN";
	std::string	*ptr = &str;
	std::string	&ref = str;

	std::cout << "address of str : " << &str << std::endl;
	std::cout << "address in ptr: " << ptr << std::endl;
	std::cout << "address in ref: " << &ref << std::endl;

	std::cout << std::endl;

	std::cout << "value of str: " << str << std::endl;
	std::cout << "value point by ptr: " << *ptr << std::endl;
	std::cout << "value point by ref: " << ref << std::endl;

	return (0);
}