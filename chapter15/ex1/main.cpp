#include "Animal.hpp"
#include <cstdint>
#include <functional>
#include <iostream>
#include <memory>
#include <random>

auto create_rng(uint16_t min, uint16_t max) {
    std::random_device dv;
    std::default_random_engine gen{dv()};
    std::uniform_int_distribution dist{min, max};
    return std::bind(dist, gen);
}

int main() {
    size_t number_animals;
    std::cin >> number_animals;
    Zoo zoo;
    for (int i = 0; i < number_animals; i++) {
        auto random_animal_type{create_rng(0, 2)};

        auto random_cow{create_rng(50, 200)};

        auto random_dog{create_rng(10, 20)};

        auto random_sheep{create_rng(20, 50)};

        switch (random_animal_type()) {
        case 0: {
            auto cow = std::make_shared<Cow>("cow", random_cow());

            zoo.animals.push_back(cow);
            break;
        }
        case 1: {
            auto dog = std::make_shared<Dog>("dog", random_dog());

            zoo.animals.push_back(dog);

            break;
        }
        case 2: {
            zoo.animals.push_back(std::make_shared<Sheep>(Sheep{"sheep", random_sheep()}));

            break;
        }
        }
    }
    zoo.print_all_animals();
}
