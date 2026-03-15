
// Using the addition operator for Box objects

#include "Box.hpp"
#include <functional>
#include <print>
#include <random>

// See Chapter 12 for an explanation of this function

auto createUniformPseudoRandomNumberGenerator(double max)

{
    std::random_device seeder; // True random number generator to obtain a seed (slow)

    std::default_random_engine generator{seeder()}; // Efficient pseudo-random generator

    std::uniform_real_distribution distribution{1.0, max}; // Generate in [1, max) interval

    return std::bind(distribution, generator); //... and in the darkness bind them!
}

int main() {
    // taken from their repo to test my own implementation
    Box box{2, 3, 4};

    std::println("Box is {}", to_string(box));

    std::size_t n{3};

    box *= 3;

    std::println("After multiplying by {} box is {}", n, to_string(box));

    box /= 3;

    std::println("After dividing by {}, box is again {}", n, to_string(box));

    Box newBox{2 * box};

    std::println("Twice {} is {}", to_string(box), to_string(newBox));

    std::println("Half that is again {}", to_string(newBox / 2));

    std::println("Adding both boxes gives {}", to_string(box + newBox));

    box += newBox;

    std::println("The same can be obtained by usign += as well: {}", to_string(box));
}
