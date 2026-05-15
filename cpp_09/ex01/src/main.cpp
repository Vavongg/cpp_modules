#include "../include/RPN.hpp"


#include "../include/RPN.hpp"

int main(int argc, char **argv) {

    if (argc != 2) {
        std::cerr << "Error: usage: ./RPN \"expression\"" << std::endl;
        return 1;
    }

    Rpn rpn;
    rpn.calcul(argv[1]);

    return 0;
}