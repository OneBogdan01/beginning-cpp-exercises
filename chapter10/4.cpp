#include "pch.hpp"

template <typename T, size_t N>
decltype(auto) my_size(const T (&array)[N]) {
    return N;
}
template <typename T>
decltype(auto) my_size(const T(&array)) {
    size_t count = 0;
    for (auto iter = array.begin(); iter != array.end(); ++iter) {
        count++;
    }
    return count;
}
int main() {
    double doubles[2]{1.0, 2.0};
    std::println("{}", my_size(doubles));
    double moreDoubles[]{1.0, 2.0, 3.0, 4.0};
    std::println("{}", my_size(moreDoubles));

    std::println("{}", my_size({1.0, 2.0, 3.0, 4.0}));
    int ints[]{1, 2, 3, 4};
    std::println("{}", my_size(ints));
    std::vector<int> vec{1, 2};
    std::array<int, 5> arr;
    ;
    std::println("{}", my_size(vec));
    std::println("{}", my_size(arr));
}
