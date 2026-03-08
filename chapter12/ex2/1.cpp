#include "integer.hpp"

#include <print>

int main() {
    hm::Integer array[3] = {};
    const hm::Integer& integer_const = array[2];
    // can only access getter and print
    auto dummy = integer_const.get_dummy();
    integer_const.print_value();
    // cannot access member var
    array[0].set_dummy(2);
    array[0].print_value();
    array[1].print_value();

    std::println("Comparison result is {}", array[0].compare(array[1]));
}
