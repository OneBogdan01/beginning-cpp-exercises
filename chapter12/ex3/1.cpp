#include "integer.hpp"

#include <print>

int main() {
    hm::Integer result{4};
    hm::Integer five{5};
    hm::Integer six{6};
    hm::Integer seven{7};
    hm::Integer eight{8};
    result.multiply(five)
        .multiply(five)
        .multiply(five)
        .add(six.multiply({5}).multiply({5}))
        .add(seven.multiply({5}))
        .add(eight)
        .print_value();
}
