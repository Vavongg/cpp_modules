/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:35:35 by ainthana          #+#    #+#             */
/*   Updated: 2026/03/03 15:40:07 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"

Intern::Intern() {

}

Intern::~Intern() {

}

Intern::Intern(const Intern &copy) {

	(void)copy;
}

Intern &Intern::operator=(const Intern &copy) {

	(void)copy;
	return *this;
}

AForm	*Intern::makeForm(const std::string &formName, const std::string &target) {

	typedef	AForm* (Intern::*CreatorFunc)(std::string);

	CreatorFunc	creator[]= {
		&Intern::createShruberry,
		&Intern::createPardon,
		&Intern::createRobotomy
	};

	std::string	tab[] = {
		"shrubbery creation",
		"presidential pardon",
		"robotomy request"
	};

	for (int i = 0; i < 3; i++) {
		if (tab[i] == formName) {
			std::cout << "Intern create the form " << formName << std::endl;
			return (this->*creator[i])(target);
		}
	}
	
	throw UnknownFormException();
}

AForm*	Intern::createShruberry(const std::string target) {

	return new ShrubberyCreationForm(target);
}

AForm*	Intern::createPardon(const std::string target) {

	return new PresidentialPardonForm(target);
}

AForm*	Intern::createRobotomy(const std::string target) {

	return new RobotomyRequestForm(target);
}

const char* Intern::UnknownFormException::what() const throw() {

	return "Unknown form type";
}