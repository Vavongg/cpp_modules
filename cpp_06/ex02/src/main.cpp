/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 22:34:48 by ainthana          #+#    #+#             */
/*   Updated: 2026/03/09 22:43:15 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

// Déclarations des fonctions
Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main() {

	std::srand(std::time(NULL));
	
    std::cout << BOLD_BLUE << "\n╔════════════════════════════════════════════════════════╗" << RESET << std::endl;
    std::cout << BOLD_BLUE << "║           TYPE IDENTIFICATION TESTS                    ║" << RESET << std::endl;
    std::cout << BOLD_BLUE << "╚════════════════════════════════════════════════════════╝\n" << RESET << std::endl;

    std::cout << BOLD_CYAN << "=== TEST 1: Génération et identification ===" << RESET << std::endl;
    
    for (int i = 0; i < 5; i++) {
        std::cout << YELLOW << "\n--- Objet " << i + 1 << " ---" << RESET << std::endl;
        
        Base *obj = generate();
        
        std::cout << CYAN << "Identification par pointeur : " << RESET;
        identify(obj);
        
        std::cout << CYAN << "Identification par référence: " << RESET;
        identify(*obj);
        
        delete obj;
    }

    std::cout << BOLD_CYAN << "\n\n=== TEST 2: Test spécifique pour chaque type ===" << RESET << std::endl;

    std::cout << YELLOW << "\n--- Test avec A ---" << RESET << std::endl;
    Base *a = new A();
    std::cout << CYAN << "Identification par pointeur : " << RESET;
    identify(a);
    std::cout << CYAN << "Identification par référence: " << RESET;
    identify(*a);
    delete a;

    std::cout << YELLOW << "\n--- Test avec B ---" << RESET << std::endl;
    Base *b = new B();
    std::cout << CYAN << "Identification par pointeur : " << RESET;
    identify(b);
    std::cout << CYAN << "Identification par référence: " << RESET;
    identify(*b);
    delete b;

    std::cout << YELLOW << "\n--- Test avec C ---" << RESET << std::endl;
    Base *c = new C();
    std::cout << CYAN << "Identification par pointeur : " << RESET;
    identify(c);
    std::cout << CYAN << "Identification par référence: " << RESET;
    identify(*c);
    delete c;

    std::cout << BOLD_CYAN << "\n\n=== TEST 3: Polymorphisme (tableau de Base*) ===" << RESET << std::endl;
    
    Base *objects[6];
    objects[0] = new A();
    objects[1] = new B();
    objects[2] = new C();
    objects[3] = new A();
    objects[4] = new C();
    objects[5] = new B();

    for (int i = 0; i < 6; i++) {
        std::cout << YELLOW << "\nObjet " << i + 1 << ": " << RESET;
        identify(objects[i]);
    }

    for (int i = 0; i < 6; i++) {
        delete objects[i];
    }
	
    return 0;
}