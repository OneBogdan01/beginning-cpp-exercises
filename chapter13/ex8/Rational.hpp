#pragma once
#include <compare>
#include <ostream>
class Rational {
  public:
    // Constructors
    Rational(int upper = 0, int lower = 1) : m_upper(upper), m_lower(lower) {}
    double fraction() const {
        return (double) m_upper / (double) m_lower;
    }

    explicit operator float() const {
        return fraction();
    }
    explicit operator double() const {
        return fraction();
    }
    auto operator<=>(double otherVolume) const {
        return static_cast<double>(*this) <=> otherVolume;
    }
    auto operator<=>(const Rational& rational) const {
        return rational.m_lower * m_upper <=> m_lower * rational.m_upper;
    }
    bool operator==(double value) const {
        return (double) *this == value;
    }

    bool operator==(const Rational& rational) const {
        return rational.m_lower * m_upper == m_lower * rational.m_upper;
    }
    Rational operator-() {
        return Rational{-m_upper, m_lower};
    }
    const Rational& operator+=(const Rational& rational) {
        m_upper = m_upper * rational.m_lower + rational.m_upper * m_lower;
        m_lower *= rational.m_lower;
        return *this;
    }
    Rational operator+(const Rational& rational) {
        Rational copy{*this};
        copy += rational;

        return copy;
    }
    const Rational& operator-=(const Rational& rational) {
        m_upper = m_upper * rational.m_lower - rational.m_upper * m_lower;
        m_lower *= rational.m_lower;
        return *this;
    }
    Rational operator-(const Rational& rational) {
        Rational copy{*this};
        copy -= rational;

        return copy;
    }
    const Rational& operator*=(const Rational& rational) {
        m_upper *= rational.m_upper;
        m_lower *= rational.m_lower;
        return *this;
    }
    Rational operator*(const Rational& rational) {
        Rational copy{*this};
        copy *= rational;

        return copy;
    }

    const Rational& operator/=(const Rational& rational) {
        m_upper *= rational.m_lower;
        m_lower *= rational.m_upper;
        return *this;
    }
    Rational operator/(const Rational& rational) {
        Rational copy{*this};
        copy /= rational;

        return copy;
    }
    int get_upper() const {
        return m_upper;
    }
    int get_lower() const {
        return m_lower;
    }
    Rational& operator++() {
        m_upper += m_lower;
        return *this;
    }
    const Rational operator++(int) {
        Rational copy{*this};
        ++(*this);
        return copy;
    }
    Rational& operator--() {
        m_upper -= m_lower;
        return *this;
    }
    const Rational operator--(int) {
        Rational copy{*this};
        --(*this);
        return copy;
    }

  private:
    int m_upper{0};
    int m_lower{1};
};
std::ostream& operator<<(std::ostream& stream, const Rational& rational) {
    stream << rational.get_upper() << " " << rational.get_lower();
    return stream;
}

inline Rational operator+(const Rational& one, const Rational& other) {
    auto copy{one};
    return copy += other;
}
inline Rational operator-(const Rational& one, const Rational& other) {
    auto copy{one};
    return copy -= other;
}
inline Rational operator*(const Rational& one, const Rational& other) {
    auto copy{one};
    return copy *= other;
}
inline Rational operator/(const Rational& one, const Rational& other) {
    auto copy{one};
    return copy /= other;
}
