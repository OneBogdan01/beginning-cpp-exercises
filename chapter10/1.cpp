#include "pch.hpp"

template <typename T>
auto clamp(T lower, T upper, T a) {
    if (a < lower)
        return lower;
    if (a > upper)
        return upper;
    return a;
}
int main() {
    int a = 3;
    int b = 5;
    int value;
    std::cin >> value;
    std::println("{} ", clamp(a, b, value));
}
