/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:49:14 by ainthana          #+#    #+#             */
/*   Updated: 2026/02/21 16:53:08 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int main()
{
    std::cout << BOLD_BLUE << "\n=== TEST 1: Création de formulaire valide ===" << RESET << std::endl;
    try {
        Form test1("Test 1", 50, 25);
        std::cout << GREEN << test1 << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD_BLUE << "\n=== TEST 2: Grade de signature trop haut (0) ===" << RESET << std::endl;
    try {
        Form test2("Test 2", 0, 50);
        std::cout << GREEN << test2 << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cout << BOLD_RED << "❌ Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD_BLUE << "\n=== TEST 3: Grade d'exécution trop bas (200) ===" << RESET << std::endl;
    try {
        Form test3("Test 3", 50, 200);
        std::cout << GREEN << test3 << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cout << BOLD_RED << "❌ Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD_BLUE << "\n=== TEST 4: Bureaucrate signe avec succès ===" << RESET << std::endl;
    try {
        Bureaucrat alexis("Alexis", 30);
        Form test4("Test valide", 50, 25);
        
        std::cout << YELLOW << "Avant signature: " << test4 << RESET << std::endl;
        std::cout << CYAN << "Bureaucrate: " << alexis << RESET << std::endl;
        alexis.signForm(test4);
        std::cout << GREEN << "Après signature: " << test4 << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD_BLUE << "\n=== TEST 5: Bureaucrate grade insuffisant ===" << RESET << std::endl;
    try {
        Bureaucrat yasser("Yasser", 100);
        Form test5("test invalide", 50, 25);
        
        std::cout << YELLOW << "Avant tentative: " << test5 << RESET << std::endl;
        std::cout << CYAN << "Bureaucrate: " << yasser << RESET << std::endl;
        yasser.signForm(test5);
        std::cout << YELLOW << "Après tentative: " << test5 << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD_BLUE << "\n=== TEST 6: Constructeur par défaut ===" << RESET << std::endl;
    try {
        Form test6;
        Bureaucrat ugo("Ugogo", 150);
        
        std::cout << YELLOW << "Formulaire: " << test6 << RESET << std::endl;
        std::cout << CYAN << "Bureaucrate: " << ugo << RESET << std::endl;
        ugo.signForm(test6);
        std::cout << GREEN << "Après signature: " << test6 << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
	
    return 0;
}