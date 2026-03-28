#include <array>
#include <exception>
#include <print>
#include <string>
#include <vector>
int main() {
    try {
        std::array<int, 1> array;
        // out of range
        array.at(1);
    } catch (const std::exception& ex) {
        std::println("{}", ex.what());
    }

    try {
        std::stoi("nan");
    } catch (const std::exception& ex) {
        std::println("{}", ex.what());
    }

    try {
        auto p = new int[99999999999999999];
    } catch (const std::exception& ex) {
        std::println("{}", ex.what());
    }

    try {
        std::vector<int> v;
        v.reserve(v.max_size());
    } catch (const std::exception& ex) {
        std::println("{}", ex.what());
    }
    try {
        std::stoi("99999999999999999999999999999999");

    } catch (const std::exception& ex) {
        std::println("{}", ex.what());
    }
}
