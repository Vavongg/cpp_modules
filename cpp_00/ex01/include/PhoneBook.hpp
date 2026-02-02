/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 10:21:14 by ainthana          #+#    #+#             */
/*   Updated: 2026/01/23 11:47:46 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "../include/Contact.hpp"

class PhoneBook {
	private:
		Contact _contact[8];
		int		_index;
		int		_count;

		std::string _formatString(std::string str) const;
	
	public:
		PhoneBook();
		~PhoneBook();

		void	addContact();
		void	searchContact() const;
		void	display();
};

#endif
