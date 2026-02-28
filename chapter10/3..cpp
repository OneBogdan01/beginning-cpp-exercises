#include "pch.hpp"

template <typename T1, typename T2>
decltype(auto) plus(const T1& a, const T2& b) {
    if constexpr (std::is_pointer_v<T1>) {
        return *a + *b;
    } else {
        return a + b;
    }
}
std::string plus(const char* a, const char* b) {
    return std::string{a} + std::string{b};
}
int main() {
    auto sum = plus(2, 3.5);
    auto* a = &sum;

    auto sum2 = plus(2, 3);
    std::println("{} {}", sum, sum2);
    std::println("{}", plus(a, a));
    std::println("{}", plus("Alina", " likes Voley"));
}
