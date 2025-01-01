#include "FuncA.h"
#include <cassert>
#include <chrono>
#include <iostream>

/**
 * @brief Test to verify that the calculation time is within 5 to 20 seconds.
 */
void test_calculate_time_within_range() {
    FuncA func;
    const int x_start = 1;
    const int x_end = 100;
    const int n_start = 500;
    const int n_end = 1000;

    auto start_time = std::chrono::high_resolution_clock::now();

    // Perform computation
    for (int x = x_start; x <= x_end; ++x) {
        for (int n = n_start; n <= n_end; ++n) {
            func.calculate(static_cast<double>(x), n);
        }
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    double elapsed_time = std::chrono::duration<double>(end_time - start_time).count();

    // Assert that elapsed time is within the range [5, 20] seconds
    std::cout << "Elapsed time: " << elapsed_time << " seconds" << std::endl;
    assert(elapsed_time >= 5.0 && "Elapsed time is less than 5 seconds");
    assert(elapsed_time <= 20.0 && "Elapsed time is greater than 20 seconds");
}

int main() {
    try {
        test_calculate_time_within_range();
        std::cout << "Test passed: Calculation time is within the expected range.\n";
    } catch (const std::exception &e) {
        std::cerr << "Test failed: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
