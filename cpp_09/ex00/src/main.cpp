#include "../include/BitcoinExchange.hpp"

int main(int argc, char **argv) {

    if (argc != 2) {
        std::cerr << RED << "Error: could not open file." << RESET << "\n";
        return 1;
    }

    try {
        BitcoinExchange btc;
        btc.loadDatabase("data.csv");
        btc.processInput(argv[1]);
    }
    catch (std::exception &e) {
        std::cerr << RED << e.what() << RESET << "\n";
        return 1;
    }

    return 0;
}