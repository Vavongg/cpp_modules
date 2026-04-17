#include "../include/RPN.hpp"

//canonical form

Rpn::Rpn() {

}

Rpn::Rpn(Rpn const &copy) {
	_stack = copy._stack;
}

Rpn &Rpn::operator=(Rpn const &copy) {

	if (this != &copy) 
		_stack = copy._stack;

	return *this;
}

Rpn::~Rpn() {

}

//method

void Rpn::calcul(std::string const &expression) {
    std::stringstream   ss(expression);
    std::string         token;

    while (ss >> token) {

        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (_stack.size() < 2) {
                std::cerr << RED << "Error" << RESET << "\n";
                return ;
            }
            long b = _stack.top(); _stack.pop();
            long a = _stack.top(); _stack.pop();

            if (token == "+")
				_stack.push(a + b);
            if (token == "-")
				_stack.push(a - b);
            if (token == "*")
				_stack.push(a * b);
            if (token == "/") {
                if (b == 0) {
                    std::cerr << RED << "Error: division by zero" << RESET << "\n";
                    return ;
                }
                _stack.push(a / b);
            }
        }
		else {
			
			std::stringstream ss1(token);
			long num;
			
			if (!(ss1 >> num)) {
				std::cerr << RED << "Error" << RESET << "\n";
				return ;
			}

			std::string remaining;
			ss1 >> remaining;
			
			if (!remaining.empty()) {
				std::cerr << RED << "Error" << RESET << "\n";
				return ;
			}

			_stack.push(num);
		}
    }

    if (_stack.size() != 1) {
        std::cerr << RED << "Error" << RESET << "\n";
        return ;
    }
    std::cout << GREEN << _stack.top() << RESET << "\n";
}

