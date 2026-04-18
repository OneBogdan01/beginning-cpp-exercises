// Using nested classes

#include "truckload.hpp"

#include <exception>
#include <print>

// See Chapter 12 for an explanation of this function

auto createUniformPseudoRandomNumberGenerator(double max)

{
    std::random_device seeder; // True random number generator to obtain a seed (slow)

    std::default_random_engine generator{seeder()}; // Efficient pseudo-random generator

    std::uniform_real_distribution distribution{1.0, max}; // Generate in [1, max) interval

    return std::bind(distribution, generator); //... and in the darkness bind them!
}

int main()

{
    const double limit{99.0}; // Upper limit on Box dimensions

    auto random{createUniformPseudoRandomNumberGenerator(limit)};

    Truckload load;

    const std::size_t boxCount{20}; // Number of Box object to be created

    // Create boxCount Box objects

    for (std::size_t i{}; i < boxCount; ++i)

        load.addBox(std::make_shared<Box>(random(), random(), random()));

    Truckload truck1{load};

    auto& element = load[0];
    std::println("{}", to_string(*element));

    try {
        auto& exception = load[-1];
    } catch (const std::exception& ex) {
        std::println("Avoid crash out of bounds {}", ex.what());
    }
    std::println("{}", to_string(*element));
    Truckload truck2{std::move(truck1)};

    truck1 = std::move(load);
}
