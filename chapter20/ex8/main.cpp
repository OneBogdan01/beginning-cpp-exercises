

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
    std::ranges::generate(numbers.begin(), numbers.end(), random);
    std::ranges::sort(numbers);
    std::println("Count of numbers {}", numbers.size());

    auto rem{std::ranges::unique(numbers)};
    numbers.erase(rem.begin(), rem.end());
    std::println("Count of numbers after unique() {}", numbers.size());
}

std::vector<int> fillVector_1toN(int N) {
    // std::vector<int> numbers;
    // for (int i{1}; i <= N; ++i)
    //     numbers.push_back(i);
    // return numbers;
    std::vector numbers{std::ranges::to<std::vector<int>>(std::views::iota(1, N + 1))};
    return numbers;
}

void removeEvenNumbers(auto& numbers) /* Correct! */
{
    // for (auto iter{numbers.begin()}; iter != numbers.end();) {
    //     if (*iter % 2 == 0)
    //         iter = numbers.erase(iter);
    //     else
    //         ++iter;
    // }
    auto only_odd_numbers_view{numbers | std::views::filter([](auto x) { return x % 2 == 1; })};
    numbers = std::ranges::to<std::vector<int>>(only_odd_numbers_view);
}