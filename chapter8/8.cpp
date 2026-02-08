#include "pch.hpp"

double power(double x, int n);
double power_faster(double x, int n);

int main() {
    for (int i{-3}; i <= 3; ++i) // Calculate powers of 8 from -3 to +3
    {
        std::print("{:10g}", power_faster(8.0, i));
    }

    std::println("");
    for (int i{-3}; i <= 3; ++i) // Calculate powers of 8 from -3 to +3
    {
        std::print("{:10g}", power(8.0, i));
    }

    std::println("");
}

// Recursive function to calculate x to the power n
double power(double x, int n) {
    if (n == 0)
        return 1.0;
    if (n > 0) {
        return x * power(x, n - 1);
    }

    return 1.0 / power(x, -n);
}

double power_faster(double x, int n) {
    if (n == 0)
        return 1.0;
    if (n > 0) {
        auto half_power = power(x, n / 2);
        if (n % 2 == 0) {
            return half_power * half_power;
        }
        return x * half_power * half_power;
    }

    return 1.0 / power(x, -n);
}
