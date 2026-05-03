// This exercise was extremely confusing.
#include <array>
#include <format>
#include <iostream>
#include <iterator>
#include <print>
#include <span>
#include <string>
#include <vector>
#include <ranges>

template <typename T>
// dark magic of checking if moving stuff is noexcept
concept NoExcept = requires(T left, T right) {
    { left = std::move(right) } noexcept -> std::same_as<T&>;
};

// unconstained
auto& move_assign_if_noexcept(auto& x) noexcept {
    return x;
}
auto&& move_assign_if_noexcept(NoExcept auto& x) noexcept {
    return std::move(x);
}

struct Safe {
    std::string s;
    Safe(const char* v) : s(v) {}
    Safe(const Safe&) = default;
    Safe(Safe&&) noexcept = default;
    Safe& operator=(const Safe& o) {
        std::println("  COPY");
        s = o.s;
        return *this;
    }
    Safe& operator=(Safe&& o) noexcept {
        std::println("   MOVE");
        s = std::move(o.s);
        return *this;
    }
};
struct Risky {
    std::string s;
    Risky(const char* v) : s(v) {}
    Risky(const Risky&) = default;
    Risky(Risky&&) {}
    Risky& operator=(const Risky& o) {
        std::println("  Risky: COPY");
        s = o.s;
        return *this;
    }
    Risky& operator=(Risky&& o) {
        std::println("  Risky: MOVE");
        s = std::move(o.s);
        return *this;
    }
};

int main() {
    {
        Safe a{"A"}, b{"B"};
        a = move_assign_if_noexcept(b);
        std::println("  after: a={}  b={} \n", a.s, b.s);
    }
    {
        Risky a{"A"}, b{"B"};
        a = move_assign_if_noexcept(b);
        std::println("  after: a={}  b={} ", a.s, b.s);
    }
}
