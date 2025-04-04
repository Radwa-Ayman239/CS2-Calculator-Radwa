#include <iostream>
#include "calculator.h"
#include "Parsing.h"
using namespace std;

int main() {
    cout << "Addition: " << add(3, 5) <<endl;
    cout << "Factorial of 5: " << factorial(5) <<endl;
    cout << "GCD of 20 and 8: " << gcd(20, 8) <<endl;
    cout << "Random number (1-10): " << randomInRange(1, 10) <<endl;
cout<<"============================"<<endl;
 string input = "3 + 4 * (2 - 1) / 5";
    Calculator calc(input);
    cout << "Result: " << calc.evaluate() << endl;

    return 0;
}