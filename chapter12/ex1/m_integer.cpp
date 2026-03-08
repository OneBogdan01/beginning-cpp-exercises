#include "integer.hpp"
#include <print>
hm::Integer::Integer() : m_dummy(0) {
    std::println("ctor");
}
int hm::Integer::get_dummy() const {
    return m_dummy;
}
void hm::Integer::set_dummy(int dummy) {
    m_dummy = dummy;
}

void hm::Integer::print_value() const {
    std::println("{}", m_dummy);
}
