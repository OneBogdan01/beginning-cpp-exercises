#include "integer.hpp"
#include <print>

hm::Integer::Integer(int dummy) : m_dummy(dummy) {
    std::println("ctor");
}
hm::Integer::Integer(const Integer& integer) : m_dummy(integer.m_dummy) {
    std::println("copy ctor");
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
int hm::Integer::compare(const Integer& integer) const {
    if (integer.m_dummy > m_dummy) {
        return -1;
    }
    if (integer.m_dummy == m_dummy) {
        return 0;
    }
    return 1;
}
hm::Integer& hm::Integer::add(const Integer& integer) {
    m_dummy += integer.m_dummy;
    return *this;
}
hm::Integer& hm::Integer::subtract(const Integer& integer) {
    m_dummy -= integer.m_dummy;
    return *this;
}
hm::Integer& hm::Integer::multiply(const Integer& integer) {
    m_dummy *= integer.m_dummy;
    return *this;
}

