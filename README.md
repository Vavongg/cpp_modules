<div align="center">

# 🎓 42 C++ Modules

*A series of 42 school projects designed to master Object-Oriented Programming (OOP) in C++.*

[![C++](https://img.shields.io/badge/C++-98-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://cplusplus.com/)
[![Norme](https://img.shields.io/badge/Norme-42-000000?style=for-the-badge&logo=42&logoColor=white)](https://42.fr/)
[![Build](https://img.shields.io/badge/Make-GNU-brightgreen?style=for-the-badge&logo=gnu&logoColor=white)](https://www.gnu.org/software/make/)

</div>

---

## 📝 About this repository

This repository contains all the C++ modules from the 42 school curriculum (`cpp_00` to `cpp_09`). The goal of these modules is to progressively introduce the fundamental concepts of C++ and OOP, while **strictly adhering to the C++98 standard**.

### Core concepts covered:
- Classes, objects, member functions, and constructors/destructors.
- Orthodox Canonical Class Form.
- Dynamic memory allocation (`new` and `delete` operators).
- Polymorphism, inheritance, and interfaces.
- Operator overloading.
- Exceptions.
- Templates (functions and classes).
- STL (Standard Template Library) containers and algorithms.

---

## 📚 Modules Overview

| Module | Topics Covered | Notable Projects |
| :--- | :--- | :--- |
| **CPP 00** | Namespaces, classes, member functions, stdio streams, initialization lists. | `Megaphone`, `PhoneBook` |
| **CPP 01** | Memory allocation, pointers, references, switch statement. | `Zombies`, `Harl` |
| **CPP 02** | Ad-hoc polymorphism, operator overloading, Orthodox Canonical class form. | `Fixed` (Fixed-point numbers) |
| **CPP 03** | Inheritance. | `ClapTrap`, `ScavTrap`, `FragTrap` |
| **CPP 04** | Subtype polymorphism, abstract classes, interfaces. | `Animal`, `Brain` |
| **CPP 05** | Repetition and Exceptions (`try`/`catch`). | `Bureaucrat`, `Forms` |
| **CPP 06** | C++ Casts (`static`, `dynamic`, `reinterpret`, `const`). | `ScalarConverter`, `Serializer` |
| **CPP 07** | C++ Templates. | `Whatever`, `Iter`, `Array` |
| **CPP 08** | Templated containers, iterators, and algorithms. | `easyfind`, `Span`, `MutantStack` |
| **CPP 09** | STL (Standard Template Library). | `BitcoinExchange`, `RPN`, `PmergeMe` (Ford-Johnson) |

---

## 📂 Standard Exercise Structure

Each exercise in every module has its own independent structure to compile a specific executable:

```text
cpp_XX/
└── exYY/
    ├── Makefile         # Compilation rules (all, clean, fclean, re)
    ├── include/         # Header files (.hpp)
    └── src/             # Source files (.cpp)
```

---

## 🛠️ Prerequisites & Compilation

To compile these projects, you need a Unix environment (macOS or Linux) with `make` and a C++ compiler (such as `c++`, `clang++`, or `g++`).

All projects are compiled with the strict 42 school flags, including the restriction to the C++98 standard:
```bash
c++ -Wall -Wextra -Werror -std=c++98
```

---

## 🚀 Usage

To test a specific exercise, navigate to its folder and use `make`:

1. **Go to the exercise folder:**
   ```bash
   cd cpp_09/ex02
   ```

2. **Compile the project:**
   ```bash
   make
   ```

3. **Run the compiled executable (example with PmergeMe):**
   ```bash
   ./PmergeMe 3 5 9 7 4
   ```

4. **Clean up compiled files:**
   ```bash
   make fclean
   ```

---

<div align="center">

Made by [Vavongg](https://github.com/Vavongg)

</div>
