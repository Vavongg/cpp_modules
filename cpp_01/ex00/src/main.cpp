/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 11:57:52 by ainthana          #+#    #+#             */
/*   Updated: 2026/01/26 18:27:38 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int main() {

    std::cout << "Creating a random chump on the stack" << std::endl;
    randomChump("Stack_Zombie");

    std::cout << std::endl;

    std::cout << "Creating a zombie on the heap" << std::endl;
    Zombie* heap = newZombie("Heap_Zombie");
    heap->announce();
    
    delete heap; 

    return 0;
}