#include "integer.hpp"

#include <print>
int main() {
    hm::Integer array[3] = {};
    {
        hm::Integer::print_count();
        auto dummy_1{hm::Integer{5}};
        const hm::Integer& integer_const = array[2];

        // can only access getter and print
        hm::Integer::print_count();
        auto dummy_2{integer_const};
        // cannot access member var
        array[0].set_dummy(2);
        array[0].print_value();
        integer_const.print_value();
        auto dummy = integer_const.get_dummy();
        hm::Integer::print_count();
    }
    hm::Integer::print_count();

    std::println("Comparison result is {}", array[0].compare(array[1]));
}
