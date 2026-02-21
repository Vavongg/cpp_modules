/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 11:53:47 by ainthana          #+#    #+#             */
/*   Updated: 2026/02/21 12:19:25 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form {

	private:
		std::string const 	_name;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExecute;
	
	public:
		Form();
		Form(std::string const &name, int gradeToSign, int gradeToExecute);
		~Form();
		Form(const Form &copy);
		Form &operator=(const Form &copy);

		std::string getName() const;
		bool		getSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		void		beSigned(Bureaucrat const &Bureaucrat);

		class		GradeTooHighException : public std::exception {

			public:
				virtual const char* what() const throw();
		};

		class		GradeTooLowException : public std::exception {

			public:
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, Form const &f);

#endif