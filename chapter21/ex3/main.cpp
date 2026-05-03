// This exercise was extremely confusing.
#include <array>
#include <format>
#include <iterator>
#include <print>
#include <span>
#include <string>
#include <vector>

template <typename T, std::size_t N>
auto medianOfSorted(std::span<T, N> s)
    requires(N != std::dynamic_extent)
{
    static_assert(s.empty() == false);
    auto size{s.size()};
    if (size % 2 == 0) {
        return (s[size / 2 - 1] + s[size / 2]) / 2;
    } else {
        return s[size / 2];
    }
}

int main() {
    std::array values_odd{1, 2, 3, 4, 5, 6, 7};
    std::println("{}", medianOfSorted(std::span{values_odd}));

    std::array values_even{1., 2., 3., 4., 5., 6.};
    std::println("{}", medianOfSorted(std::span{values_even}));
}