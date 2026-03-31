#include <print>
#include "Array.hpp"

#include <functional>
#include <iostream>
#include <random>
auto createUniformPseudoRandomNumberGenerator(int min, int max) {
    std::random_device seeder; // True random number generator to obtain a seed (slow)
    std::default_random_engine generator{seeder()}; // Efficient pseudo-random generator
    std::uniform_int_distribution distribution{min, max};
    return std::bind(distribution, generator); //... and in the darkness bind them!
}

int main() {
    auto index_generator = createUniformPseudoRandomNumberGenerator(0, 499);
    auto value_generator = createUniformPseudoRandomNumberGenerator(32, 212);
    SparseArray<int> array;
    for (size_t i{}; i < 20; i++) {
        auto random_index = index_generator();
        array[random_index] = value_generator();
        std::println("Inserted at index {}, the value {}", random_index, array[random_index]);
    }
    std::cout << array;
}
