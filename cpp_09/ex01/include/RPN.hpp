#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <list>
#include <string>
#include <iostream>
#include <sstream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

class Rpn {

    private:
        std::stack<int, std::list<int> > _stack;

    public:
        Rpn();
        Rpn(Rpn const &copy);
        Rpn &operator=(Rpn const &copy);
        ~Rpn();

        void calcul(std::string const &expression);
};

#endif