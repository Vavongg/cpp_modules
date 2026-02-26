/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 16:05:21 by ainthana          #+#    #+#             */
/*   Updated: 2026/02/22 16:25:08 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Bureaucrat.hpp"

//cannonical form

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Shrubbery Creation", 145, 137), _target("default") {

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) 
	: AForm("Shrubbery Creation", 145, 137), _target(target) {

}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy)
	: AForm(copy), _target(copy._target) {

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy) {

	if (this != &copy) {
		AForm::operator=(copy);
		_target = copy._target;
	}
	return *this;
}

//functions

std::string	ShrubberyCreationForm::getTarget() const {

	return _target;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const {

	if (!getSigned())
		throw FormNotSignedException();
	
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	
	std::string filename = _target + "_shrubbery";
	std::ofstream file(filename.c_str());

	if (!file.is_open())
		throw std::runtime_error("can't create file");
	
    file << "       ###\n";
    file << "      #o###\n";
    file << "    #####o###\n";
    file << "   #o#\\#|#/###\n";
    file << "    ###\\|/#o#\n";
    file << "     # }|{  #\n";
    file << "       }|{\n";
    file << "\n";
    file << "       ###\n";
    file << "      #o###\n";
    file << "    #####o###\n";
    file << "   #o#\\#|#/###\n";
    file << "    ###\\|/#o#\n";
    file << "     # }|{  #\n";
    file << "       }|{\n";

	file.close();
}
