
// Using the addition operator for Box objects

#include "Box.hpp"
#include <functional>
#include <print>
#include <random>
void testBox(const Box& box)

{
    std::println("The box's volume is {}.", box.volume());

    if (box)

        std::println("This volume is non-zero.");

    if (!box)

        std::println("This volume is zero.");
}

int main()

{
    Box box1{2, 3, 4};

    std::println("box1 is {}", to_string(box1));

    testBox(box1);

    std::println("");

    Box box2{0, 0, 0};

    std::println("box2 is {}", to_string(box2));

    testBox(box2);
}
