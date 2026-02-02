/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:27:35 by ainthana          #+#    #+#             */
/*   Updated: 2026/01/21 15:01:05 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int main(int ac, char **av)
{
    if (ac <= 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    for (int i = 1; i < ac; i++)
    {
        std::string str = av[i];
        for (size_t j = 0; j < str.length(); j++)
            std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(str[j])));
    }
    std::cout << std::endl;
    return (0);
}