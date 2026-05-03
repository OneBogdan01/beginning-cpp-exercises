// This exercise was extremely confusing.
#include <array>
#include <format>
#include <iterator>
#include <print>
#include <span>
#include <string>
#include <vector>
#include <ranges>
template <std::ranges::range Range>
    requires requires(std::ranges::range_value_t<Range> e) {
        { e / 2 } -> std::same_as<decltype(e)>;
        { e + 2 } -> std::same_as<decltype(e)>;
    }

auto medianOfSorted(Range range) {
    auto size = std::ranges::size(range);
    auto mid = std::ranges::begin(range);
    std::ranges::advance(mid, size / 2);
    if (size % 2 == 1) {
        return *mid;
    }
    auto before_mid{std::ranges::begin(range)};
    std::ranges::advance(before_mid, size / 2 - 1);

    return (*before_mid + *mid) / 2;
}
template <std::ranges::range Range>
auto medianOfSorted(Range range) {
    auto mid = std::ranges::begin(range);
    std::ranges::advance(mid, std::ranges::size(range) / 2);
    return *mid;
}
int main() {
    std::array values_odd{1, 2, 3, 4, 5, 6, 7};
    std::println("{}", medianOfSorted(values_odd));

    std::array values_even{1., 2., 3., 4., 5., 6.};
    std::println("{}", medianOfSorted(values_even));

    std::array strings{"Jo", "JOJO", "Mojo"};
    std::println("{}", medianOfSorted(strings));
}