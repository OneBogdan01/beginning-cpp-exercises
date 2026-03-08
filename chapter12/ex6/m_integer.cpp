#include "integer.hpp"
#include <print>

hm::Integer::Integer(int dummy) : m_dummy(dummy) {
    std::println("ctor");
    s_count++;
}
hm::Integer::~Integer() {
    s_count--;
}
hm::Integer::Integer(const Integer& integer) : Integer(integer.m_dummy) {
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
void hm::Integer::print_count() {
    std::println("Instances alive {}", s_count);
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

// int hm::Integer::compare(Integer integer) const {
//     if (integer.m_dummy > m_dummy) {
//         return -1;
//     }
//     if (integer.m_dummy == m_dummy) {
//         return 0;
//     }
//     return 1;
// }
