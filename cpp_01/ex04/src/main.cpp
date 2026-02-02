/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:15:24 by ainthana          #+#    #+#             */
/*   Updated: 2026/02/02 10:59:24 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>

std::string	ft_replace(std::string str,std::string s1, std::string s2) {

	std::string	res;
	std::size_t	pos = 0;
	std::size_t	found;

	while ((found = str.find(s1, pos)) != std::string::npos) {
		res += str.substr(pos, found - pos);
		res += s2;
		pos = found + s1.length();
	}
	res += str.substr(pos);

	return (res);
}

int	main(int ac, char **av) {

	if (ac != 4) {

		std::cout << "Usage : ./sed_is_for_losers <filename> <search> <replace>" << std::endl;
		return (1);
	}

	std::string	filename = av[1];
	std::string	s1 = av[2];
	std::string s2 = av[3];
	std::ifstream	infile(filename.c_str());

	if (s1.empty()) {

    	std::cout << "Error: search string cannot be empty." << std::endl;
    	return (1);
	}

	if (!infile.is_open()) {
		
		std::cout << "Error: cannot create infile" << std::endl;
		return (1);
	}

	std::string	line;
	std::string	str;

	while (std::getline(infile, line)) {
		str += line;
		if (!infile.eof())
			str += "\n";
	}

	infile.close();
	str = ft_replace(str, s1, s2);
	std::ofstream	outfile((filename + ".replace").c_str());

	if (!outfile.is_open()) {
		
		std::cout << "Error: cannot create outfile" << std::endl;
		return (1);
	}

	outfile << str;
	outfile.close();
	std::cout << "Sucess: creating file" << std::endl;

	return (0);
}