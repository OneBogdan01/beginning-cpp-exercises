#pragma once
#include <stdexcept>
#include <string>
#include <ostream>

template <typename First, typename Second>
class Pair {
  public:
    // cannot have deduced types via the initializer list, because we use 2 types, but it works by
    // default
    Pair() : m_first(), m_second() {}
    Pair(const First& first, const Second& second) : m_first(first), m_second(second) {}
    First getFirst() {
        return m_first;
    }
    Second getSecond() {
        return m_second;
    }
    void setFirst(const First& first) {
        m_first = first;
    }
    void setSecond(const Second& second) {
        m_second = second;
    }
    auto operator<=>(const Pair&) const = default;

  private:
    First m_first;
    Second m_second;
};

template <typename First, typename Second>
std::ostream& operator<<(std::ostream& stream, const Pair<First, Second>& pair) {
    stream << pair.getFirst() << pair.getSecond();
    return stream;
}
