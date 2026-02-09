/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:15:35 by ainthana          #+#    #+#             */
/*   Updated: 2026/02/09 16:44:00 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/Brain.hpp"

int main()
{
    const Animal    *animalTab[2];
    const Animal    *dogTest = new Dog();
    const Animal    *catTest = new Cat();

    std::cout << std::endl;

    const Dog        dog;
    const Cat        cat;
    const Dog        dogCopy = dog;
    const Cat        catCopy = cat;

    animalTab[0] = dogTest;
    animalTab[1] = catTest;

    std::cout << std::endl;

    for(int i = 0; i < 2; i++)
        delete animalTab[i];
    std::cout << std::endl;
    return 0;
}