#include <iostream>
#include "FuncA.h"

int main() {
    FuncA func;

    // Input values for x and n
    double x;
    int n;

    std::cout << "Enter the value of x: ";
    std::cin >> x;
    std::cout << "Enter the number of terms (n): ";
    std::cin >> n;

    std::cout << "Result: " << func.calculate(x, n) << std::endl;

    return 0;
}

