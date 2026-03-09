/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:08:40 by ainthana          #+#    #+#             */
/*   Updated: 2026/03/09 15:28:30 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"
#include "../include/Data.hpp"

int main()
{
    std::cout << BOLD_BLUE << "\n╔════════════════════════════════════════════════════════╗" << RESET << std::endl;
    std::cout << BOLD_BLUE << "║           SERIALIZATION TESTS                          ║" << RESET << std::endl;
    std::cout << BOLD_BLUE << "╚════════════════════════════════════════════════════════╝" << RESET << std::endl;

    std::cout << BOLD_BLUE << "\n=== TEST 1: Sérialisation basique (objet sur la stack) ===" << RESET << std::endl;
    {
        Data original(42, "Stack Object");
        
        std::cout << YELLOW << "📦 Objet original:" << RESET << std::endl;
        std::cout << "   Adresse : " << &original << std::endl;
        std::cout << "   Value   : " << original.value << std::endl;
        std::cout << "   Name    : " << original.name << std::endl;

        std::cout << CYAN << "\n🔄 Sérialisation..." << RESET << std::endl;
        uintptr_t raw = Serializer::serialize(&original);
        std::cout << "   Valeur sérialisée : " << raw << std::endl;

        std::cout << CYAN << "\n🔄 Désérialisation..." << RESET << std::endl;
        Data* ptr = Serializer::deserialize(raw);
        std::cout << "   Adresse désérialisée : " << ptr << std::endl;

        std::cout << BOLD_GREEN << "\n✅ Vérification:" << RESET << std::endl;
        if (ptr == &original) {
            std::cout << GREEN << "   ✓ Les adresses sont IDENTIQUES" << RESET << std::endl;
            std::cout << GREEN << "   ✓ Value : " << ptr->value << RESET << std::endl;
            std::cout << GREEN << "   ✓ Name  : " << ptr->name << RESET << std::endl;
        } else {
            std::cout << BOLD_RED << "   ✗ ERREUR : Les adresses sont DIFFÉRENTES" << RESET << std::endl;
        }
    }

    std::cout << BOLD_BLUE << "\n=== TEST 2: Sérialisation avec allocation dynamique (heap) ===" << RESET << std::endl;
    {
        Data *original = new Data(100, "Heap Object");
        
        std::cout << YELLOW << "📦 Objet original (alloué dynamiquement):" << RESET << std::endl;
        std::cout << "   Adresse : " << original << std::endl;
        std::cout << "   Value   : " << original->value << std::endl;
        std::cout << "   Name    : " << original->name << std::endl;

        std::cout << CYAN << "\n🔄 Sérialisation..." << RESET << std::endl;
        uintptr_t raw = Serializer::serialize(original);
        std::cout << "   Valeur sérialisée : " << raw << std::endl;

        std::cout << CYAN << "\n🔄 Désérialisation..." << RESET << std::endl;
        Data* ptr = Serializer::deserialize(raw);
        std::cout << "   Adresse désérialisée : " << ptr << std::endl;

        std::cout << BOLD_GREEN << "\n✅ Vérification:" << RESET << std::endl;
        if (ptr == original) {
            std::cout << GREEN << "   ✓ Les adresses sont IDENTIQUES" << RESET << std::endl;
            std::cout << GREEN << "   ✓ Value : " << ptr->value << RESET << std::endl;
            std::cout << GREEN << "   ✓ Name  : " << ptr->name << RESET << std::endl;
        } else {
            std::cout << BOLD_RED << "   ✗ ERREUR : Les adresses sont DIFFÉRENTES" << RESET << std::endl;
        }

        delete original;
    }

	std::cout << BOLD_BLUE << "\n=== TEST 3: Constructeur par défaut ===" << RESET << std::endl;
	{
		Data original;
		
		std::cout << YELLOW << "📦 Objet créé avec constructeur par défaut:" << RESET << std::endl;
		std::cout << "   Adresse : " << &original << std::endl;
		std::cout << "   Value   : " << original.value << std::endl;
		std::cout << "   Name    : " << original.name << std::endl;

		// ← AJOUT : Afficher la sérialisation
		std::cout << CYAN << "\n🔄 Sérialisation..." << RESET << std::endl;
		uintptr_t raw = Serializer::serialize(&original);
		std::cout << "   Valeur sérialisée : " << raw << std::endl;

		// ← AJOUT : Afficher la désérialisation
		std::cout << CYAN << "\n🔄 Désérialisation..." << RESET << std::endl;
		Data* ptr = Serializer::deserialize(raw);
		std::cout << "   Adresse désérialisée : " << ptr << std::endl;

		std::cout << BOLD_GREEN << "\n✅ Vérification:" << RESET << std::endl;
		if (ptr == &original) {
			std::cout << GREEN << "   ✓ Les adresses sont IDENTIQUES" << RESET << std::endl;
		} else {
			std::cout << BOLD_RED << "   ✗ ERREUR : Les adresses sont DIFFÉRENTES" << RESET << std::endl;
		}
	}
	std::cout << BOLD_BLUE << "\n=== TEST 4: Multiples sérialisations ===" << RESET << std::endl;
	{
		Data obj1(1, "First");
		Data obj2(2, "Second");
		Data obj3(3, "Third");

		std::cout << YELLOW << "📦 Trois objets créés:" << RESET << std::endl;
		std::cout << "   obj1 : " << &obj1 << " (value=" << obj1.value << ")" << std::endl;
		std::cout << "   obj2 : " << &obj2 << " (value=" << obj2.value << ")" << std::endl;
		std::cout << "   obj3 : " << &obj3 << " (value=" << obj3.value << ")" << std::endl;

		std::cout << CYAN << "\n🔄 Sérialisation des 3 objets..." << RESET << std::endl;
		uintptr_t raw1 = Serializer::serialize(&obj1);
		uintptr_t raw2 = Serializer::serialize(&obj2);
		uintptr_t raw3 = Serializer::serialize(&obj3);

		std::cout << "   raw1 : " << raw1 << std::endl;
		std::cout << "   raw2 : " << raw2 << std::endl;
		std::cout << "   raw3 : " << raw3 << std::endl;

		std::cout << CYAN << "\n🔄 Désérialisation des 3 objets..." << RESET << std::endl;
		Data* ptr1 = Serializer::deserialize(raw1);
		Data* ptr2 = Serializer::deserialize(raw2);
		Data* ptr3 = Serializer::deserialize(raw3);

		std::cout << "   ptr1 : " << ptr1 << std::endl;
		std::cout << "   ptr2 : " << ptr2 << std::endl;
		std::cout << "   ptr3 : " << ptr3 << std::endl;

		std::cout << BOLD_GREEN << "\n✅ Vérifications:" << RESET << std::endl;
		if (ptr1 == &obj1 && ptr2 == &obj2 && ptr3 == &obj3) {
			std::cout << GREEN << "   ✓ Toutes les adresses sont IDENTIQUES" << RESET << std::endl;
			std::cout << GREEN << "   ✓ ptr1->value = " << ptr1->value << RESET << std::endl;
			std::cout << GREEN << "   ✓ ptr2->value = " << ptr2->value << RESET << std::endl;
			std::cout << GREEN << "   ✓ ptr3->value = " << ptr3->value << RESET << std::endl;
		} else {
			std::cout << BOLD_RED << "   ✗ ERREUR : Au moins une adresse est incorrecte" << RESET << std::endl;
		}
	}
}