/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:22:54 by ainthana          #+#    #+#             */
/*   Updated: 2026/03/03 15:39:53 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Bureaucrat.hpp"

int main() {
    std::srand(std::time(NULL));

    std::cout << BOLD_BLUE << "\n=== TEST 1: Création de formulaires valides ===" << RESET << std::endl;
    try {
        Intern someRandomIntern;
        AForm* form1 = someRandomIntern.makeForm("shrubbery creation", "home");
        AForm* form2 = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm* form3 = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
        
        std::cout << GREEN << *form1 << RESET << std::endl;
        std::cout << GREEN << *form2 << RESET << std::endl;
        std::cout << GREEN << *form3 << RESET << std::endl;
        
        delete form1;
        delete form2;
        delete form3;
    }
    catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD_BLUE << "\n=== TEST 2: Formulaire inexistant ===" << RESET << std::endl;
    try {
        Intern intern;
        AForm* form = intern.makeForm("unknown form", "target");
        delete form;
    }
    catch (std::exception &e) {
        std::cout << BOLD_RED << "❌ Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD_BLUE << "\n=== TEST 3: Utilisation complète avec Bureaucrat ===" << RESET << std::endl;
    try {
        Intern intern;
        Bureaucrat boss("Boss", 1);
        Bureaucrat lowLevel("Stagiaire", 150);
        
        AForm* form = intern.makeForm("robotomy request", "Marvin");
        
        std::cout << YELLOW << *form << RESET << std::endl;
        
        lowLevel.signForm(*form);
        boss.signForm(*form);
        
        std::cout << MAGENTA << "\nExécution:" << RESET << std::endl;
        boss.executeForm(*form);
        
        delete form;
    }
    catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD_BLUE << "\n=== TEST 4: Plusieurs formulaires du même type ===" << RESET << std::endl;
    try {
        Intern intern;
        Bureaucrat gardener("Gardener", 100);
        
        AForm* form1 = intern.makeForm("shrubbery creation", "jardin1");
        AForm* form2 = intern.makeForm("shrubbery creation", "jardin2");
        AForm* form3 = intern.makeForm("shrubbery creation", "jardin3");
        
        gardener.signForm(*form1);
        gardener.signForm(*form2);
        gardener.signForm(*form3);
        
        std::cout << MAGENTA << "\nExécution des 3 formulaires:" << RESET << std::endl;
        gardener.executeForm(*form1);
        gardener.executeForm(*form2);
        gardener.executeForm(*form3);
        
        delete form1;
        delete form2;
        delete form3;
    }
    catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << BOLD_BLUE << "\n=== TEST 5: Intern crée et bureaucrate exécute tout ===" << RESET << std::endl;
    try {
        Intern intern;
        Bureaucrat god("God", 1);
        
        std::string formNames[] = {
            "shrubbery creation",
            "robotomy request",
            "presidential pardon"
        };
        
        std::string targets[] = {
            "temple",
            "Prophet",
            "Sinner"
        };
        
        for (int i = 0; i < 3; i++) {
            std::cout << MAGENTA << "\n→ Formulaire " << i + 1 << ":" << RESET << std::endl;
            AForm* form = intern.makeForm(formNames[i], targets[i]);
            god.signForm(*form);
            god.executeForm(*form);
            delete form;
        }
    }
    catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
	
    return 0;
}