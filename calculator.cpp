#include "calculator.h"
#include <stdexcept>
#include <random>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0.0){
cout<<"Cannot divide by zero!";
return 0.0; 
}
    return a / b;
}

int factorial(int n) {
    if (n < 0){
cout<<"Invalid value";

}
int result = 1;
     
    for (int i = 2; i <= n; ++i){
 result *= i;}
    return result;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return abs(a * b) / gcd(a, b);
}

int randomInRange(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(min, max);
    return distr(gen);
}