#include "CurveBall.hpp"
#include <exception>
#include <functional>
#include <print>
#include <random>
auto createUniformPseudoRandomNumberGenerator(uint32_t min, uint32_t max)

{
    std::random_device seeder; // True random number generator to obtain a seed (slow)

    std::default_random_engine generator{seeder()}; // Efficient pseudo-random generator

    std::uniform_int_distribution distribution{min, max}; // Generate in [1, max) interval

    return std::bind(distribution, generator); //... and in the darkness bind them!
}
int main() {
    auto rng = createUniformPseudoRandomNumberGenerator(1, 100);
    size_t exception_count{0};
    for (size_t i{0}; i < 1'000'000; i++) {
        try {
            if (rng() <= 25) {
                throw CurveBall{};
            }

        } catch (const std::exception& exception) {
            exception_count++;
        }
    }
    std::println("Total exception count is {}", exception_count);
}
