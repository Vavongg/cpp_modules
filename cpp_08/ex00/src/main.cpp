#include "../include/easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

int main() {
    std::cout << "\n========== TEST 1: vector<int> ==========" << std::endl;
    {
        std::vector<int> v;
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);
        v.push_back(40);
        v.push_back(50);
        
        // Valeur présente
        try {
            std::vector<int>::iterator it = easyfind(v, 30);
            std::cout << GREEN << "✓ Trouvé : " << *it << RESET << std::endl;
            std::cout << "Position : " << (it - v.begin()) << std::endl;
        }
        catch (std::exception& e) {
            std::cout << RED << "✗ Erreur : " << e.what() << RESET << std::endl;
        }
        
        // Valeur absente
        try {
            easyfind(v, 100);
            std::cout << GREEN << "✗ ERREUR : Pas d'exception levée" << RESET << std::endl;
        }
        catch (std::exception& e) {
            std::cout << RED << "✗ Exception : " << e.what() << RESET << std::endl;
        }
        
        // Premier élément
        try {
            std::vector<int>::iterator it = easyfind(v, 10);
            std::cout << GREEN << "✓ Trouvé : " << *it << RESET << std::endl;
			std::cout << "Position : " << (it - v.begin()) << std::endl;
        }
        catch (std::exception& e) {
            std::cout << RED << "✗ Erreur : " << e.what() << RESET << std::endl;
        }
        
        // Dernier élément
        try {
            std::vector<int>::iterator it = easyfind(v, 50);
            std::cout << GREEN << "✓ Trouvé : " << *it << RESET << std::endl;
			std::cout << "Position : " << (it - v.begin()) << std::endl;
        }
        catch (std::exception& e) {
            std::cout << RED << "✗ Erreur : " << e.what() << RESET << std::endl;
        }
    }
    
    std::cout << "\n========== TEST 2: list<int> ==========" << std::endl;
    {
        std::list<int> lst;
        lst.push_back(100);
        lst.push_back(200);
        lst.push_back(300);
        
        try {
            std::list<int>::iterator it = easyfind(lst, 200);
            std::cout << GREEN << "✓ Trouvé dans list : " << *it << RESET << std::endl;
        }
        catch (std::exception& e) {
            std::cout << RED << "✗ Erreur : " << e.what() << RESET << std::endl;
        }
        
        try {
            easyfind(lst, 999);
            std::cout << GREEN << "✗ ERREUR : Pas d'exception levée" << RESET << std::endl;
        }
        catch (std::exception& e) {
            std::cout << RED << "✗ Exception : " << e.what() << RESET << std::endl;
        }
    }
    
    std::cout << "\n========== TEST 3: deque<int> ==========" << std::endl;
    {
        std::deque<int> dq;
        dq.push_back(5);
        dq.push_back(15);
        dq.push_back(25);
        
        try {
            std::deque<int>::iterator it = easyfind(dq, 15);
            std::cout << GREEN << "✓ Trouvé dans deque : " << *it << RESET << std::endl;
        }
        catch (std::exception& e) {
            std::cout << RED << "✗ Erreur : " << e.what() << RESET << std::endl;
        }
    }
    
    std::cout << "\n========== TEST 4: Conteneur vide ==========" << std::endl;
    {
        std::vector<int> empty;
        
        try {
            easyfind(empty, 42);
            std::cout << GREEN << "✗ ERREUR : Pas d'exception levée" << RESET << std::endl;
        }
        catch (std::exception& e) {
            std::cout << RED << "✗ Exception sur conteneur vide : " << e.what() << RESET << std::endl;
        }
    }
    
    std::cout << "\n========== TEST 5: Première occurrence ==========" << std::endl;
    {
        std::vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(2);
        v.push_back(4);
        
        try {
            std::vector<int>::iterator it = easyfind(v, 2);
            std::cout << GREEN << "✓ Première occurrence de 2 trouvée" << RESET << std::endl;
            std::cout << "Position : " << (it - v.begin()) << std::endl;
        }
        catch (std::exception& e) {
            std::cout << RED << "✗ Erreur : " << e.what() << RESET << std::endl;
        }
    }
    
    return 0;
}