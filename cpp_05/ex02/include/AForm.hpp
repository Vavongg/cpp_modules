/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 11:53:47 by ainthana          #+#    #+#             */
/*   Updated: 2026/02/21 17:16:38 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm {

	private:
		std::string const 	_name;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExecute;
	
	public:
		AForm();
		AForm(std::string const &name, int gradeToSign, int gradeToExecute);
		virtual ~AForm();
		AForm(const AForm &copy);
		AForm &operator=(const AForm &copy);

		std::string 	getName() const;
		bool			getSigned() const;
		int				getGradeToSign() const;
		int				getGradeToExecute() const;

		void			beSigned(Bureaucrat const &Bureaucrat);
		virtual void	execute(Bureaucrat const &exec) const = 0;

		class		GradeTooHighException : public std::exception {

			public:
				virtual const char* what() const throw();
		};

		class		GradeTooLowException : public std::exception {

			public:
				virtual const char* what() const throw();
		};

		class		FormNotSignedException : public std::exception {

			public:
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, AForm const &a);

#endif