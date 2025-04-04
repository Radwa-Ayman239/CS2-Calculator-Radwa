#ifndef PARSING_H
#define PARSING_H

#include <string>

class Calculator {
private:
    std::string expr;
    int pos;

    char nextChar();
    void stepBack();
    double calcExpression();
    double calcTerm();
    double calcNumber();

public:
    Calculator(std::string e);
    double evaluate();
};

#endif // PARSING_H
