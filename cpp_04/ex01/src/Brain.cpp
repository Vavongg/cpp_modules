/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:31:04 by ainthana          #+#    #+#             */
/*   Updated: 2026/02/09 17:54:19 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"

Brain::Brain() {

	std::cout << "Brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = "";
}

Brain::~Brain() {

	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &copy) {
    std::cout << "Brain copy constructor called" << std::endl;
    *this = copy;
}

Brain &Brain::operator=(const Brain &copy) {

	if (this != &copy)
	{
		for (int i = 0; i < 100; i++) {
			_ideas[i] = copy._ideas[i];
		}
	}
	
	return *this;
}

void	Brain::setIdea(int i, const std::string &idea) {

	if (i >= 0 && i < 100) {
		_ideas[i] = idea;
	}
}

std::string	Brain::getIdea(int i) const{

	if (i >= 0 && i < 100)
		return _ideas[i];
	return "";
}