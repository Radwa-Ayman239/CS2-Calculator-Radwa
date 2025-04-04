#include "Parsing.h"
#include <cctype>

Calculator::Calculator(std::string e) : expr(e), pos(0) {}

char Calculator::nextChar() {
    if (pos < expr.length()) return expr[pos++];
    return '\0';
}

void Calculator::stepBack() {
    if (pos > 0) pos--;
}

double Calculator::calcExpression() {
    double result = calcTerm();
    char op;
    while ((op = nextChar()) == '+' || op == '-') {
        double term = calcTerm();
        result = (op == '+') ? result + term : result - term;
    }
    stepBack();
    return result;
}

double Calculator::calcTerm() {
    double result = calcNumber();
    char op;
    while ((op = nextChar()) == '*' || op == '/') {
        double num = calcNumber();
        result = (op == '*') ? result * num : result / num;
    }
    stepBack();
    return result;
}

double Calculator::calcNumber() {
    char ch = nextChar();
    while (ch == ' ') ch = nextChar(); 

    if (isdigit(ch)) {
        double num = ch - '0';
        while (isdigit(expr[pos])) {
            num = num * 10 + (expr[pos] - '0');
            pos++;
        }
        return num;
    } else if (ch == '(') {
        double value = calcExpression();
        nextChar(); // Consume ')'
        return value;
    }
    return 0; 
}
