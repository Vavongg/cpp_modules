#include "../include/RPN.hpp"


#include "../include/RPN.hpp"

int main(int argc, char **argv) {

    if (argc != 2) {
        std::cerr << RED << "Error: usage: ./RPN <expression>" << RESET << "\n";
        return 1;
    }

    Rpn rpn;
    rpn.calcul(argv[1]);

    return 0;
}