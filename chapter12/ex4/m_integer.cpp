#include "integer.hpp"
#include <print>

void hm::Integer::set_dummy(int dummy) {
    m_dummy = dummy;
}

void hm::Integer::print_value() const {
    std::println("{}", m_dummy);
}
int hm::Integer::compare(const Integer& integer) const {
    if (integer.m_dummy > m_dummy) {
        return -1;
    }
    if (integer.m_dummy == m_dummy) {
        return 0;
    }
    return 1;
}
