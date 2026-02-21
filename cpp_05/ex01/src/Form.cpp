/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:26:56 by ainthana          #+#    #+#             */
/*   Updated: 2026/02/21 16:57:04 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

//canonical form

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {

}

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {

	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::~Form() {

}

Form::Form(const Form &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {

}

Form &Form::operator=(const Form &copy) {
	
	if (this != &copy)
		_signed = copy._signed;
	return *this;
}

//functions

std::string Form::getName() const {

	return _name;
}

bool	Form::getSigned() const {

	return _signed;
}

int		Form::getGradeToSign() const {

	return _gradeToSign;
}

int		Form::getGradeToExecute() const {

	return _gradeToExecute;
}

void	Form::beSigned(Bureaucrat const &bureaucrat) {

	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

//execptions

const char*	Form::GradeTooHighException::what() const throw() {

	return "Grade is too high";
}

const char*	Form::GradeTooLowException::what() const throw() {

	return "Grade is too low";
}

//operator

std::ostream &operator<<(std::ostream &o, Form const &f) {

	o << "Form " << f.getName() << ", signed: " << (f.getSigned() ? "yes" : "no") << ", grade required to sign: " << f.getGradeToSign() << ", grade required to execute: " << f.getGradeToExecute();
	return o;
}