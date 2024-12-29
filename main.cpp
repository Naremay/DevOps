#include <iostream>
#include "FuncA.h"

int main() {
    FuncA func;

    double x = 1.0;
    int n = 5;
    std::cout << "Result: " << func.calculate(x, n) << std::endl;

    return 0;
}

