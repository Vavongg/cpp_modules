/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:49:14 by ainthana          #+#    #+#             */
/*   Updated: 2026/02/21 12:00:04 by ainthana         ###   ########.fr       */
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
        Bureaucrat alexis("Alexis", 50);
        std::cout << GREEN << alexis << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD_BLUE << "\n=== TEST 2: Grade trop haut (0) ===" << RESET << std::endl;
    try {
        Bureaucrat yasser("Yasser", 0);
        std::cout << GREEN << yasser << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cout << BOLD_RED << "❌ Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD_BLUE << "\n=== TEST 3: Grade trop bas (200) ===" << RESET << std::endl;
    try {
        Bureaucrat walid("Walid", 200);
        std::cout << GREEN << walid << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cout << BOLD_RED << "❌ Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD_BLUE << "\n=== TEST 4: Incrémenter normalement ===" << RESET << std::endl;
    try {
        Bureaucrat rydom("Rydom", 100);
        std::cout << YELLOW << "Avant: " << rydom << RESET << std::endl;
        rydom.incrementGrade();
        std::cout << GREEN << "Après increment: " << rydom << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD_BLUE << "\n=== TEST 5: Décrémenter normalement ===" << RESET << std::endl;
    try {
        Bureaucrat senshy("Senshy", 100);
        std::cout << YELLOW << "Avant: " << senshy << RESET << std::endl;
        senshy.decrementGrade();
        std::cout << GREEN << "Après decrement: " << senshy << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD_BLUE << "\n=== TEST 6: Incrémenter au-delà de 1 ===" << RESET << std::endl;
    try {
        Bureaucrat kyks("Kyks", 1);
        std::cout << YELLOW << "Avant: " << kyks << RESET << std::endl;
        kyks.incrementGrade();
        std::cout << GREEN << "Après increment: " << kyks << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cout << BOLD_RED << "❌ Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD_BLUE << "\n=== TEST 7: Décrémenter au-delà de 150 ===" << RESET << std::endl;
    try {
        Bureaucrat wassim("Wassim", 150);
        std::cout << YELLOW << "Avant: " << wassim << RESET << std::endl;
        wassim.decrementGrade();
        std::cout << GREEN << "Après decrement: " << wassim << RESET << std::endl;
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