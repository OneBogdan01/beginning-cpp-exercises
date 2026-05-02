

#include <execution>
#include <functional>
#include <print>
#include <random>
#include <ranges>
#include <vector>
auto createUniformPseudoRandomNumberGenerator(int max) {
    std::random_device seeder; // True random number generator to obtain a seed (slow)
    std::default_random_engine generator{seeder()};       // Efficient pseudo-random generator
    std::uniform_int_distribution<> distribution{0, max}; // Generate in [0, max) interval
    return std::bind(distribution, generator);            //... and in the darkness bind them!
}

int main() {
    auto random{createUniformPseudoRandomNumberGenerator(10'000)};

    std::vector numbers(100'000, 10);
    std::ranges::generate(numbers, random);
    std::sort(std::execution::par, numbers.begin(), numbers.end());
    std::println("Count of numbers {}", numbers.size());

    auto it{std::unique(std::execution::par, numbers.begin(), numbers.end())};
    numbers.erase(it, numbers.end());
    std::println("Count of numbers after unique() {}", numbers.size());
}
