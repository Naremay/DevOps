#ifndef FUNCA_H
#define FUNCA_H

/**
 * @class FuncA
 * @brief Class to calculate the sum of n terms in the hyperbolic cosine series.
 */
class FuncA {
public:
    /**
     * @brief Calculate the sum of n terms in the series.
     * @param x Input value for calculation.
     * @param n Number of terms to sum.
     * @return Result of the series calculation.
     */
    double calculate(double x, int n);
};

#endif // FUNCA_H
