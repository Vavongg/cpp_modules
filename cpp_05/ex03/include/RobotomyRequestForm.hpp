/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:13:47 by ainthana          #+#    #+#             */
/*   Updated: 2026/02/26 13:17:46 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm {

	private:
		std::string	_target;
	
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const &target);
		~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &copy);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &copy);

		std::string	getTarget() const;

		void		execute(Bureaucrat const &executor) const;
};

#endif