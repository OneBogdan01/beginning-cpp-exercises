#include "integer.hpp"

#include <print>

int main() {
    constexpr int dummy{
        hm::Integer{4}.multiply(5).add(6).multiply(5).add(7).multiply(5).add(8).get_dummy()};
    std::println("{}", dummy);
}
