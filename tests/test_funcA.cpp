#include <iostream>
#include <cassert>
#include "../FuncA.h"

void test_calculate() {
    FuncA func;
    assert(func.calculate(0, 5) == 1.0);  // cosh(0) = 1.0
    assert(func.calculate(1, 5) > 1.0);   // Check approximation
    std::cout << "All tests passed!" << std::endl;
}

int main() {
    test_calculate();
    return 0;
}
