#include "pch.hpp"
f64 mult(f64 x, f64 y) {
    static u64 multi_count = 0u;
    std::println("{}", multi_count++);
    return x * y;
}

double power(double x, int n) {
    if (n == 0)
        return 1.0;
    if (n > 0) {
        auto half_power = power(x, n / 2);
        if (n % 2 == 0) {
            return mult(half_power, half_power);
        }
        return mult(x, mult(half_power, half_power));
    }

    return 1.0 / power(x, -n);
}

int main() {
    power(1.5, 1000);
} // Recursive function to calculate x to the power n
