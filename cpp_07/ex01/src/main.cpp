/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 17:31:03 by ainthana          #+#    #+#             */
/*   Updated: 2026/03/11 17:31:30 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Iter.hpp"

template <typename T>
void print(T const &x) {
    std::cout << x << std::endl;
}

void increment(int &x) {
    x++;
}

void toUpper(char &c) {
    if (c >= 'a' && c <= 'z')
        c = c - 32;
}

int main(void) {
    std::cout << "=== Test 1: Tableau d'int ===" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    iter(intArray, 5, print<int>);
    
    std::cout << "\n=== Test 2: Incrémenter ===" << std::endl;
    iter(intArray, 5, increment);
    iter(intArray, 5, print<int>);
    
    std::cout << "\n=== Test 3: Tableau de string ===" << std::endl;
    std::string strArray[] = {"Hello", "World", "42"};
    iter(strArray, 3, print<std::string>);
    
    std::cout << "\n=== Test 4: Tableau de char ===" << std::endl;
    char charArray[] = {'a', 'b', 'c', 'd'};
    iter(charArray, 4, toUpper);
    iter(charArray, 4, print<char>);
    
    std::cout << "\n=== Test 5: Tableau const ===" << std::endl;
    const int constArray[] = {10, 20, 30};
    iter(constArray, 3, print<int>);
    
    return 0;
}