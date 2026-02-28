#include "pch.hpp"

template <typename T>
T larger(T a, T b); // Function template prototype
// template <typename T>
// T* larger(T* a, T* b); // Function template prototype

const char* larger(const char* a, const char* b);
int main() {
    std::println("Larger of 1.5 and 2.5 is {}", larger(1.5, 2.5));
    std::println("Larger of 3.5 and 4.5 is {}", larger(3.5, 4.5));

    const int big_int{17011983}, small_int{10};
    std::println("Larger of {} and {} is {}", big_int, small_int, larger(big_int, small_int));

    const auto z_string = "Z";
    const auto a_string = "A";

    // This comparison is made against pointers, not the actual characters, this is why it depends
    // on the order that they are declared
    std::println("Larger of {} and {} is {}", a_string, z_string, larger(a_string, z_string));
}

// Template for functions to return the larger of two values
template <typename T>
T larger(T a, T b) {
    return a > b ? a : b;
}
const char* larger(const char* a, const char* b) {
    return std::string_view{a} > std::string_view{b} ? a : b;
}

// template <typename T>
// T* larger(T* a, T* b) {
//     return *a > *b ? a : b;
// }
