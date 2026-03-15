#pragma once
#include <algorithm>
#include <compare>
#include <format>
#include <iomanip>
#include <istream>
#include <string>

class Box {
  public:
    // Constructors
    Box() = default;
    Box(double l, double w, double h) : m_length{l}, m_width{w}, m_height{h} {}

    double volume() const {
        return m_length * m_width * m_height;
    }

    // Accessors
    double getLength() const {
        return m_length;
    }
    double getWidth() const {
        return m_width;
    }
    double getHeight() const {
        return m_height;
    }

    std::partial_ordering operator<=>(const Box& otherBox) const {
        return volume() <=> otherBox.volume();
    }
    std::partial_ordering operator<=>(double otherVolume) const {
        return volume() <=> otherVolume;
    }

    bool operator==(const Box& otherBox) const = default;
    friend std::istream& operator>>(std::istream& stream, Box& box);

  private:
    double m_length{1.0};
    double m_width{1.0};
    double m_height{1.0};
};

std::ostream& operator<<(std::ostream& stream, const Box& box) {
    stream << std::setprecision(1) << std::fixed; // Same as .1f format specifier
    stream << "Box(" << box.getLength() << ", " << box.getWidth() << ", " << box.getHeight() << ')';
    return stream;
}
std::istream& operator>>(std::istream& stream, Box& box) {
    stream >> box.m_length >> box.m_width >> box.m_height;
    return stream;
}
std::string to_string(const Box& box) {
    return std::format("Box({:.1f}, {:.1f}, {:.1f})", box.getLength(), box.getWidth(),
                       box.getHeight());
}
