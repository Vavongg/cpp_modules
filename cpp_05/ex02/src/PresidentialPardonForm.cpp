/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 16:49:24 by ainthana          #+#    #+#             */
/*   Updated: 2026/02/22 17:00:01 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"
#include "../include/Bureaucrat.hpp"

//cannonical form

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("Presidential Pardon", 25, 5), _target("default") {

}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
	: AForm("Presidential Pardon", 25, 5), _target(target) {

}

PresidentialPardonForm::~PresidentialPardonForm() {

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy)
	: AForm(copy), _target(copy._target) {

}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &copy) {

	if (this != &copy) {
		AForm::operator=(copy);
		_target = copy._target;
	}
	return *this;
}

//function

std::string	PresidentialPardonForm::getTarget() const {

	return _target;
}

void		PresidentialPardonForm::execute(Bureaucrat const &executor) const {

	if (!getSigned())
		throw FormNotSignedException();

	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}