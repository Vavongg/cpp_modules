/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:22:54 by ainthana          #+#    #+#             */
/*   Updated: 2026/02/26 16:11:49 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//main a change (color etc)

#include "../include/Intern.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Bureaucrat.hpp"

int main() {
    
    std::cout << "=== TEST 1: Création de formulaires valides ===" << std::endl;
    {
        Intern someRandomIntern;
        AForm* form1;
        AForm* form2;
        AForm* form3;

        form1 = someRandomIntern.makeForm("shrubbery creation", "home");
        form2 = someRandomIntern.makeForm("robotomy request", "Bender");
        form3 = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");

        std::cout << *form1 << std::endl;
        std::cout << *form2 << std::endl;
        std::cout << *form3 << std::endl;

        delete form1;
        delete form2;
        delete form3;
    }

    std::cout << "\n=== TEST 2: Formulaire inexistant ===" << std::endl;
    {
        Intern intern;
        AForm* form;

        form = intern.makeForm("unknown form", "target");
        if (form == NULL) {
            std::cout << "Formulaire non créé (erreur gérée)" << std::endl;
        }
    }

    std::cout << "\n=== TEST 3: Utilisation complète avec Bureaucrat ===" << std::endl;
    {
        Intern intern;
        Bureaucrat boss("Boss", 1);
        Bureaucrat lowLevel("Stagiaire", 150);
        
        AForm* form = intern.makeForm("robotomy request", "Marvin");
        
        std::cout << *form << std::endl;
        
        // Le stagiaire essaie de signer (devrait échouer)
        lowLevel.signForm(*form);
        
        // Le boss signe
        boss.signForm(*form);
        
        // Le boss exécute
        boss.executeForm(*form);
        
        delete form;
    }

    std::cout << "\n=== TEST 4: Test de copie d'Intern ===" << std::endl;
    {
        Intern intern1;
        Intern intern2(intern1);
        Intern intern3;
        intern3 = intern1;

        AForm* f1 = intern1.makeForm("shrubbery creation", "garden");
        AForm* f2 = intern2.makeForm("robotomy request", "Robot");
        AForm* f3 = intern3.makeForm("presidential pardon", "Criminal");

        std::cout << *f1 << std::endl;
        std::cout << *f2 << std::endl;
        std::cout << *f3 << std::endl;

        delete f1;
        delete f2;
        delete f3;
    }

    std::cout << "\n=== TEST 5: Plusieurs formulaires du même type ===" << std::endl;
    {
        Intern intern;
        
        AForm* form1 = intern.makeForm("shrubbery creation", "jardin1");
        AForm* form2 = intern.makeForm("shrubbery creation", "jardin2");
        AForm* form3 = intern.makeForm("shrubbery creation", "jardin3");

        Bureaucrat gardener("Gardener", 100);
        
        gardener.signForm(*form1);
        gardener.signForm(*form2);
        gardener.signForm(*form3);
        
        gardener.executeForm(*form1);
        gardener.executeForm(*form2);
        gardener.executeForm(*form3);

        delete form1;
        delete form2;
        delete form3;
    }

    return 0;
}