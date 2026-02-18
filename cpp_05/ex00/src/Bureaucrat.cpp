/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:17:53 by ainthana          #+#    #+#             */
/*   Updated: 2026/02/18 13:39:43 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

//canonical form

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {

}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade) {

	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {

}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade) {
	
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {

	if (this != &copy)
		_grade = copy._grade;
	return *this;
}

//functions

std::string	Bureaucrat::getName() const {

	return _name;
}

int	Bureaucrat::getGrade() const {

	return _grade;
}

void	Bureaucrat::incrementGrade() {

	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade() {

	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}

//exception

const char*	Bureaucrat::GradeTooHighException::what() const throw() {

	return ("Grade is too high");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {

	return ("Grade is too low");
}

//operator

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b) {

	o << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return o;
}