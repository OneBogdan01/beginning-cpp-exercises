#include "CurveBall.hpp"
#include <exception>
#include <functional>
#include <iostream>
#include <print>
#include <random>
#include <stdexcept>
#include <string>
auto createUniformPseudoRandomNumberGenerator(uint32_t min, uint32_t max)

{
    std::random_device seeder; // True random number generator to obtain a seed (slow)

    std::default_random_engine generator{seeder()}; // Efficient pseudo-random generator

    std::uniform_int_distribution distribution{min, max}; // Generate in [1, max) interval

    return std::bind(distribution, generator); //... and in the darkness bind them!
}
int readEvenNumber() {
    int n;
    std::cin >> n;

    auto rng = createUniformPseudoRandomNumberGenerator(1, 100);
    if (rng() <= 25) {
        throw CurveBall{};
    }
    if (std::cin.fail()) {
        std::cin.clear();
        std::string input;
        std::getline(std::cin, input);
        throw NotANumber{input};
    }
    if (n < 0) {
        throw NegativeNumber{std::to_string(n)};
    }
    if (n % 2 == 1) {
        throw OddNumber{std::to_string(n)};
    }

    return n;
}
void askEvenNumber() {
    std::println("Please input number");
    int n;
    while (true) {
        bool can_stop = true;
        try {
            n = readEvenNumber();

        } catch (std::domain_error& exception) {
            std::println("{}", exception.what());
            NotANumber* nan = dynamic_cast<NotANumber*>(&exception);

            if (nan != nullptr) {
                return;
            }
            can_stop = false;

        } catch (...) {
            throw;
        }
        if (can_stop) {
            break;
        }
    }

    std::println("Thanks for inputing {}", n);
}
int main() {
    try {
        askEvenNumber();
    } catch (const CurveBall& ball) {
        std::println("..hit it out in the park", ball.what());
    }
}
