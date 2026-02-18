/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:49:14 by ainthana          #+#    #+#             */
/*   Updated: 2026/02/18 13:57:52 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int main()
{
    std::cout << BOLD_CYAN << "\n╔════════════════════════════════════════╗" << RESET << std::endl;
    std::cout << BOLD_CYAN << "║     BUREAUCRAT EXCEPTION TESTS         ║" << RESET << std::endl;
    std::cout << BOLD_CYAN << "╚════════════════════════════════════════╝" << RESET << std::endl;

    std::cout << BOLD_BLUE << "\n=== TEST 1: Création normale ===" << RESET << std::endl;
    try {
        Bureaucrat bob("Bob", 50);
        std::cout << GREEN << bob << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD_BLUE << "\n=== TEST 2: Grade trop haut (0) ===" << RESET << std::endl;
    try {
        Bureaucrat alice("Alice", 0);
        std::cout << GREEN << alice << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cout << BOLD_RED << "❌ Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD_BLUE << "\n=== TEST 3: Grade trop bas (200) ===" << RESET << std::endl;
    try {
        Bureaucrat charlie("Charlie", 200);
        std::cout << GREEN << charlie << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cout << BOLD_RED << "❌ Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD_BLUE << "\n=== TEST 4: Incrémenter normalement ===" << RESET << std::endl;
    try {
        Bureaucrat dave("Dave", 100);
        std::cout << YELLOW << "Avant: " << dave << RESET << std::endl;
        dave.incrementGrade();
        std::cout << GREEN << "Après increment: " << dave << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD_BLUE << "\n=== TEST 5: Décrémenter normalement ===" << RESET << std::endl;
    try {
        Bureaucrat eve("Eve", 100);
        std::cout << YELLOW << "Avant: " << eve << RESET << std::endl;
        eve.decrementGrade();
        std::cout << GREEN << "Après decrement: " << eve << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD_BLUE << "\n=== TEST 6: Incrémenter au-delà de 1 ===" << RESET << std::endl;
    try {
        Bureaucrat frank("Frank", 1);
        std::cout << YELLOW << "Avant: " << frank << RESET << std::endl;
        frank.incrementGrade();
        std::cout << GREEN << "Après increment: " << frank << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cout << BOLD_RED << "❌ Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD_BLUE << "\n=== TEST 7: Décrémenter au-delà de 150 ===" << RESET << std::endl;
    try {
        Bureaucrat grace("Grace", 150);
        std::cout << YELLOW << "Avant: " << grace << RESET << std::endl;
        grace.decrementGrade();
        std::cout << GREEN << "Après decrement: " << grace << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cout << BOLD_RED << "❌ Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD_BLUE << "\n=== TEST 8: Constructeur par défaut ===" << RESET << std::endl;
    try {
        Bureaucrat defaultBureaucrat;
        std::cout << GREEN << defaultBureaucrat << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    return 0;
}