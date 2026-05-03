// This exercise was extremely confusing.
#include <array>
#include <format>
#include <forward_list>
#include <iterator>
#include <list>
#include <print>
#include <span>
#include <string>
#include <vector>

template <std::random_access_iterator Iter, std::integral Off>
auto advance(Iter it, Off offset) {
    return it += offset;
}
template <std::bidirectional_iterator Iter, std::integral Off>
auto advance(Iter it, Off offset) {
    if (offset > 0) {
        while (offset != 0) {
            ++it;
            --offset;
        }
    } else {
        while (offset != 0) {
            --it;
            ++offset;
        }
    }
}

template <std::forward_iterator Iter, std::integral Off>
    requires requires(Off o) {
        { o >= 0 } -> std::convertible_to<bool>;
    }

auto advance(Iter it, Off offset) {
    while (offset != 0) {
        --offset;
        ++it;
    }
    return it;
}
int main() {
    // Random-access iterators:
    std::vector v{1, 2, 3, 4, 5};
    std::println("{}", *advance(v.begin(), 3));

    // Bidirectional iterators:
    std::list l{1, 2, 3, 4, 5};
    std::println("{}", *advance(l.end(), -3));

    // Forward iterators:
    std::forward_list f{1, 2, 3, 4, 5};
    std::println("{}", *advance(f.begin(), 3));
}