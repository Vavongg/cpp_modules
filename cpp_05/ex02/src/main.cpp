/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:49:14 by ainthana          #+#    #+#             */
/*   Updated: 2026/03/04 17:09:46 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main()
{	
    // ========== SHRUBBERY CREATION FORM ==========

    std::cout << BOLD_BLUE << "\n=== TEST 1: ShrubberyCreationForm - Signature et exécution ===" << RESET << std::endl;
    try {
        Bureaucrat kyks("kyks", 130);
        ShrubberyCreationForm rydom("jardin");
        std::cout << YELLOW << "Avant signature: " << rydom << RESET << std::endl;
        std::cout << CYAN << "Bureaucrate: " << kyks << RESET << std::endl;
        kyks.signForm(rydom);
        std::cout << GREEN << "Après signature: " << rydom << RESET << std::endl;
        kyks.executeForm(rydom);
    }
    catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD_BLUE << "\n=== TEST 2: ShrubberyCreationForm - Exécution sans signature ===" << RESET << std::endl;
    try {
        Bureaucrat yasser("yasser", 100);
        ShrubberyCreationForm walid("parc");
        std::cout << YELLOW << "Formulaire non signé: " << walid << RESET << std::endl;
        std::cout << CYAN << "Bureaucrate: " << yasser << RESET << std::endl;
        yasser.executeForm(walid);
    }
    catch (std::exception &e) {
        std::cout << BOLD_RED << "❌ Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD_BLUE << "\n=== TEST 3: ShrubberyCreationForm - Grade insuffisant pour exécuter ===" << RESET << std::endl;
    try {
        Bureaucrat wassim("wassim", 145);
        ShrubberyCreationForm pompom("bureau");
        std::cout << CYAN << "Bureaucrate: " << wassim << RESET << std::endl;
        wassim.signForm(pompom);
        std::cout << GREEN << "Formulaire signé" << RESET << std::endl;
        wassim.executeForm(pompom);
    }
    catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    // ========== ROBOTOMY REQUEST FORM ==========

    std::cout << BOLD_BLUE << "\n=== TEST 4: RobotomyRequestForm - Signature et exécution (3 fois) ===" << RESET << std::endl;
    try {
        Bureaucrat timtim("Timtim", 40);
        RobotomyRequestForm robot("Fry");
        std::cout << YELLOW << "Avant signature: " << robot << RESET << std::endl;
        std::cout << CYAN << "Bureaucrate: " << timtim << RESET << std::endl;
        timtim.signForm(robot);
        std::cout << GREEN << "Après signature: " << robot << RESET << std::endl;
        
        std::cout << MAGENTA << "\nTentative 1:" << RESET << std::endl;
        timtim.executeForm(robot);
        
        std::cout << MAGENTA << "\nTentative 2:" << RESET << std::endl;
        timtim.executeForm(robot);
        
        std::cout << MAGENTA << "\nTentative 3:" << RESET << std::endl;
        timtim.executeForm(robot);
    }
    catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD_BLUE << "\n=== TEST 5: RobotomyRequestForm - Grade insuffisant pour exécuter ===" << RESET << std::endl;
    try {
        Bureaucrat safiya("Safiya", 50);
        RobotomyRequestForm robot("Fry");
        std::cout << YELLOW << "Avant tentative: " << robot << RESET << std::endl;
        std::cout << CYAN << "Bureaucrate: " << safiya << RESET << std::endl;
        safiya.signForm(robot);
        safiya.executeForm(robot);
    }
    catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD_BLUE << "\n=== TEST 6: RobotomyRequestForm - Grade insuffisant pour signer ===" << RESET << std::endl;
    try {
        Bureaucrat theo("Theo", 80);
        RobotomyRequestForm robot("Dyson");
        std::cout << CYAN << "Bureaucrate: " << theo << RESET << std::endl;
        theo.signForm(robot);
    }
    catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    // ========== PRESIDENTIAL PARDON FORM ==========

    std::cout << BOLD_BLUE << "\n=== TEST 7: PresidentialPardonForm - Signature et exécution ===" << RESET << std::endl;
    try {
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardon("Monkey.D Luffy");
        std::cout << YELLOW << "Avant signature: " << pardon << RESET << std::endl;
        std::cout << CYAN << "Bureaucrate: " << president << RESET << std::endl;
        president.signForm(pardon);
        std::cout << GREEN << "Après signature: " << pardon << RESET << std::endl;
        president.executeForm(pardon);
    }
    catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD_BLUE << "\n=== TEST 8: PresidentialPardonForm - Grade insuffisant pour signer ===" << RESET << std::endl;
    try {
        Bureaucrat houssen("houssen", 30);
        PresidentialPardonForm pardon("Kelyan");
        std::cout << YELLOW << "Avant tentative: " << pardon << RESET << std::endl;
        std::cout << CYAN << "Bureaucrate: " << houssen << RESET << std::endl;
        houssen.signForm(pardon);
    }
    catch (std::exception &e) {
        std::cout << BOLD_RED << "❌ Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD_BLUE << "\n=== TEST 9: PresidentialPardonForm - Peut signer mais pas exécuter ===" << RESET << std::endl;
    try {
        Bureaucrat vavong("Vavong", 10);
        PresidentialPardonForm pardon("patron");
        std::cout << CYAN << "Bureaucrate: " << vavong << RESET << std::endl;
        vavong.signForm(pardon);
        std::cout << GREEN << "Signature réussie" << RESET << std::endl;
        vavong.executeForm(pardon);
    }
    catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    return 0;
}