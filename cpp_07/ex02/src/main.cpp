/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 18:26:23 by ainthana          #+#    #+#             */
/*   Updated: 2026/03/11 18:59:29 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Array.hpp"
#include <iostream>

#define BOLD_CYAN    "\033[1;36m"
#define BOLD_GREEN   "\033[1;32m"
#define BOLD_RED     "\033[1;31m"
#define YELLOW       "\033[33m"
#define GREEN        "\033[32m"
#define RED          "\033[31m"
#define RESET        "\033[0m"

int main() {
    std::cout << BOLD_CYAN << "\n╔════════════════════════════════════════╗" << RESET << std::endl;
    std::cout << BOLD_CYAN << "║         ARRAY TEMPLATE TESTS           ║" << RESET << std::endl;
    std::cout << BOLD_CYAN << "╚════════════════════════════════════════╝\n" << RESET << std::endl;

    std::cout << YELLOW << "=== Test 1: Constructeur par défaut ===" << RESET << std::endl;
    {
        Array<int> empty;
        std::cout << GREEN << "Taille : " << empty.size() << RESET << std::endl;
        // Attendu : 0
    }

    std::cout << YELLOW << "\n=== Test 2: Constructeur avec taille ===" << RESET << std::endl;
    {
        Array<int> arr(5);
        std::cout << GREEN << "Taille : " << arr.size() << RESET << std::endl;
        
        // Valeurs par défaut
        std::cout << "Valeurs par défaut : ";
        for (unsigned int i = 0; i < arr.size(); i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << YELLOW << "\n=== Test 3: Modification des éléments ===" << RESET << std::endl;
    {
        Array<int> arr(5);
        
        for (unsigned int i = 0; i < arr.size(); i++) {
            arr[i] = i * 10;
        }
        
        std::cout << "Valeurs modifiées : ";
        for (unsigned int i = 0; i < arr.size(); i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << YELLOW << "\n=== Test 4: Constructeur par copie ===" << RESET << std::endl;
    {
        Array<int> original(3);
        original[0] = 10;
        original[1] = 20;
        original[2] = 30;
        
        Array<int> copy(original);
        
        std::cout << "Original : ";
        for (unsigned int i = 0; i < original.size(); i++) {
            std::cout << original[i] << " ";
        }
        std::cout << std::endl;
        
        std::cout << "Copy : ";
        for (unsigned int i = 0; i < copy.size(); i++) {
            std::cout << copy[i] << " ";
        }
        std::cout << std::endl;
        
        copy[0] = 999;
        
        std::cout << "Après modification de copy[0] = 999 :" << std::endl;
        std::cout << "Original[0] : " << original[0] << " (doit rester 10)" << RESET << std::endl;
        std::cout << "Copy[0] : " << copy[0] << " (doit être 999)" << RESET << std::endl;
    }

    std::cout << YELLOW << "\n=== Test 5: Opérateur d'assignation ===" << RESET << std::endl;
    {
        Array<int> a(3);
        a[0] = 1;
        a[1] = 2;
        a[2] = 3;
        
        Array<int> b;
        b = a;
        
        std::cout << "a : ";
        for (unsigned int i = 0; i < a.size(); i++) {
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
        
        std::cout << "b : ";
        for (unsigned int i = 0; i < b.size(); i++) {
            std::cout << b[i] << " ";
        }
        std::cout << std::endl;
        
        b[0] = 100;
        std::cout << "Après b[0] = 100 :" << std::endl;
        std::cout << "a[0] : " << a[0] << " (doit rester 1)" << std::endl;
        std::cout << "b[0] : " << b[0] << " (doit être 100)" << std::endl;
    }
	
    std::cout << YELLOW << "\n=== Test 6: Exception out of bounds ===" << RESET << std::endl;
    {
        Array<int> arr(5);
        
        try {
            std::cout << "Accès à arr[10] :" << std::endl;
            arr[10] = 42;
            std::cout << BOLD_RED << "❌ ERREUR : Pas d'exception levée !" << RESET << std::endl;
        }
        catch (std::exception &e) {
            std::cout << BOLD_GREEN << "✓ Exception attrapée : " << e.what() << RESET << std::endl;
        }
    }

    std::cout << YELLOW << "\n=== Test 7: Array<std::string> ===" << RESET << std::endl;
    {
        Array<std::string> arr(3);
        arr[0] = "Hello";
        arr[1] = "World";
        arr[2] = "!";
        
        std::cout << "Contenu : ";
        for (unsigned int i = 0; i < arr.size(); i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
	
    return 0;
}