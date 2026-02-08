#include "pch.hpp"

void fib_rec(u32 number, u32 a = 0, u32 b = 1) {
    std::println("{}", b);

    if (number == 1) {
        return;
    }

    fib_rec(--number, b, a + b);
}
void fib_loop(u32 n) {
    u32 a = 0;
    u32 b = 1;
    for (u32 i{0}; i < n; i++) {
        std::println("{}", b);
        auto c = a + b;
        a = b;
        b = c;
    }
}
int main() {
    std::println("Enter how many fibonacci numbers to generate");
    u32 n;
    std::cin >> n;
    fib_loop(n);
}
