
#include <algorithm>
#include <print>
#include <ranges>
#include <string>
#include <vector>
bool is_prime(int number) {
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}
int main() {
    using namespace std::views;
    auto count{0u};
    for (auto number :
         iota(2) | std::views::filter(&is_prime) | take_while([](auto x) { return x < 1'000; })) {
        std::println("{}", number);
        count++;
    }
}