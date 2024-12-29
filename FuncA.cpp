#include "FuncA.h"
#include <cmath>

/**
 * @brief Calculate the sum of the first n elements of the hyperbolic cosine series.
 * 
 * @param x The input value for which the series is calculated.
 * @param n The number of terms to include in the series sum.
 * @return double The sum of the first n terms of the series.
 */
double FuncA::calculate(double x, int n) {
    double sum = 0.0;
    for (int k = 0; k < n; ++k) {
        double term = std::pow(x, 2 * k) / tgamma(2 * k + 1);
        sum += term;
    }
    return sum;
}
