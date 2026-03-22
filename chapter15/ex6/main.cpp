#include "Shapes.hpp"
#include <print>
#include <vector>

void print_shapes_values(std::vector<Shape*>& shapes) {
    double area = 0.0;
    double perimeter = 0.0;

    for (const auto& shape : shapes) {
        area += shape->area();
        perimeter += shape->perimeter();
    }
    std::println("Area is {}", area);
    std::println("Perimeter is {}", perimeter);
}
int main() {
    // example from the book
    Circle c1{Point{1, 1}, 1};

    Circle c2{Point{2, 2}, 2};

    Circle c3{Point{3, 3}, 3};

    Rectangle r1{
        {4, 5},
        4,
        5}; // Shorter notation (omitted Point type) could of course be used for Circles as well!

    Rectangle r2{{6, 7}, 6, 7};

    Rectangle r3{{8, 9}, 8, 9};
    std::vector<Shape*> shapes{&c1, &c2, &c3, &r1, &r2, &r3};

    print_shapes_values(shapes);
    for (auto& shape : shapes) {
        shape->scale(1.5);
    }
    print_shapes_values(shapes);
}
