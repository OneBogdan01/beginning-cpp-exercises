#include "pch.hpp"

#include <iostream>

bool is_prime(u32 number) {
    if (number < 2) {
        return false;
    }
    for (u32 i{2}; i * i <= number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}
std::vector<u32> generate_natural_numbers(u32 less_equal_then, u32 starting_from = 1) {
    std::vector<u32> natural_numbers;
    for (u32 i{starting_from}; i <= less_equal_then; i++) {
        natural_numbers.emplace_back(i);
    }
    return natural_numbers;
}
std::vector<u32> generate_prime_numbers(const std::vector<u32>& input) {
    std::vector<u32> primes;
    for (u32 number : input) {
        if (is_prime(number) == true) {
            primes.emplace_back(number);
        }
    }
    return primes;
}
int main() {
    u32 less_eq_than_input;
    std::cin >> less_eq_than_input;
    auto natural_numbers = generate_natural_numbers(less_eq_than_input);
    auto prime_numbers = generate_prime_numbers(natural_numbers);
    for (u32 prime_number : prime_numbers) {
        static u32 numbers_per_line = 15;
        std::print("{} ", prime_number);
        if (--numbers_per_line == 0) {
            std::println("");
            numbers_per_line = 15;
        }
    }
}
