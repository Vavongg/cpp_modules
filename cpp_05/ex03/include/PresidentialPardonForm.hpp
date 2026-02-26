/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 16:38:33 by ainthana          #+#    #+#             */
/*   Updated: 2026/02/22 16:48:38 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define	PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {

	private:
		std::string	_target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const &target);
		~PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const &copy);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &copy);

		std::string	getTarget() const;

		void		execute(Bureaucrat const &executor) const;
};

#endif