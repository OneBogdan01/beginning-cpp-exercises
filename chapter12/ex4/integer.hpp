#pragma once
namespace hm {
class Integer {
  public:
    constexpr Integer(int dummy = 0) : m_dummy(dummy) {}

    constexpr int get_dummy() const;
    void set_dummy(int dummy);
    void print_value() const;
    int compare(const Integer& integer) const;

    constexpr Integer& add(const Integer& integer);
    constexpr Integer& subtract(const Integer& integer);
    constexpr Integer& multiply(const Integer& integer);

  private:
    int m_dummy;
};
constexpr hm::Integer& hm::Integer::add(const Integer& integer) {
    m_dummy += integer.m_dummy;
    return *this;
}
constexpr hm::Integer& hm::Integer::subtract(const Integer& integer) {
    m_dummy -= integer.m_dummy;
    return *this;
}
constexpr hm::Integer& hm::Integer::multiply(const Integer& integer) {
    m_dummy *= integer.m_dummy;
    return *this;
}
constexpr int hm::Integer::get_dummy() const {
    return m_dummy;
}
} // namespace hm
