/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:18:02 by ainthana          #+#    #+#             */
/*   Updated: 2026/02/26 13:33:36 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"
#include "../include/Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Robotomy Request", 72, 45), _target("default") {

}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
	: AForm("Robotomy Request", 72, 45), _target(target) {

}

RobotomyRequestForm::~RobotomyRequestForm() {

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy)
	: AForm(copy), _target(copy._target) {

}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &copy) {

	if (this != &copy) {
		AForm::operator=(copy);
		_target = copy._target;
	}
	return *this;
}

std::string	RobotomyRequestForm::getTarget() const {

	return _target;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const {

	if (!getSigned())
		throw FormNotSignedException();
	
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();

	std::cout << "* BZZZZZZ * DRILLING NOISES * BZZZZZZ *" << std::endl;
	
	if (std::rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomized failed on " << _target << "!" << std::endl;
}