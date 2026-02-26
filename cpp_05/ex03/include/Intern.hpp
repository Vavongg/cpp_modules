/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:23:38 by ainthana          #+#    #+#             */
/*   Updated: 2026/02/26 14:35:26 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern {

	private:
		AForm *createShruberry(std::string target);
		AForm *createPardon(std::string target);
		AForm *createRobotomy(std::string target);

	public:
		Intern();
		Intern(const Intern &copy);
		~Intern();
		Intern &operator=(Intern const &copy);

		AForm	*makeForm(const std::string &formName, const std::string &target);
};

#endif