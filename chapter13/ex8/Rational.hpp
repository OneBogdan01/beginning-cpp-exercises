#pragma once
#include <algorithm>
#include <compare>
#include <format>
#include <iomanip>
#include <istream>
#include <string>
class Rational {
  public:
    // Constructors
    Rational(int upper, int lower) : m_upper(upper), m_lower(lower) {}
    double fraction() {
        return (double) m_upper / (double) m_lower;
    }
    std::partial_ordering operator<=>(const Rational& rational) const {
        return volume() <=> otherBox.volume();
    }
    std::partial_ordering operator<=>(double otherVolume) const {
        return volume() <=> otherVolume;
    }
    // even with explicit, it can still be used as if(box)
    explicit operator bool() const {
        return volume() == 0;
    }
    bool operator==(const Box& otherBox) const = default;

  private:
    int m_upper{0};
    int m_lower{1};
};
std::ofstream& operator<<(ofstream& stream,)
