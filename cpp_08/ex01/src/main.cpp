#include "../include/Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#define BOLD_GREEN   "\033[1;32m"
#define BOLD_RED     "\033[1;31m"
#define GREEN        "\033[32m"
#define RED          "\033[31m"
#define CYAN         "\033[36m"
#define RESET        "\033[0m"

int main() {
    std::cout << CYAN << "=== Test 1: Test du sujet ===" << RESET << std::endl;
    {
        Span sp = Span(5);
        
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
        std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
    }
    
    // ========== Test capacité ==========
    std::cout << CYAN << "\n=== Test 2: Dépassement de capacité ===" << RESET << std::endl;
    {
        Span sp(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        
        try {
            sp.addNumber(4);
            std::cout << GREEN << "✓ SUCESS !" << RESET << std::endl;
        }
        catch (std::exception& e) {
            std::cout << RED << "✗ Exception : " << e.what() << RESET << std::endl;
        }
    }
    
    std::cout << CYAN << "\n=== Test 3: Span avec 0 ou 1 nombre ===" << RESET << std::endl;
    {
        Span empty(10);
        
        try {
            empty.shortestSpan();
            std::cout << GREEN << "✓ SUCESS !" << RESET << std::endl;
        }
        catch (std::exception& e) {
            std::cout << RED << "✗ Exception span vide : " << e.what() << RESET << std::endl;
        }
        
        Span one(10);
        one.addNumber(42);
        
        try {
            one.longestSpan();
            std::cout << GREEN << "✓ SUCESS !" << RESET << std::endl;
        }
        catch (std::exception& e) {
            std::cout << RED << "✗ Exception 1 nombre : " << e.what() << RESET << std::endl;
        }
    }
    
    std::cout << CYAN << "\n=== Test 4: 10,000 nombres ===" << RESET << std::endl;
    {
        Span big(10000);
        
        for (int i = 0; i < 10000; i++) {
            big.addNumber(i);
        }
        
        std::cout << "Taille : " << big.size() << std::endl;
        std::cout << GREEN << "shortestSpan: " << big.shortestSpan() << RESET << std::endl;
        std::cout << GREEN << "longestSpan: " << big.longestSpan() << RESET << std::endl;
    }
    
    std::cout << CYAN << "\n=== Test 5: addRange avec dépassement ===" << RESET << std::endl;
    {
        std::vector<int> v;
        for (int i = 0; i < 100; i++) {
            v.push_back(i);
        }
        
        Span sp(50);
        
        try {
            sp.addRange(v.begin(), v.end());
            std::cout << GREEN << "✓ SUCESS !" << RESET << std::endl;
        }
        catch (std::exception& e) {
            std::cout << RED << "✗ Exception : " << e.what() << RESET << std::endl;
        }
    }
        
    return 0;
}