/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:26:56 by ainthana          #+#    #+#             */
/*   Updated: 2026/02/21 17:31:23 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

//canonical form

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {

}

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {

	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::~AForm() {

}

AForm::AForm(const AForm &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {

}

AForm &AForm::operator=(const AForm &copy) {
	
	if (this != &copy)
		_signed = copy._signed;
	return *this;
}

//functions

std::string AForm::getName() const {

	return _name;
}

bool	AForm::getSigned() const {

	return _signed;
}

int		AForm::getGradeToSign() const {

	return _gradeToSign;
}

int		AForm::getGradeToExecute() const {

	return _gradeToExecute;
}

void	AForm::beSigned(Bureaucrat const &bureaucrat) {

	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

//exceptions

const char*	AForm::GradeTooHighException::what() const throw() {

	return "Grade is too high";
}

const char*	AForm::GradeTooLowException::what() const throw() {

	return "Grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw() {

	return "Form is not signed";
}

//operator

std::ostream &operator<<(std::ostream &o, AForm const &f) {

	o << "AForm " << f.getName() << ", signed: " << (f.getSigned() ? "yes" : "no") << ", grade required to sign: " << f.getGradeToSign() << ", grade required to execute: " << f.getGradeToExecute();
	return o;
}